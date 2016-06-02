#include "triangulo.h"

class elipse : public figura
{
	public:
		elipse();
		void Draw(bool og,float r, float g, float b,short mask);
		void reDraw(int x, int y, int XM, int YM, float r, float g, float b);
		void Drawsp();
};