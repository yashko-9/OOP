#include "Mob.h"



Mob::Mob()
{
	typeOfEntity = mobE;
}

Mob::Mob(string namePar, int damagePar, int healthPar)
{
	typeOfEntity = mobE;
	name = namePar;
	damage = damagePar;
	health = healthPar;

}


bool Mob::isAlive() const
{
	if (health > 0) {
		return true;
	}
	return false;
}



void Mob::getAttacked(int damagePar)
{
	cout << name <<" is getting attacked!" << endl;
	health -= damagePar;
}
void Mob::attack(Entity & cpy)
{
	string name = typeid(cpy).name();
	string playerName = typeid(Player).name();
	
	// Mob може да атакува само тип Player
	if (name == playerName) {
		double distance = getDistanceto(cpy);
		if (distance < 5) {
			cout << "Mob attacks!" << endl;
			cpy.getAttacked(damage);
		}
	}
	else {
		cout << "Mob can't attack another mob!" << endl;
	}
}


void Mob::print() const
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

Mob::~Mob()
{
}
