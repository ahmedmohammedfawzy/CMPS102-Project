#ifndef CRECT_H
#define CRECT_H
#include "CFigure.h"

class CSquare : public CFigure
{
	Point center;
	Point Corner1;
	Point Corner2;

public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	bool IsPointInsideFig(int x, int y) override;
	void Draw(Output* pOut) const override;
};

#endif