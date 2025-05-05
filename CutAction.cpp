#include "CutAction.h"
#include "ApplicationManager.h"

#include "input.h"
#include "Output.h"
CutAction::CutAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CutAction::ReadActionParameters()
{
}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->GetSelectedFigsCount() > 1)
	{
		pOut->PrintMessage("Error!!! Can't copy multiple figures. Please select only one figure.");
		return;
	}
	else if (pManager->GetSelectedFigsCount() == 0) {
		pOut->PrintMessage("Error!!! Please select one figure.");
	}
	else
	{
		pManager->MoveSelectedToClipboard();
		pManager->GetSelectedFigs()[0]->setGreyColor(true);

	}
}
