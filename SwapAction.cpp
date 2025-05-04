#include "SwapAction.h"
#include "ApplicationManager.h"

#include "input.h"
#include "Output.h"

SwapAction::SwapAction(ApplicationManager* pApp): Action(pApp)
{
}

void SwapAction::ReadActionParameters() {}

void SwapAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->GetSelectedFigsCount() == 2) 
	{
		CFigure* shape1 = pManager->GetSelectedFigs()[0];
		CFigure* shape2 = pManager->GetSelectedFigs()[1];

		pManager->SwapFigures(shape1, shape2);
	}
	else 
	{
		pOut->PrintMessage("Error: You must select exactly two shapes in order to swap");
	}
}
