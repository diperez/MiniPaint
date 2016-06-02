#pragma comment (lib, "lib/glut32.lib")

#include "figura.h"
#include "glut.h"
#include <stdio.h>
figura::figura(){}
void figura ::setparameters(bool og, float r, float g,float b,short mask)
{

	this->og =og;
	this->r=r;
	this->g=g;
	this->b=b;
	this->mask=mask;
}
int figura::abs(int x) 
{
	if(x>0)
		return x;
	return -x;
}
float figura::GlutToOpenglx(float x)
{
		int auxx=glutGet(GLUT_WINDOW_WIDTH)>>1;
		//printf("%d\n",auxx);
		x=(x/auxx) - 1;
		//x = (float)(2*x-(glutGet(GLUT_WINDOW_WIDTH)-1) )/(glutGet(GLUT_WINDOW_WIDTH)-1);
		return x;
}

float figura::GlutToOpengly(float y)
{
		int auxy=glutGet(GLUT_WINDOW_HEIGHT)>>1;
		y=((y/auxy)-1)*-1;
		//y= (float)((glutGet(GLUT_WINDOW_HEIGHT)-1)-2*y)/(glutGet(GLUT_WINDOW_HEIGHT)-1);
		return y;
}

int figura::OpenglToGlutx(float x)
{
		int auxx=glutGet(GLUT_WINDOW_WIDTH)>>1;
		int X;
		X = (int)((x*auxx) + auxx);
		return X;
}
int figura::OpenglToGluty(float y)
{
		int auxy=glutGet(GLUT_WINDOW_HEIGHT)>>1;
		int Y;
		Y = (int)(-1*(y*auxy)+auxy);
		return Y;
}