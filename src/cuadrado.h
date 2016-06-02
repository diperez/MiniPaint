#include "linea.h"
class cuadrado : public figura
{
	public:
		cuadrado();
		linea* l1;
		linea* l2;
		linea* l3;
		linea* l4;
		void Draw(bool og,float r, float g, float b,short mask);
		void Drawsp();
};