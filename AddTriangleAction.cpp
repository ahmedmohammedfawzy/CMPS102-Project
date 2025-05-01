#include "AddTriangleAction.h"
#include "CTriangle.h"

#include "ApplicationManager.h"

#include "input.h"
#include "Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp): Action(pApp)
{
}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddTriangleAction::Execute()
{
	ReadActionParameters();

	CTriangle* tr = new CTriangle(P1, P2, P3, TriGfxInfo);

	pManager->AddFigure(tr);
}
