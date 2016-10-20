#include "main.h"

std::unique_ptr<Ezreal> gpEzreal = nullptr;

Ezreal::Ezreal()
{
	pMenu = gpSDK->AddMenu("Ezreal++");
	pKillsteal = pMenu->CheckBox("Killsteal", false);

	pChildQ = pMenu->AddMenu("Q");
	pAutoQ = pChildQ->CheckBox("Use in Combo", false);
	pAutoQHarass = pChildQ->CheckBox("Auto Harass", false);
	pAutoQHarassMinMana = pChildQ->AddInteger("Min. Mana % to Auto Harass", 1, 100, 50);

	pChildW = pMenu->AddMenu("W");
	pAutoW = pChildW->CheckBox("Use in Combo", false);

	pChildR = pMenu->AddMenu("R");
	pAutoR = pChildR->CheckBox("Use to Killsteal", false);
	pAutoRMinRange = pChildR->AddInteger("Min. Range to Killsteal", 125, 1500, 800);
	pAutoRMaxRange = pChildR->AddInteger("Max. Range to Killsteal", 550, 2500, 1500);

	pQ = gpSDK->CreateSpell2(kSlotQ, kLineCast, true, false, static_cast<eCollisionFlags>(kCollidesWithMinions | kCollidesWithYasuoWall));
	pW = gpSDK->CreateSpell2(kSlotW, kLineCast, true, false, static_cast<eCollisionFlags>(kCollidesWithYasuoWall));
	pE = gpSDK->CreateSpell2(kSlotE, kTargetCast, false, false, static_cast<eCollisionFlags>(kCollidesWithNothing));
	pR = gpSDK->CreateSpell2(kSlotR, kLineCast, true, false, static_cast<eCollisionFlags>(kCollidesWithYasuoWall));
}

Ezreal::~Ezreal()
{
	pChildQ->Remove();
	pChildW->Remove();
	pMenu->Remove();
}

void Ezreal::OnRender()
{
	if (gpEntityList->Player() == nullptr)
		return;
}

void Ezreal::OnUpdate()
{
	if (gpEntityList->Player() == nullptr)
		return;

	if (pKillsteal->Enabled())
	{
		RunKillsteal(gpEntityList->Player());
	}

	if (pAutoQHarass->Enabled() && gpEntityList->Player()->ManaPercent() >= static_cast<float>(pAutoQHarassMinMana->GetInteger()))
	{
		// find the best target in Q range
		IUnit* pTarget = gpTargetSelector->FindTarget(QuickestKill, TrueDamage, pQ->Range() - 50.f);

		if (pTarget != nullptr && !pTarget->IsDead() && pQ->IsReady() && gpEntityList->Player()->IsValidTarget(pTarget, pQ->Range()))
		{
			pQ->CastOnTarget(pTarget, kHitChanceHigh);
		}
	}

	if (gpOrbwalker->GetOrbwalkingMode() == kModeCombo)
	{
		IUnit* pTarget = gpTargetSelector->FindTarget(QuickestKill, TrueDamage, pQ->Range());

		if (pTarget != nullptr && !pTarget->IsDead() && pTarget->IsHero() && pTarget->IsEnemy(gpEntityList->Player()))
		{
			RunCombo(gpEntityList->Player(), pTarget);
		}
	}
}

void Ezreal::RunKillsteal(IUnit* pLocal)
{
	for (auto hero : gpEntityList->GetAllHeros(false, true))
	{
		if (pQ->IsReady() && pLocal->IsValidTarget(hero, pQ->Range()))
		{
			float dmg = gpHealthPrediction->GetKSDamage(hero, kSlotQ, 0.25f, true);

			if (dmg > hero->GetHealth())
			{
				pQ->CastOnTarget(hero, kHitChanceHigh);
			}
		}

		if (pW->IsReady() && pLocal->IsValidTarget(hero, pW->Range()))
		{
			float dmg = gpHealthPrediction->GetKSDamage(hero, kSlotW, 0.25f, true);

			if (dmg > hero->GetHealth())
			{
				pW->CastOnTarget(hero, kHitChanceHigh);
			}
		}

		if (pR->IsReady() && pLocal->IsValidTarget(hero, static_cast<float>(pAutoRMaxRange->GetInteger())))
		{
			float distance = (pLocal->GetPosition() - hero->GetPosition()).GetLength3D();

			if (distance > static_cast<float>(pAutoRMinRange->GetInteger()))
			{
				float dmg = gpHealthPrediction->GetKSDamage(hero, kSlotR, 1.1f, true);

				if (dmg > hero->GetHealth())
				{
					pR->CastOnTarget(hero, kHitChanceHigh);
				}
			}
		}
	}
}

void Ezreal::RunCombo(IUnit* pLocal, IUnit* pTarget)
{
	if (pAutoQ->Enabled() && pQ->IsReady() && pLocal->IsValidTarget(pTarget, pQ->Range() - 50.f))
	{
		pQ->CastOnTarget(pTarget, kHitChanceHigh);
	}

	if (pAutoW->Enabled() && pW->IsReady() && pLocal->IsValidTarget(pTarget, pW->Range()))
	{
		pW->CastOnTarget(pTarget, kHitChanceHigh);
	}
}