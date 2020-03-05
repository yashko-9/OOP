#pragma once
#include "Entity.h"
#include "Player.h"

class Mob : public Entity
{
protected:
	// ����-����� �� �������:
	int damage = 0;
	int health = 0;
	// ���������: Enum type �� ������ � ��������������.
public:

	Mob();
	Mob(string namePar, int damagePar, int healthPar);


	// �������� �� �������:
	bool isAlive() const;
	// ���������: Entity �� ��������� ���� � �� ��� Player 
	

	// ����� �� �� � �������� �� ���� ��������
	// �������� �� �� ����������
	void getAttacked(int damagePar);

	void attack(Entity& cpy);

	// print �� ������ ���������� � ��� ��������
	void print() const;

	virtual ~Mob();
};
