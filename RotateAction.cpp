#include "RotateAction.h"
#include "ApplicationManager.h"

#include "input.h"
#include "Output.h"

RotateAction::RotateAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RotateAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Rotate: Write (c) to rotate clockwise, (a) to rotate anti-clockwise");
	string input = pIn->GetString(pOut);

	if (input == "c") 
	{
		IsClock = true;
	} 
	else 
	{
		IsClock = false;
	}

	pOut->ClearStatusBar();
}

void RotateAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();

	if(pManager->GetSelectedFigsCount() == 1)
	{
		bool status = pManager->RotateFigure(pManager->GetSelectedFigs()[0], IsClock);

		if (status == false) 
		{
			pOut->PrintMessage("Error: Can not rotate squares and circles");
		}
	} 
	else 
	{
		pOut->PrintMessage("Error: Can rotate only a single figure.");
	}

}
