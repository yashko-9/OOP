#pragma once
#include "Entity.h"

class NPC : public Entity
{
public:
	NPC();
	NPC(string namePar);
	bool isAlive() const;
	void print() const;
	~NPC();
};

