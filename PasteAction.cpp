#include "PasteAction.h"
#include "ApplicationManager.h"

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Paste: Click on a point to use as center");

	pIn->GetPointClicked(P.x, P.y);

	pOut->ClearStatusBar();
}

void PasteAction::Execute()
{
	ReadActionParameters();

	pManager->PasteFromClipboard(P);
}
