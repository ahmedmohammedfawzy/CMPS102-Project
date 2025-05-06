#pragma once
#include "Action.h"

#include "SelectAction.h"
#include "ApplicationManager.h"
#include "typeinfo"
#include "input.h"
#include "Output.h"
#include "MatchingPairsAction.h"

MatchingPairsAction ::MatchingPairsAction(ApplicationManager* pApp) : Action(pApp)
{
	Score = 0;
}

void MatchingPairsAction::ReadActionParameters()
{

}

void MatchingPairsAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	while (true)
	{
		pOut->PrintMessage("Matching pairs: Click inside a shape to select it, Click outside shapes to abort.");

		pIn->GetPointClicked(P1.x, P1.y);
		CFigure* sh1 = pManager->GetFigure(P1.x, P1.y);
		if (sh1 == nullptr)
		{
			pOut->PrintMessage("Click another time to confirm");
			sh1 = pManager->GetFigure(P1.x, P1.y);
			pOut->ClearStatusBar();
			if (sh1 == nullptr)
				break;
		}
		pManager->SelectFigure(sh1);
		sh1->setGreyColor(true);
		pOut->ClearStatusBar();
		pManager->UpdateInterface();


		pOut->PrintMessage("Matching pairs: Click another one please, Click outside shapes to abort.");

		pIn->GetPointClicked(P2.x, P2.y);
		CFigure* sh2 = pManager->GetFigure(P2.x, P2.y);
		if (sh2 == nullptr)
		{
			pOut->PrintMessage("Click another time to confirm");
			sh2 = pManager->GetFigure(P2.x, P2.y);
			pOut->ClearStatusBar();
			if (sh2 == nullptr)
				break;
		}
		pManager->SelectFigure(sh2);
		sh2->setGreyColor(true);
		pOut->ClearStatusBar();
		pManager->UpdateInterface();


		if (typeid(*sh1) == typeid(*sh2) && sh1->GetFillClr() == sh2->GetFillClr())
		{
			Score += 20;
			pOut->PrintMessage(to_string(Score));
		}
		else if (typeid(*sh1) == typeid(*sh2))
		{
			Score += 10;
			pOut->PrintMessage(to_string(Score));
		}
		else if (sh1->GetFillClr() == sh2->GetFillClr())
		{
			Score += 10;
			pOut->PrintMessage(to_string(Score));
		}
		else if (typeid(*sh1) != typeid(*sh2) && sh1->GetFillClr() != sh2->GetFillClr())
		{
			Score -= 20;
			pOut->PrintMessage(to_string(Score));
		}
		else
		{
			Score -= 10;
			pOut->PrintMessage(to_string(Score));
		}
		string msg1 = "Matching pairs: Click anywhere to choose another shape, ";
		string msg2 = "Score is: " + to_string(Score);
		pManager->ClearSelection();
		pManager->UpdateInterface();
		pOut->PrintMessage(msg1 + msg2);
		pIn->GetPointClicked(P1.x, P2.y);
	}

	for (int i = 0; i < pManager->GetSelectedFigsCount(); i++)
	{
		pManager->GetSelectedFigs()[i]->setGreyColor(false);
	}
}