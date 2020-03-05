#include "Point3D.h"



Point3D::Point3D()
{
	x = 0;
	y = 0;
	z = 0;
}

Point3D::Point3D(double xPar, double yPar, double zPar) : Point2D(xPar, yPar)
{
	z = zPar;
}

double Point3D::getDistanceTo(const Point3D & cpy) const
{
	return sqrt(pow(x - cpy.x, 2) + pow(y - cpy.y, 2) + pow(z - cpy.z, 2));
}


void Point3D::print() const
{
	Point2D::print();
	cout << "z: " << z << endl;
}

void Point3D::setX(double xPar)
{
	x = xPar;
}
/*
void Point3D::setY(double yPar)
{
	y = yPar;
}

void Point3D::setZ(double zPar)
{
	z = zPar;
}

double Point3D::getX() const
{
	return x;
}

double Point3D::getY() const
{
	return y;
}

double Point3D::getZ() const
{
	return z;
}

*/
