#pragma once
#include "Action.h"

class SaveGraph : public Action
{
private:
	string FileName;

public:
	SaveGraph(ApplicationManager* pApp);
	void ReadActionParameters() override;
	void Execute() override;
};


