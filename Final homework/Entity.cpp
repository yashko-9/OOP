#include "Entity.h"



Entity::Entity()
{
}



bool Entity::isAlive() const
{
	return true;
}

double Entity::getDistanceto2D(Entity & cpy)
{
	Point2D location2D = (Point2D)*location;
	Point2D cpyLocation2D = (Point2D)*cpy.location;
	return location2D.getDistanceTo(cpyLocation2D);
}

double Entity::getDistanceto(Entity & cpy)
{
	string name1 = typeid(*location).name();
	string name2 = typeid(*(cpy.location)).name();
	string namePoint3D = typeid(Point3D).name();

	if (name1 == namePoint3D && name2 == namePoint3D) {
		double distance = 0.0;
		
		Point3D* loc1 = dynamic_cast<Point3D*>(location);
		Point3D* loc2 = dynamic_cast<Point3D*>(cpy.location);
		Point3D value1 = *loc1;
		Point3D value2 = *loc2;
		return value1.getDistanceTo(value2);
		
	}
		
	return getDistanceto2D(cpy);
}

void Entity::moveTo(Point2D & cpy)
{
	string name1 = typeid(*location).name();
	string namePoint2D = typeid(Point2D).name();
	string namePoint3D = typeid(Point3D).name();

	//����� ��������� �� ��������� �, �� �� 3D ���� �� ����� 2D, �� �� 2D �� ���� �� 3D 

	// ��� location � 2D, ������ ���� ��������� z, �� �� �� ����� ���� x,y �� ���������;
	if (name1 == namePoint2D) {
		location->setX(cpy.getX());
		location->setY(cpy.getY());
	}

	// ��� location � 3D �� ����� 2D,������ ���������� � 2D ������ ���� �������� �� z;
	// ��� ���������� � 3D, �� ������ 3D
	if (name1 == namePoint3D) {
		location = &cpy;
	}

}

void Entity::moveTo(const Entity & cpy)
{
	string name1 = typeid(*location).name();
	string namePoint2D = typeid(Point2D).name();
	string namePoint3D = typeid(Point3D).name();

	// ��� � 2D ������ ���� x,y
	if (name1 == namePoint2D) {
		location->setX(cpy.location->getX());
		location->setY(cpy.location->getY());
	}
	
	if (name1 == namePoint3D) {
		location = cpy.location;
	}
}

void Entity::setLocation(Point2D & cpy)
{
	location = &cpy;
}



Entity::~Entity()
{
}
