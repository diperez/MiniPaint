#include "punto.h"

punto::punto()
{
	punto::vx=0;
	punto::vy=0;
	punto::vz=0;
}
float punto::getVX()
{
	return punto::vx;
}
float punto::getVY()
{
	return punto::vy;
}
float punto::getVZ()
{
	return punto::vz;
}
void punto::setVX(float VX)
{
	punto::vx=VX;
}
void punto::setVY(float VY)
{
	punto::vy=VY;
}
void punto::setVZ(float VZ)
{
	punto::vz=VZ;
}