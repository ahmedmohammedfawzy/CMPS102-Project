#ifndef CFIGURE_H
#define CFIGURE_H

#include "defs.h"
#include "Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	bool IsGreyed;
	GfxInfo FigGfxInfo;	//Figure graphis info	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	color GetFillClr();
	virtual bool IsPointInsideFig(int x, int y) = 0;
	virtual void Rotate(bool IsClock) = 0;
	virtual bool CanRotate() = 0;
	virtual void MoveTo(Point newCenter) = 0;
	virtual Point GetCenter() = 0;
	int getID();
	void setID(int id);
	virtual string SaveInfo()=0;
	virtual void Load(ifstream& file)=0;
	virtual CFigure* Clone() = 0;

	void setGreyColor(bool isGrey);

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif