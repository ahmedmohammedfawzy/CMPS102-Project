#ifndef CRECT_H
#define CRECT_H
#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
	Point Corner1;
	Point Corner2;

	void CalculateCorners();
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	bool IsPointInsideFig(int x, int y) override;
	void Draw(Output* pOut) const override;
	void Rotate(bool IsClock) override;
	bool CanRotate() override;
	void MoveTo(Point newCenter) override;
	Point GetCenter() override;
	string SaveInfo() override;
};

#endif