#include "SelectAction.h"
#include "ApplicationManager.h"

#include "input.h"
#include "Output.h"

SelectAction::SelectAction(ApplicationManager* pApp): Action(pApp)
{
}

void SelectAction::ReadActionParameters()
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select: Click inside a shape to select it");

	pIn->GetPointClicked(P.x, P.y);


	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	ReadActionParameters();

	CFigure* fig = pManager->GetFigure(P.x, P.y);
	if (fig == nullptr) 
	{
		pManager->ClearSelection();
		return;
	}
	
	if (fig->IsSelected() == false)
		pManager->SelectFigure(fig);
	else
		pManager->DeselectFigure(fig);
}
