#include "AddHexagonAction.h"
#include "CHexagon.h"

#include "ApplicationManager.h"

#include "input.h"
#include "Output.h"

AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddHexagonAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(Center.x, Center.y);

	HexagonGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexagonGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexagonGfxInfo.FillClr = PromptUserForColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexagonAction::Execute()
{
	ReadActionParameters();

	CHexagon* R = new CHexagon(Center, HexagonGfxInfo);

	pManager->AddFigure(R);
}
