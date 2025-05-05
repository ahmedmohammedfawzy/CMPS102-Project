#pragma once
#include "CFigure.h"
class CHexagon : public CFigure
{
private:
	Point Center;
	Point Vertices[6];

	void CalculateVertices();
public:
	CHexagon(Point, GfxInfo hexagonGfxInfo);
	bool IsPointInsideFig(int x, int y) override;
	void Draw(Output* pOut) const override;
	void Rotate(bool IsClock) override;
	bool CanRotate() override;
	void MoveTo(Point newCenter) override;
	Point GetCenter() override;
	string SaveInfo() override;
};

