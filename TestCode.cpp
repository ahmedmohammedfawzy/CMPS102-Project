#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x, y;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2,P3;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("Drawing a square ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->Drawsqre(P1, P2, gfxInfo, false);

	pOut->PrintMessage("Drawing a square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->Drawsqre(P1, P2, gfxInfo, true);

	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("Drawing a square ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->Drawsqre(P1, P2, gfxInfo, false);

	pOut->PrintMessage("Drawing a square ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->Drawsqre(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();
	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	pOut->PrintMessage("Drawing a Triangle ==> non-filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawTri(P1, P2, P3 ,gfxInfo, false);

	pOut->PrintMessage("Drawing a Triangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTri(P1, P2,P3, gfxInfo, true);

	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	pOut->PrintMessage("Drawing a Triangle ==> filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawTri(P1, P2, P3 , gfxInfo , false); 

	pOut->PrintMessage("Drawing a Triangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTri(P1, P2,P3, gfxInfo, true);



	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Hexagon in all possible states

	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("Drawing a Circle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawCircle(P1, P2, gfxInfo, false);

	pOut->PrintMessage("Drawing a Circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCircle(P1, P2, gfxInfo, true);

	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	pOut->PrintMessage("Drawing a Circle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawCircle(P1, P2, gfxInfo, false);

	pOut->PrintMessage("Drawing a Circle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCircle(P1, P2, gfxInfo, true);

	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings");
	string str = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	pOut->PrintMessage("You Entered : " + str);

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_RECT:
			pOut->PrintMessage("Action: Draw a Rectangle, Click anywhere");
			break;

		case DRAW_SQUA:
			pOut->PrintMessage("Action: Draw a Square, Click anywhere");
			break;

		case DRAW_TRI:
			pOut->PrintMessage("Action: Draw a Triangle, Click anywhere");
			break;

		case DRAW_CIRC:
			pOut->PrintMessage("Action: Draw a Circle, Click anywhere");
			break;

		case DRAW_HEX:
			pOut->PrintMessage("Action: Draw a Hexagon, Click anywhere");
			break;

		case SELECT:
			pOut->PrintMessage("Action: Select a shape");
			break;

		case SWAP:
			pOut->PrintMessage("Action: Swap two shapes");
			break;

		case ROTATE:
			pOut->PrintMessage("Action: Rotate a shape");
			break;

		case DEL:
			pOut->PrintMessage("Action: Delete a shape");
			break;

		case CLEAR:
			pOut->PrintMessage("Action: Clear all shapes");
			break;

		case COPY:
			pOut->PrintMessage("Action: Copy a shape");
			break;

		case CUT:
			pOut->PrintMessage("Action: Cut a shape");
			break;

		case PASTE:
			pOut->PrintMessage("Action: Paste a shape");
			break;

		case SAVE_GRAPH:
			pOut->PrintMessage("Action: Save the graph to file");
			break;

		case LOAD_GRAPH:
			pOut->PrintMessage("Action: Load a graph from file");
			break;

		case PLAY_MISSING_SHAPES:
			pOut->PrintMessage("Action: Play - Find missing shapes game");
			break;

		case PLAY_MISSING_PAIRS:
			pOut->PrintMessage("Action: Play - Find missing pairs game");
			break;

		case STATUS:
			pOut->PrintMessage("Action: A click on the Status Bar, Click anywhere");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: A click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: A click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, creating Design toolbar");
			pOut->ClearToolBar();
			pOut->CreateDrawToolBar();
			break;

		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Play toolbar");
			pOut->ClearToolBar();
			pOut->CreatePlayToolBar();
			break;

		case EXIT:
			// No message needed; exit condition
			break;
		}

	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


