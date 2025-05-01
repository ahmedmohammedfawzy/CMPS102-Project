#ifndef CRECT_H
#define CRECT_H
#include "CFigure.h"

class CSquare : public CFigure
{
	Point center;

public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	void Draw(Output* pOut) const override;
};

#endif