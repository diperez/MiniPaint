#include "linea.h"
linea::linea(){}
void linea::swap(int *x, int *y)
{
	int aux;
	aux = *x;
	*x=*y;
	*y=aux;
}
void linea :: Drawsp(){

	Draw(this->og,this->r,this->g,this->b,this->mask);
}
void linea::Draw (bool og,float r, float g, float b,short mask)
{
	int inc;
	bool how;
	bool pilas=true;
	int dx, dy, incE, incNE, d, x, y,X1,X2,Y1,Y2,l;
	X2=OpenglToGlutx(this->X2Y2.getVX());X1=OpenglToGlutx(this->X1Y1.getVX());
	Y2=OpenglToGluty(this->X2Y2.getVY());Y1=OpenglToGluty(this->X1Y1.getVY());
	//printf("x2= %d\n",X2);
	how= abs(Y2 - Y1) > abs(X2-X1);
	if(og)
	{
		glColor3f(r,g,b);
		glLineStipple(1,mask);
		glBegin(GL_LINE_STRIP);
		glVertex3f (GlutToOpenglx((float)X1),GlutToOpengly((float)Y1), 0.0f);
		glVertex3f (GlutToOpenglx((float)X2),GlutToOpengly((float)Y2), 0.0f);
		glEnd();
	}else
	{
		if(how)
		{
			swap(&X1,&Y1);
			swap(&X2,&Y2);
		}
		if(X1 > X2)
		{
			swap(&X1,&X2);
			swap(&Y1,&Y2);

		}
		dx = X2 - X1;
		dy = Y2 - Y1;

		if(dy<0)
		{
			inc = -1;
			dy = -dy;
		}else
		{
			inc =1;
		}
		l=1;
		incE = dy << 1;
		incNE = (dy-dx)<<1;
		d = (dy << 1) - dx;
		y = Y1;
		glBegin (GL_POINTS);
		glColor3f(r, g, b);
		for(x=X1; x <= X2; x++)
		{
			if( l & mask)
			{
				if(how)
				{
					glVertex3f (GlutToOpenglx((float)y),GlutToOpengly((float)x), 0.0f);
				}else
				{
					glVertex3f (GlutToOpenglx((float)x),GlutToOpengly((float)y), 0.0f);
				}
			}
			if(d<=0)
			{
				d+=incE;
			}else
			{
				d+=incNE;
				y+=inc;
			}
			if(l==65536)
			{
				l=1;
			}else
			{
				l=l<<1;
			}
		}
		glEnd ();
	}
}