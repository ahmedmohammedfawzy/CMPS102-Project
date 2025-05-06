#pragma once
#include "CFigure.h"

class CTriangle: public CFigure
{
private:
	Point P1,P2,P3;

public:
	CTriangle(Point, Point, Point, GfxInfo);
	bool IsPointInsideFig(int x, int y) override;
	void Draw(Output* pOut) const override;
	void Rotate(bool IsClock) override;
	bool CanRotate() override;
	void MoveTo(Point newCenter) override;
	Point GetCenter() override;
	string SaveInfo() override;
	void Load(ifstream& file) override;
};

