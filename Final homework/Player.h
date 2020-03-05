#pragma once
#include "Entity.h"
#include "Mob.h"

class Player  : public Entity
{
protected:
	// ����- ����� �� �������: 
	int damage = 0;
	int health = 0;
	// ���������: Enum type �� ������ � ��������������.

public:
	Player();
	Player(string namePar, int damagePar, int healthPar);

	// �������� �� �������: 
	bool isAlive() const;

	// ����� �� �� � �������� �� ���� ��������
	// �������� �� �� ����������
	void getAttacked(int damagePar);

	void attack(Entity& cpy);

	// print �� ������ ���������� � ��� ��������
	void print() const;

	virtual ~Player();
};

