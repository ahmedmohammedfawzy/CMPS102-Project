#include "LoadGraph.h"
#include "SaveGraph.h"
#include "ApplicationManager.h"
#include "input.h"
#include "Output.h"
#include "iostream"
#include <fstream>
#include "Ccircle.h"
#include "CSquare.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CHexagon.h"

LoadGraph::LoadGraph(ApplicationManager* pApp) : Action(pApp)
{
}

void LoadGraph::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the FileName:");
	FileName = pIn->GetString(pOut);
}

void LoadGraph::Execute()
{
	ReadActionParameters();
	ifstream inputFile(FileName);
	string name;
	if (inputFile.is_open()) {
		while (!inputFile.eof())
		{
			GfxInfo gfxinfo;
			gfxinfo.isFilled = false;

			gfxinfo.DrawClr = pManager->GetOutput()->getCrntDrawColor();
			gfxinfo.FillClr = pManager->GetOutput()->getCrntFillColor();
			CFigure* newFig = nullptr;
			string type;
			inputFile >> type;
			if (type == "Rectangle")
				newFig = new CRectangle({ 0,0 }, { 0,0 }, gfxinfo);
			else if (type == "Square")
				newFig = new CSquare({ 0,0 },gfxinfo);
			else if (type == "Circle")
				newFig = new CCircle({ 0,0 },0,gfxinfo);
			else if (type == "Hexagon")
				newFig = new CHexagon({ 0,0 },gfxinfo);
			else if (type == "Triangle")
				newFig = new CTriangle({ 0,0 }, { 0,0 }, { 0,0 }, gfxinfo);

			if (newFig)
			{
				newFig->Load(inputFile);
				pManager->AddFigure(newFig); // Assuming you already have this function
			}
		}
		inputFile.close();
	}
	else {
		pManager->GetOutput()->PrintMessage("Failed to open the file.");
	}

	return;
};

