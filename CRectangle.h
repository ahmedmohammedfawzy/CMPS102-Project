#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	bool IsPointInsideFig(int x, int y) override;
	void Draw(Output* pOut) const override;
	void Rotate(bool IsClock) override;
	bool CanRotate() override;
	void MoveTo(Point newCenter) override;
	Point GetCenter() override;
	string SaveInfo() override;
};

#endif