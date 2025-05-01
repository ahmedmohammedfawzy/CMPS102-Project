#pragma once
#include "Action.h"
class AddHexagonAction : public Action
{
private:
	Point Center;
	GfxInfo HexagonGfxInfo;
public:
	AddHexagonAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

