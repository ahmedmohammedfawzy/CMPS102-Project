#include "DeleteAction.h"
#include "ApplicationManager.h"

#include "input.h"
#include "Output.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
}

void DeleteAction::Execute()
{
	pManager->deleteSelectedFigs();
}
