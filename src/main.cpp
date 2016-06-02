/*
Autor : Diego A Perez A
CI : 19754458
*/

#pragma comment (lib, "lib/glut32.lib")

#include <vector>
#include <stack>
#include "elipse.h"
using namespace std;

vector<figura*> v;
stack<figura*> c;
figura *globallinea;
bool num=false,tria=false,tria2=false,og=false;
int what=0;
int mask=0xFFFF;
float r=1.0,g=1.0,b=1.0;
float GlutToOpenglx(float x)
{
		int auxx=glutGet(GLUT_WINDOW_WIDTH)>>1;
		//printf("%d\n",auxx);
		x=(x/auxx) - 1;
		//x = (float)(2*x-(glutGet(GLUT_WINDOW_WIDTH)-1) )/(glutGet(GLUT_WINDOW_WIDTH)-1);
		return x;
}
float GlutToOpengly(float y)
{
		int auxy=glutGet(GLUT_WINDOW_HEIGHT)>>1;
		y=((y/auxy)-1)*-1;
		//y= (float)((glutGet(GLUT_WINDOW_HEIGHT)-1)-2*y)/(glutGet(GLUT_WINDOW_HEIGHT)-1);
		return y;
}
void menuApp(int value)
{
	if(value == 1)
	{
		what=0;
		tria2=tria=false;
	}
	if(value == 2)
	{
		what=1;
		tria2=tria=false;
	}
	if(value == 3)
	{
		tria2=true;
		what=2;
	}
	if(value ==4)
	{
		what=3;
		tria2=tria=false;
	}
	if(value == 9)exit(0);
}
void menuApp2(int value)
{
	if(value == 1)
	{
		mask=0xFFFF;
	}
	if(value == 2)
	{
		mask=0x0F0F;
	}
	if(value == 3)
	{
		mask=0x5F5F;
	}
	if(value == 4)
	{
		mask=0xAAAA;
	}
}
void menuApp3(int value)
{
	if(value == 1)
	{
		og=true;
	}
	if(value == 2)
	{
		og=false;
	}
}
void menuApp4(int value)
{
	if(value == 1)
	{
		r=1.0;g=1.0;b=1.0;
	}
	if(value == 2)
	{
		r=1.0;g=1.0;b=0.0;
	}
	if(value == 3)
	{
		r=0.0;g=1.0;b=0.0;
	}
	if(value == 4)
	{
		r=0.0;g=1.0;b=1.0;
	}
	if(value == 5)
	{
		r=0.0;g=0.0;b=1.0;
	}
	if(value == 6)
	{
		r=1.0;g=0.0;b=1.0;
	}
	if(value == 7)
	{
		r=1.0;g=0.0;b=0.0;
	}
}
void renderScene (void)
{
	void init();
	{
		int submenu_forma,submenu_tipo_linea,submenu_despliegue,submenu_colores;
		submenu_forma=glutCreateMenu(menuApp);
		glutAddMenuEntry ("Linea",1);
		glutAddMenuEntry ("Rectangulo",2);
		glutAddMenuEntry ("Triangulo",3);
		glutAddMenuEntry ("Elipse",4);
		submenu_tipo_linea=glutCreateMenu(menuApp2);
		glutAddMenuEntry ("Continua",1);
		glutAddMenuEntry ("Raya_Espacio_Raya",2);
		glutAddMenuEntry ("Punto_Raya",3);
		glutAddMenuEntry ("Punto_Espacio_Punto",4);
		submenu_despliegue=glutCreateMenu(menuApp3);
		glutAddMenuEntry ("Open gl",1);
		glutAddMenuEntry ("Bresenham",2);
		submenu_colores=glutCreateMenu(menuApp4);
		glutAddMenuEntry ("Blanco",1);
		glutAddMenuEntry ("Amarillo",2);
		glutAddMenuEntry ("Verde",3);
		glutAddMenuEntry ("Cyan",4);
		glutAddMenuEntry ("Azul",5);
		glutAddMenuEntry ("Magenta",6);
		glutAddMenuEntry ("Rojo",7);
		glutCreateMenu (menuApp);
		glutAddSubMenu ("Formas",submenu_forma);
		glutAddSubMenu ("Tipo linea",submenu_tipo_linea);
		glutAddSubMenu ("Despliegue",submenu_despliegue);
		glutAddSubMenu ("Colores",submenu_colores);
		glutAddMenuEntry ("Salir",9);
		
		glutAttachMenu (GLUT_RIGHT_BUTTON);
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for(unsigned int i=0;i < v.size();i++)
	{
		v.at(i)->Drawsp();
		//printf("inicio %d fin %d\n",b.at(i)->X1Y1.getVX(),b.at(i)->X2Y2.getVX());
		//printf("%d\n",b.size());
	}
	glutSwapBuffers();

}
void ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.0f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}
void ctrZ()
{
	if(!v.empty())
	{
		c.push(v.back());
		v.pop_back();
		renderScene();
	}
}
void ctrY()
{
	if(!c.empty())
	{
		v.push_back(c.top());
		c.pop();
	}
	renderScene();
}
void limpiarPantalla()
{
	while(!v.empty())
		v.pop_back();
	while(!c.empty())
		c.pop();
	renderScene();
}
void teclado (unsigned char key, int x, int y)
{
	if(key==122)// z
		ctrZ();
	if(key==121)// y
		ctrY();
	if(key==27)
		limpiarPantalla();
}
void pasivo (int x, int y)
{


}
void click (int boton, int estado, int x, int y)
{
	if((estado==GLUT_UP))
	{
		if(tria2 && tria)
		{
			tria=false;
		}else
		{
			if(tria2)
				tria=true;

		}
		num=false;
	}
	if((estado==GLUT_DOWN))
	{
		if(tria)
		{
			float X=GlutToOpenglx((float)x);
			float Y=GlutToOpengly((float)y);

			globallinea->X2Y2.setVX(X);
			globallinea->X2Y2.setVY(Y);
			renderScene();
		}
	}
}
void movimiento (int X, int Y)
{
	//printf("%d,%d\n",X,Y);
	float x=GlutToOpenglx((float)X);
	float y=GlutToOpengly((float)Y);
	//printf("%f,%f\n",x,y);
	while(!c.empty())
		c.pop();
	switch(what)
	{
		case 0:
			if(!num)
			{
				globallinea=new linea();
				v.push_back(globallinea);
				globallinea->X1Y1.setVX(x);
				globallinea->X1Y1.setVY(y);
				globallinea->X2Y2.setVX(x);
				globallinea->X2Y2.setVY(y);
				globallinea->setparameters(og,r,g,b,mask);
			}else
			{
				globallinea->X2Y2.setVX(x);
				globallinea->X2Y2.setVY(y);
			}
			num=true;
			break;

		case 1:
			if(!num)
			{
				globallinea=new cuadrado();
				v.push_back(globallinea);
				globallinea->X1Y1.setVX(x);
				globallinea->X1Y1.setVY(y);
				globallinea->X2Y2.setVX(x);
				globallinea->X2Y2.setVY(y);
				globallinea->setparameters(og,r,g,b,mask);
			}else
			{
				globallinea->X2Y2.setVX(x);
				globallinea->X2Y2.setVY(y);
			}
			num=true;
			break;
		case 2:

			if(!(num || tria))
			{
				globallinea=new triangulo();
				v.push_back(globallinea);
				globallinea->X1Y1.setVX(x);
				globallinea->X1Y1.setVY(y);
				globallinea->X2Y2.setVX(x);
				globallinea->X2Y2.setVY(y);
				globallinea->X3Y3.setVX(x);
				globallinea->X3Y3.setVY(y);
				globallinea->setparameters(og,r,g,b,mask);
			}else
			{	
				if(tria)
				{
					globallinea->X2Y2.setVX(x);
					globallinea->X2Y2.setVY(y);
				}else
				{
					globallinea->X3Y3.setVX(x);
					globallinea->X3Y3.setVY(y);
				}
				
			}
			num=true;
			break;
		case 3:
			if(!num)
			{
				globallinea=new elipse();
				v.push_back(globallinea);
				globallinea->X1Y1.setVX(x);
				globallinea->X1Y1.setVY(y);
				globallinea->X2Y2.setVX(x);
				globallinea->X2Y2.setVY(y);
				globallinea->setparameters(og,r,g,b,mask);
			}else
			{
				globallinea->X2Y2.setVX(x);
				globallinea->X2Y2.setVY(y);
			}
			num=true;
			break;

		default:
			break;
	}
renderScene();
}
int main (int argc, char *argv [])
{
	glutInit (&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition (100, 100);
	glutInitWindowSize (500, 500);
	glutCreateWindow ("Tarea#1");
	glEnable(GL_LINE_STIPPLE);
	glutDisplayFunc (renderScene);
	//glutReshapeFunc(ReSizeGLScene);
	glutMotionFunc(movimiento);
	glutMouseFunc(click);
	glutKeyboardFunc(teclado);
	//glutPassiveMotionFunc(pasivo);
	glutMainLoop ();

}