#pragma once
#include "Action.h"
#include "SaveGraph.h"

#include "ApplicationManager.h"
#include "input.h"
#include "Output.h"
#include "iostream"
#include <fstream>

class LoadGraph : public Action
{
	string FileName;
public:
	LoadGraph(ApplicationManager* pApp);
	void ReadActionParameters() override;
	void Execute() override;
};


