#include "ApplicationManager.h"
#include "AddRectAction.h"
#include "AddSquareAction.h"
#include "AddCircleAction.h"
#include "AddTriangleAction.h"
#include "SelectAction.h"
#include "RotateAction.h"
#include "AddHexagonAction.h"
#include "CopyAction.h"
#include "DeleteAction.h"
#include "SwapAction.h"
#include "SwitchToPlayModeAction.h"
#include "SwitchToDrawAction.h"
#include "MatchingPairsAction.h"
#include "CutAction.h"
#include "PasteAction.h"
#include "ExitAction.h"
#include "ClearAllAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	SelectedFigsCount = 0;
	Score = 0;
	Clipboard = nullptr;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_SQUA:
			pAct = new AddSquareAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			break;		
		
		case DRAW_TRI:
			pAct = new AddTriangleAction(this);
			break;		
		case DRAW_HEX:
			pAct = new AddHexagonAction(this);
			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;

		case ROTATE:
			pAct = new RotateAction(this);
			break;

		case SWAP:
			pAct = new SwapAction(this);
			break;

		case COPY:
			pAct = new CopyAction(this);
			break;

		case PLAY_MISSING_PAIRS:
			pAct = new MatchingPairsAction(this);
			break;
	

		case DEL:
			pAct = new DeleteAction(this);
			break;

		case CUT:
			pAct = new CutAction(this);
			break;

		case PASTE:
			pAct = new PasteAction(this);
			break;

		case TO_PLAY:
			pAct = new SwitchToPlayModeAction(this);
			break;

		case TO_DRAW:
			pAct = new SwitchToDrawAction(this);
			break;

		case CLEAR:
			pAct = new ClearAllAction(this);
			break;

		case EXIT:
			pAct = new ExitAction(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	CFigure* pFig = nullptr;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsPointInsideFig(x,y))
		{
			pFig = FigList[i];
		}
	}
	return pFig;
}
void ApplicationManager::SelectFigure(CFigure* pFig)
{
	SelectedFigs[SelectedFigsCount] = pFig;
	SelectedFigsCount++;
	pFig->SetSelected(true);
}
void ApplicationManager::DeselectFigure(CFigure* pFig)
{
	for (int i = 0; i < SelectedFigsCount; i++)
	{
		if (SelectedFigs[i] == pFig)
		{
			SelectedFigs[i]->SetSelected(false);
			for (int j = i; j < SelectedFigsCount - 1; j++)
			{
				SelectedFigs[j] = SelectedFigs[j + 1];
			}
			SelectedFigsCount--;
			return;
		}
	}
}
void ApplicationManager::ClearSelection()
{
	for (int i = 0; i < SelectedFigsCount; i++)
	{
		SelectedFigs[i]->SetSelected(false);
	}
	SelectedFigsCount = 0;
}

bool ApplicationManager::RotateFigure(CFigure* pFig, bool isClock)
{
	if (pFig->CanRotate()) 
	{
		pFig->Rotate(isClock);
		ClearSelection();
		return true;
	} 
	else 
	{
		return false;
	}
}
void ApplicationManager::SwapFigures(CFigure* shape1, CFigure* shape2)
{
	Point cen1 = shape1->GetCenter();
	Point cen2 = shape2->GetCenter();

	shape1->MoveTo(cen2);
	shape2->MoveTo(cen1);
	ClearSelection();
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();

	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)

	pOut->RedrawToolBar();
}

int ApplicationManager::GetSelectedFigsCount() const
{
	return SelectedFigsCount;
}

CFigure** ApplicationManager::GetSelectedFigs()
{
	return SelectedFigs;
}

void ApplicationManager::MoveSelectedToClipboard(bool isCut)
{
	if (Clipboard != nullptr)
	{
		Clipboard->setGreyColor(false);

		if (isClipboardCut)
			delete Clipboard;
	}

	isClipboardCut = isCut;
	Clipboard = SelectedFigs[0];
	DeselectFigure(Clipboard);
	Clipboard->setGreyColor(isCut);
}


void ApplicationManager::PasteFromClipboard(Point newCent)
{
	CFigure* newfig = Clipboard->Clone();
	newfig->MoveTo(newCent);
	AddFigure(newfig);

	if (isClipboardCut) 
	{
		newfig->setGreyColor(false);
		deleteFigure(Clipboard, false);
	}
}

void ApplicationManager::ClearAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		deleteFigure(FigList[i], true);
	}
	FigCount = 0;
	ClearSelection();
	Clipboard = nullptr;
	isClipboardCut = false;
}

void ApplicationManager::deleteFigure(CFigure *ptr, bool deAllocate)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == ptr) {
			FigList[i] = NULL;
			for (int j = i; j < FigCount - 1 ; j++)
			{
				FigList[j] = FigList[j + 1];
			}
			FigCount--;
		}
	}

	for (int i = 0; i < SelectedFigsCount; i++)
	{
		if (SelectedFigs[i] == ptr) {
			SelectedFigs[i] = NULL;
			for (int j = i; j < SelectedFigsCount - 1; j++)
			{
				SelectedFigs[j] = SelectedFigs[j + 1];
			}
			SelectedFigsCount--;
		}
	}
	if (deAllocate)
		delete ptr;
}
void ApplicationManager::deleteSelectedFigs()
{
	for (int i = 0; i < SelectedFigsCount; i++)
	{
		deleteFigure(SelectedFigs[i], true);
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
