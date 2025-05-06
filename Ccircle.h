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
	void Rotate(bool IsClock) override;
	bool CanRotate() override;
	void MoveTo(Point newCenter) override;
	Point GetCenter() override;
	string SaveInfo() override;
	void Load(ifstream& file) override;
	CFigure* Clone() override;
};

