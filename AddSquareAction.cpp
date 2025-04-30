#include "AddSquareAction.h"
#include "CSquare.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) : Action(pApp)
{
}

void AddSquareAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center");

	pIn->GetPointClicked(P1.x, P1.y);

	SquareGfxInfo.isFilled = false;

	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddSquareAction::Execute()
{
	ReadActionParameters();

	CSquare* S = new CSquare(P1, SquareGfxInfo);

	pManager->AddFigure(S);
}
