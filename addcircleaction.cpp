#include "AddCircleAction.h"
#include "CCircle.h"
#include "ApplicationManager.h"

#include "input.h"
#include "Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp): Action(pApp)
{
}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the center");

	pIn->GetPointClicked(Center.x, Center.y);

	pOut->PrintMessage("New Circle: Click at another point");

	pIn->GetPointClicked(P2.x, P2.y);

	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CCircle* R = new CCircle(Center, Center.GetDistance(P2), CircleGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
