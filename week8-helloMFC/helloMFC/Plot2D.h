#ifndef PLOT2D_H
#define PLOT2D_H

#include <cmath>
class Wave{
public:
	void draw(CDC* pDC,  double x, double y, double width, double height, double omega=1){
		HGDIOBJ oldBrush=pDC->SelectObject (GetStockObject(DC_BRUSH));
		HGDIOBJ oldPen  =pDC->SelectObject (GetStockObject(NULL_PEN));
		COLORREF oldColor=pDC->SetDCBrushColor (RGB(233, 233, 0));
		int i, xDraw, yDraw;
		for(i=0;i<width;i++){
			xDraw=x+i, yDraw=y+(sin(omega*(x+i))+1)*height/2;
			pDC->Ellipse(xDraw-2, yDraw-2, xDraw+2, yDraw+2);
		}
		pDC->SetDCBrushColor(oldColor);
		pDC->SelectObject(oldBrush);
		pDC->SelectObject(oldPen);
	}
};
class Heart{
private:
	double equation(double x, double y, double xScale, double yScale){
		x = -5 + x * 10 /xScale;
		y = 5 - y * 10 / yScale;
		return 17*pow(x,2) - 16*fabs(x)*y + 17*pow(y,2) - 225;
	}
	int onEquation(double x, double y, double xScale, double yScale){
		return fabs(equation(x,y, xScale,yScale))<1;
	}
public:
	void draw(CDC* pDC,  double x, double y, double width, double height){
		HGDIOBJ oldBrush=pDC->SelectObject (GetStockObject(DC_BRUSH));
		HGDIOBJ oldPen  =pDC->SelectObject (GetStockObject(NULL_PEN));
		COLORREF oldColor=pDC->SetDCBrushColor (RGB(255, 0, 0));
		int  xDraw, yDraw, ix, iy;
		for(ix=0;ix<width;ix++){
			for(iy=0;iy<height;iy++){
				xDraw = x+ix, yDraw = y+iy;
				if(onEquation(ix, iy, width, height))
					pDC->Rectangle(xDraw-2, yDraw-2, xDraw+2, yDraw+2);
			}
		}
		pDC->SetDCBrushColor(oldColor);
		pDC->SelectObject(oldBrush);
		pDC->SelectObject(oldPen);
	}
};
class Circles{

public:
	void draw(CDC* pDC,  double x, double y, double width, double height){
		HGDIOBJ oldBrush=pDC->SelectObject (GetStockObject(DC_BRUSH));
		HGDIOBJ oldPen  =pDC->SelectObject (GetStockObject(WHITE_PEN));
		COLORREF oldColor=pDC->SetDCBrushColor (RGB(130, 63, 152));
		for(int i=0;i<width;i+=20)
			pDC->Ellipse(x,y,x+width-i,y+height-i);
		pDC->SetDCBrushColor(oldColor);
		pDC->SelectObject(oldBrush);
		pDC->SelectObject(oldPen);

	}
};
#endif