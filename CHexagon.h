#pragma once
#include "CFigure.h"
class CHexagon : public CFigure
{
private:
	Point Center;
	Point Vertices[6];
public:
	CHexagon(Point, GfxInfo hexagonGfxInfo);
	bool IsPointInsideFig(int x, int y) override;
	void Draw(Output* pOut) const override;
};

