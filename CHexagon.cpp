#include "CHexagon.h"
#include "Helpers.h"

CHexagon::CHexagon(Point center, GfxInfo hexagonGfxInfo): CFigure(hexagonGfxInfo)
{
	Center = center;

	Vertices[0] = { HEXAGON_SIZE, 0 };
	Vertices[1] = { (HEXAGON_SIZE / 2), (int)((sqrt(3) / 2) * HEXAGON_SIZE) };
	Vertices[2] = { -(HEXAGON_SIZE / 2), (int)((sqrt(3) / 2) * HEXAGON_SIZE) };
	Vertices[3] = { -HEXAGON_SIZE, 0 };
	Vertices[4] = { -(HEXAGON_SIZE / 2), (int)(-(sqrt(3) / 2) * HEXAGON_SIZE)};
	Vertices[5] = { (HEXAGON_SIZE / 2), (int)(-(sqrt(3) / 2) * HEXAGON_SIZE)};

	for (int i = 0; i < 6; i++)
	{
		Vertices[i].x += center.x;
		Vertices[i].y += center.y;
	}
}
bool CHexagon::IsPointInsideFig(int x, int y)
{
	for (int i = 0; i < 6; i++)
	{
		Point p1 = Vertices[i];
		Point p2 = Vertices[(i + 1) % 6];

		if (isInsideTriangle(p1, p2, Center, { x,y }))
			return true;
	}
	return false;
}

void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHexagon(Vertices, FigGfxInfo, Selected);
}
