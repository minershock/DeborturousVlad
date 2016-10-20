#pragma once
#include "sdk\PluginSDK.h"

class Ezreal
{
public:
	Ezreal();
	~Ezreal();

	void RunKillsteal(IUnit* pLocal);
	void RunCombo(IUnit* pLocal, IUnit* pTarget);

	void OnRender();
	void OnUpdate();

private:
	IMenu *pMenu;
	IMenu *pChildQ, *pChildW, *pChildE, *pChildR;

	IMenuOption *pKillsteal, *pAutoQ, *pAutoW, *pAutoR, *pAutoQHarass;
	IMenuOption *pAutoQHarassMinMana, *pAutoRMinRange, *pAutoRMaxRange;

	ISpell2 *pQ, *pW, *pE, *pR;

	IFont *pFont;
};

extern std::unique_ptr<Ezreal> gpEzreal;