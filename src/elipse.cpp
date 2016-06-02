#include "elipse.h"
elipse ::elipse()
{

}
void elipse::reDraw(int x,int y,int XM, int YM, float r, float g, float b)
{
	glBegin (GL_POINTS);
	glColor3f(r, g, b);
	glVertex3f (GlutToOpenglx((float)(x+XM)),GlutToOpengly((float)(y+YM)), 0.0f);
	glVertex3f (GlutToOpenglx((float)(x+XM)),GlutToOpengly((float)((-y+YM))), 0.0f);
	glVertex3f (GlutToOpenglx((float)((-x+XM))),GlutToOpengly((float)(y+YM)), 0.0f);
	glVertex3f (GlutToOpenglx((float)((-x+XM))),GlutToOpengly((float)((-y+YM))), 0.0f);
	glEnd ();

}
void elipse::Drawsp()
{
	Draw(this->og,this->r,this->g,this->b,this->mask);
}
void elipse::Draw(bool og,float r,float g,float B,short mask)
{
	int a,a2,b,b2,XM,YM,y,x,d1,d2,l;
	XM=(int)(OpenglToGlutx(this->X1Y1.getVX()) + OpenglToGlutx(this->X2Y2.getVX()))/2;
	YM=(int)(OpenglToGluty(this->X1Y1.getVY()) + OpenglToGluty(this->X2Y2.getVY()))/2;
	if(OpenglToGluty(this->X1Y1.getVY()) == OpenglToGluty(this->X2Y2.getVY()) || OpenglToGluty(this->X1Y1.getVY()) == OpenglToGluty(this->X2Y2.getVY()) + 1 || OpenglToGluty(this->X1Y1.getVY()) == OpenglToGluty(this->X2Y2.getVY())-1)
	{
		int X1 = OpenglToGlutx(this->X1Y1.getVX());
		int X2 = OpenglToGlutx(this->X2Y2.getVX());
		glBegin (GL_POINTS);
		glColor3f(r, g, B);
		l = 1;
		if(X2>X1)
		{
			for(int i=X1;i<X2;i++)
			{
				if(l==65536)
				{
					l=1;
				}
				if(l & mask)
					glVertex3f (GlutToOpenglx((float)(i)),this->X1Y1.getVY(), 0.0f);
				l = l<<1;

			}
		}else
		{
			for(int i=X2;i<X1;i++)
			{
					if(l==65536)
				{
					l=1;
				}
				if(l & mask)
					glVertex3f (GlutToOpenglx((float)(i)),this->X1Y1.getVY(), 0.0f);
				l = l<<1;
			}
		}

		glEnd();
		
	}else
	{
		a= abs(OpenglToGlutx(this->X2Y2.getVX()) - XM);
		b= abs(OpenglToGluty(this->X2Y2.getVY()) - YM);
		a2=a*a;
		b2=b*b;
		x=0;
		y=b;
		l=1;
		//printf("A = %d, B = %d, (XM = %d, YM = %d)\n", a, b);
		if(l & mask)
			reDraw(x,y,XM,YM,r,g,B);

		d1=(b2)+((a2)*(-b + 1/4));

		while((a2)*(y-(1/2)) > (b2)*(x+1))
		{
			l = l<<1;
			if(d1<0)
			{
				d1+=(b2)*((x*2)+3);
			}else
			{
				d1+=b2*((x*2)+3) + a2*(-(y*2)+2);
				y--;
			}
			x++;
			if(l & mask)
				reDraw(x,y,XM,YM,r,g,B);
			if(l==65536)
			{
				l=1;
			}
		}

		d2 = b2 * ((x+(1/2))*(x+(1/2))) + a2*((y-1)*(y-1)) - a2*b2;

		while(y>0)
		{
			l=l<<1;
			if(d2<0)
			{
				d2+= (b2)*(2*x+2) + a2*(-(y<<1) + 3);
				x ++;
			}else
			{
				d2+=a2*(-(y*2) + 3);
			}
			y--;
			if(l & mask)
				reDraw(x,y,XM,YM,r,g,B);

			if(l==65536)
			{
				l=1;
			}

		}
	}
}