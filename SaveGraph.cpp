#include "SaveGraph.h"

#include "ApplicationManager.h"
#include "input.h"
#include "Output.h"
#include "iostream"
#include <fstream>

SaveGraph::SaveGraph(ApplicationManager* pApp) : Action(pApp)
{
}


void SaveGraph::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the FileName:");
    FileName = pIn->GetString(pOut);
};

void SaveGraph:: Execute()
{
	ReadActionParameters();
    Output* pOut = pManager->GetOutput();

	string str = pManager->SaveInfo();

    ofstream outFile(FileName);

    // Check if the file opened successfully
    if (outFile.is_open()) {
        outFile << str;
        outFile.close(); // Always close the file when done
        pOut->PrintMessage("File save successfully");
    }
    else {
        pOut->PrintMessage("Failed to open the file.");
    }

};
