#include "cuadrado.h"
class triangulo : public figura
{
	public:
		triangulo();
		linea* l1;
		linea* l2;
		linea* l3;
		void Draw(bool og,float r, float g, float b,short mask);
		void Drawsp();
};