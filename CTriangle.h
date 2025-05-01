#pragma once
#include "CFigure.h"

class CTriangle: public CFigure
{
private:
	Point P1,P2,P3;

public:
	CTriangle(Point, Point, Point, GfxInfo);
	void Draw(Output* pOut) const override;
};

