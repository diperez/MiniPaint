#include "figura.h"
class linea : public figura
{
	public:
		linea();
		void swap(int *x, int*y);
		void Drawsp();
		void Draw(bool og,float r, float g, float b,short mask);

};