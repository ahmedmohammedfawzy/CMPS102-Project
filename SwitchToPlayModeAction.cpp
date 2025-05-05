#include "SwitchToPlayModeAction.h"
#include "ApplicationManager.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToPlayModeAction::ReadActionParameters()
{
}

void SwitchToPlayModeAction::Execute()
{
	pManager->GetOutput()->CreatePlayToolBar();

}
