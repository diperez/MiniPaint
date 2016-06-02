#pragma comment (lib, "lib/glut32.lib")
#include "glut.h"
#include "punto.h"

class figura
{
public:
	punto X1Y1;
	punto X2Y2;
	punto X3Y3;
	bool og;
	float r;
	float g;
	float b;
	short mask;
	figura();
	int abs(int x);
	virtual void Drawsp()=0;
	virtual void Draw(bool og,float r, float g, float b, short mask)=0;
	float GlutToOpenglx(float x);
	float GlutToOpengly(float y);
	int OpenglToGlutx(float x);
	int OpenglToGluty(float y);
	void setparameters(bool og, float r, float g, float b,short mask);
};