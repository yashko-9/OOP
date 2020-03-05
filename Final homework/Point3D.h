#pragma once
#include "Point2D.h"
class Point3D : public Point2D
{
protected:
	double z;
public:
	Point3D();
	Point3D(double xPar, double yPar, double zPar);

	double getDistanceTo(const Point3D & cpy) const; 
	
	void print() const;
	

	virtual void setX(double xPar);
	//void setY(double yPar);
	//void setZ(double zPar);

	//double getX() const;
	//double getY() const;
	//double getZ() const;

	virtual ~Point3D() {};
};

