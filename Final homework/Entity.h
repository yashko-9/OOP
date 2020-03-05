#pragma once
#include "Point3D.h"
#include <string>
#include <typeinfo>

static int globalID = 0;

enum type {
		none = 0,
		playerE,
		npcE,
		mobE
	};

class Entity
{
protected:
	
	string name;
	int damage = 0; 
	int health = 0;

public:
	Entity();
	Point2D* location = new Point2D;
	int id = ++globalID;
	type typeOfEntity = none;
	

	// методите по условие: 
	virtual bool isAlive() const;
	double getDistanceto2D(Entity & cpy);
	double getDistanceto(Entity & cpy);
	void moveTo(Point2D & cpy);
	void moveTo(const Entity& cpy);
	
	// pure virtual function
	virtual void print() const = 0;

	// setter за location
	void setLocation(Point2D & cpy);

	// polymorphism
	virtual void getAttacked(int damagePar) {};
	virtual void attack(Entity& cpy) {};

	virtual ~Entity();
};