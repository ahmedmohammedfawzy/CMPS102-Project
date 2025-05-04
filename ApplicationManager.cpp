#include "ApplicationManager.h"
#include "AddRectAction.h"
#include "AddSquareAction.h"
#include "AddCircleAction.h"
#include "AddTriangleAction.h"
#include "SelectAction.h"
#include "RotateAction.h"
#include "AddHexagonAction.h"
#include "CopyAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	SelectedFigsCount = 0;
		
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

		case COPY:
			pAct = new CopyAction(this);
			break;
	

		case EXIT:
			///create ExitAction here
			
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

void ApplicationManager::MoveSelectedToClipboard()
{
	Clipboard = SelectedFigs[0];
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
