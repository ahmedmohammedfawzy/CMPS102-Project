#include "SwitchToDrawAction.h"
#include "ApplicationManager.h"

SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pApp): Action(pApp)
{
}

void SwitchToDrawAction::ReadActionParameters()
{
}

void SwitchToDrawAction::Execute()
{
	pManager->GetOutput()->CreateDrawToolBar();
}
