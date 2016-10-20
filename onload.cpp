#include "sdk\PluginSDK.h"
#include "main.h"

PluginSetup("Ezreal++")

PLUGIN_EVENTD(void) _OnGameUpdate()
{
	gpEzreal->OnUpdate();
}

PLUGIN_EVENTD(void) _OnRender()
{
	gpEzreal->OnRender();
}

PLUGIN_API void OnLoad(IPluginSDK *sdk)
{
	PluginSDKSetup(sdk);

	if (!_stricmp(gpEntityList->Player()->ChampionName(), "ezreal"))
	{
		gpEzreal = std::make_unique<Ezreal>();

		gpEventManager->AddEventHandler(kEventOnGameUpdate, _OnGameUpdate);
		gpEventManager->AddEventHandler(kEventOnRender, _OnRender);
	}
}

PLUGIN_API void OnUnload()
{
	gpEventManager->RemoveEventHandler(kEventOnGameUpdate, _OnGameUpdate);
	gpEventManager->RemoveEventHandler(kEventOnRender, _OnRender);

	gpEzreal.reset(nullptr);
}