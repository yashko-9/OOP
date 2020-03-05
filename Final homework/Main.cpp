#include <iostream>
#include <typeinfo>
#include <string>

#include "Point2D.h"
#include "Point3D.h"
#include "Entity.h"
#include "Player.h"
#include "NPC.h"
#include "Mob.h"
#include "Environment.h"

using namespace std;

int main() {
	//enum types:
	//none = 0
	//playerE = 1
	//npcE = 2
	//mobE = 3
	Point2D a(3, 0);
	Point2D b(2, 5);
	Point3D c(5, -1,5);
	Point3D d(1, 3, 2);
	Player one("Player1", 85, 1000);
	Player two("player2", 75, 1500);
	Mob mob1("mob1", 15, 40);
	Mob mob2("mob2", 40, 100);
	Mob mob3("mob3", 15, 40);
	Mob mob4("mob4", 40, 100);
	one.setLocation(a);
	two.setLocation(c);
	mob1.setLocation(a);
	mob2.setLocation(b);
	mob3.setLocation(c);
	mob4.setLocation(d);

	Environment environment;
	environment.add(one);
	environment.add(two);
	environment.add(mob1);
	environment.add(mob2);
	environment.add(mob3);
	environment.add(mob4);
	
	//mob2 не е атакуван, тъй като дистанцията е по-голяма от 5.
	//mob4 е атакуван 2 пъти за да бъде убит от player1 понеже има 100hp , а player1 има 75damage

	for (int i = 0; i < environment.entities.size(); i++) {
			one.attack(environment.getClosestAliveEntity(one, mobE));
	}

	

	system("pause");
	return 0;
}