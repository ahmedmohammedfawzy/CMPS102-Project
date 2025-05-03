#pragma once
#include "Action.h"
using namespace std;

class CopyAction :
    public Action
{
public:
	CopyAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

