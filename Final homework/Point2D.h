#pragma once
#include <iostream>


using namespace std;

class Point2D
{
protected:
	double x;
	double y;
public:
	Point2D();
	Point2D(double xPar, double yPar);

	double getDistanceTo(const Point2D & cpy) const; 

	virtual void print() const;
	virtual ~Point2D() {};
	
	virtual void setX(double xPar);
	virtual void setY(double yPar);

	virtual double getX() const;
	virtual double getY() const;

	
};
