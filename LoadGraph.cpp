#include "LoadGraph.h"
#include "SaveGraph.h"
#include "ApplicationManager.h"
#include "input.h"
#include "Output.h"
#include "iostream"
#include <fstream>

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
	ifstream inputFile("data.txt");
	string name;
	if (inputFile.is_open()) {
		while (inputFile >> name) { // Read word and number
		}
		inputFile.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}

	return;
};

