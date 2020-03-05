#pragma once
#include "Entity.h"
#include "Mob.h"

class Player  : public Entity
{
protected:
	// член- данни по условие: 
	int damage = 0;
	int health = 0;
	// забележка: Enum type се задава в конструкторите.

public:
	Player();
	Player(string namePar, int damagePar, int healthPar);

	// методите по условие: 
	bool isAlive() const;

	// метод за да е възможно да бъде атакуван
	// активира се от атакуващия
	void getAttacked(int damagePar);

	void attack(Entity& cpy);

	// print на цялата информация с цел тестване
	void print() const;

	virtual ~Player();
};

