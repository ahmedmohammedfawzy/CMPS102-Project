#pragma once
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	int Radius;
public:
	CCircle(Point, int, GfxInfo circleGfxInfo);
	bool IsPointInsideFig(int x, int y) override;
	void Draw(Output* pOut) const override;
};

