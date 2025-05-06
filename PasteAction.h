#pragma once
#include "Action.h"
class PasteAction : public Action
{
private:
	Point P;

public:
	PasteAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};