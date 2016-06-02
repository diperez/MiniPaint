#include "cuadrado.h"
cuadrado ::cuadrado()
{
	cuadrado::l1=new linea();
	cuadrado::l2=new linea();
	cuadrado::l3=new linea();
	cuadrado::l4=new linea();
}
void cuadrado::Drawsp()
{
	Draw(this->og,this->r,this->g,this->b,this->mask);
}
void cuadrado::Draw(bool og,float r, float g, float b,short mask)
{
	float X1,Y1,X2,Y2,X3,Y3,X4,Y4;
	X1=this->X1Y1.getVX();Y1=this->X1Y1.getVY();
	X2=this->X2Y2.getVX();Y2=this->X1Y1.getVY();
	X3=this->X2Y2.getVX();Y3=this->X2Y2.getVY();
	X4=this->X1Y1.getVX();Y4=this->X2Y2.getVY();
	this->l1->X1Y1.setVX(X1);this->l1->X1Y1.setVY(Y1);
	this->l1->X2Y2.setVX(X2);this->l1->X2Y2.setVY(Y2);

	this->l2->X1Y1.setVX(X2);this->l2->X1Y1.setVY(Y2);
	this->l2->X2Y2.setVX(X3);this->l2->X2Y2.setVY(Y3);

	this->l3->X1Y1.setVX(X3);this->l3->X1Y1.setVY(Y3);
	this->l3->X2Y2.setVX(X4);this->l3->X2Y2.setVY(Y4);

	this->l4->X1Y1.setVX(X4);this->l4->X1Y1.setVY(Y4);
	this->l4->X2Y2.setVX(X1);this->l4->X2Y2.setVY(Y1);

	if(og)
	{
		glLineStipple(1,mask);
		glBegin (GL_QUADS);
		glColor3f(r,g,b);
		glVertex3f (X3,Y3, 0.0f);
		glVertex3f (X4,Y4, 0.0f);
		glVertex3f (X1,Y1, 0.0f);
		glVertex3f (X2,Y2, 0.0f);
		glEnd();
	}else
	{
		this->l1->Draw(og,r,g,b,mask);
		this->l2->Draw(og,r,g,b,mask);
		this->l3->Draw(og,r,g,b,mask);
		this->l4->Draw(og,r,g,b,mask);
	}
}