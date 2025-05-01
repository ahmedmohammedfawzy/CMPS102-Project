#pragma once
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point P2;
public:
	CCircle(Point, Point, GfxInfo circleGfxInfo);
	virtual void Draw(Output* pOut) const;
};

