#include "triangulo.h"
triangulo ::triangulo()
{
	triangulo::l1=new linea();
	triangulo::l2=new linea();
	triangulo::l3=new linea();
}
void triangulo ::Drawsp()
{
	Draw(this->og,this->r,this->g,this->b,this->mask);
}
void triangulo :: Draw(bool og,float r, float g, float b,short mask)
{
	float X1,Y1,X2,Y2,X3,Y3;
	
	X1=this->X1Y1.getVX();Y1=this->X1Y1.getVY();
	X2=this->X2Y2.getVX();Y2=this->X2Y2.getVY();
	X3=this->X3Y3.getVX();Y3=this->X3Y3.getVY();

	l1->X1Y1.setVX(X1);l1->X1Y1.setVY(Y1);
	l1->X2Y2.setVX(X2);l1->X2Y2.setVY(Y2);

	l2->X1Y1.setVX(X2);l2->X1Y1.setVY(Y2);
	l2->X2Y2.setVX(X3);l2->X2Y2.setVY(Y3);

	l3->X1Y1.setVX(X3);l3->X1Y1.setVY(Y3);
	l3->X2Y2.setVX(X1);l3->X2Y2.setVY(Y1);

	if(og)
	{
		glLineStipple(1,mask);
		glBegin (GL_TRIANGLES);
		glColor3f(r,g,b);
		glVertex3f (X1,Y1, 0.0f);
		glVertex3f (X2,Y2, 0.0f);
		glVertex3f (X3,Y3, 0.0f);
		glEnd();
	
	}else
	{
		this->l1->Draw(og,r,g,b,mask);
		this->l2->Draw(og,r,g,b,mask);
		this->l3->Draw(og,r,g,b,mask);
	}

}