#include "Point2D.h"



Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(double xPar, double yPar)
{
	x = xPar;
	y = yPar;
}



double Point2D::getDistanceTo(const Point2D & cpy) const
{
	return sqrt(pow(x - cpy.x, 2) + pow(y - cpy.y, 2));
}


void Point2D::print() const
{
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
}

void Point2D::setX(double xPar)
{
	x = xPar;
}

void Point2D::setY(double yPar)
{
	y = yPar;
}

double Point2D::getX() const
{
	return x;
}

double Point2D::getY() const
{
	return y;
}

