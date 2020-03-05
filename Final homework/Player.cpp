#include "Player.h"



Player::Player()
{
	// id се генерира при създаване
	// location ще се въвежда чрез setter

	typeOfEntity = playerE;
	name = " ";
	damage = 0;
	health = 0;
}


Player::Player(string namePar, int damagePar, int healthPar)
{
	// id се генерира при създаване
	// location ще се въвежда чрез setter
	name = namePar;
	damage = damagePar;
	health = healthPar;
	typeOfEntity = playerE;
}


bool Player::isAlive() const
{
	if (health > 0) {
		return true;
	}
	return false;
}

void Player::getAttacked(int damagePar)
{
	cout << name<< " is getting attacked!" << endl;
	health -= damagePar;
}

void Player::attack(Entity & cpy)
{
	double distance = getDistanceto(cpy);
	if (distance < 5) {
		cout << "Player attacks!" << endl;
		cpy.getAttacked(damage);
	}
	
}

void Player::print() const
{
	cout << "-----------------------------------------" << endl;
	cout << "id:" << id << endl;
	cout << "name: " << name << endl;
	cout << "location: ";
	location->print();
	cout << "type: " << typeOfEntity << endl;
	cout << "health: " << health << endl;
	cout << "damage: " << damage << endl;
	cout << "-----------------------------------------" << endl;
}

Player::~Player()
{
}