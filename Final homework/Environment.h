#pragma once

#include "Player.h"
#include "NPC.h"
#include "Mob.h"
#include <vector>

class Environment
{
protected:
	


public:
	vector <Entity*> entities;
	vector <Point2D*> locations;

	Environment();

	void add(Player & cpy);
	void add(Mob & cpy);
	void add(NPC & cpy);

	Entity& getAt(int index);

	void removeAt(int index);

	void generateEntities();

	void destroyEntities();

	Entity& getClosestAliveEntity(Player& cpy,type typePar);

	virtual ~Environment();
};

