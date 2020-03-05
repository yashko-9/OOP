#include "Environment.h"






Environment::Environment()
{
}

void Environment::add(Player & cpy)
{
	entities.push_back(&cpy);
	locations.push_back(cpy.location);
}

void Environment::add(Mob & cpy)
{
	entities.push_back(&cpy);
	locations.push_back(cpy.location);
}

void Environment::add(NPC & cpy)
{
	entities.push_back(&cpy);
	locations.push_back(cpy.location);
}

Entity & Environment::getAt(int index)
{
	return *entities[index];
}

void Environment::removeAt(int index)
{
	entities.erase(entities.begin() + index);
	locations.erase(locations.begin() + index);
}

void Environment::generateEntities()
{
	// понеже не е казано да се ползва random, стойностите им ще се въвеждат от клавиатурата 

	int count;
	cout << "How many entities do you want to create?" << endl;
	cin >> count;
	for (int i = 0; i < count; i++) {
		int type;
		cout << "Press (1)for Player (2)for Mob (3)for NPC" << endl;
		cout << "Select type of entity" << endl;
		cin >> type;

		if (type == 1) {
			string name;
			int damage, health, x, y, z, locType;
			cout << "Enter the name of the player: " << endl;
			cin >> name;
			cout << "Enter the damage of the player: " << endl;
			cin >> damage;
			cout << "Enter the health of the player: " << endl;
			cin >> health;

			cout << "Select type of location. Press (2) for 2D, press (3) for 3D" << endl;
			cin >> locType;
			if (locType == 2) {
				cout << "Creating 2D location (x,y)" << endl;
				cout << "x:" << endl;
				cin >> x;
				cout << "y:" << endl;
				cin >> y;
				locations.push_back(new Point2D(x, y));
			}
			if (locType == 3) {
				cout << "Creating 3D location (x,y,z)" << endl;
				cout << "x:" << endl;
				cin >> x;
				cout << "y:" << endl;
				cin >> y;
				cout << "z:" << endl;
				cin >> z;
				locations.push_back(new Point3D(x, y, z));
			}
			int index = locations.size() - 1;
			entities.push_back(new Player(name, damage, health));
			entities[index]->setLocation(*locations[index]);
		}
		if (type == 2) {
			string name;
			int damage, health, x, y, z, locType;
			cout << "Enter the name of the mob: " << endl;
			cin >> name;
			cout << "Enter the damage of the mob: " << endl;
			cin >> damage;
			cout << "Enter the health of the mob: " << endl;
			cin >> health;

			cout << "Select type of location. Press (2) for 2D, press (3) for 3D" << endl;
			cin >> locType;
			if (locType == 2) {
				cout << "Creating 2D location (x,y)" << endl;
				cout << "x:" << endl;
				cin >> x;
				cout << "y:" << endl;
				cin >> y;
				locations.push_back(new Point2D(x, y));
			}
			if (locType == 3) {
				cout << "Creating 3D location (x,y,z)" << endl;
				cout << "x:" << endl;
				cin >> x;
				cout << "y:" << endl;
				cin >> y;
				cout << "z:" << endl;
				cin >> z;
				locations.push_back(new Point3D(x, y, z));
			}
			int index = locations.size() - 1;
			entities.push_back(new Mob(name, damage, health));
			entities[index]->setLocation(*locations[index]);
		}
		if (type == 3) {
			string name;
			int x, y, z, locType;
			cout << "Enter the name of the NPC: " << endl;
			cin >> name;
			cout << "Select type of location. Press (2) for 2D, press (3) for 3D" << endl;
			cin >> locType;
			if (locType == 2) {
				cout << "Creating 2D location (x,y)" << endl;
				cout << "x:" << endl;
				cin >> x;
				cout << "y:" << endl;
				cin >> y;
				locations.push_back(new Point2D(x, y));
			}
			if (locType == 3) {
				cout << "Creating 3D location (x,y,z)" << endl;
				cout << "x:" << endl;
				cin >> x;
				cout << "y:" << endl;
				cin >> y;
				cout << "z:" << endl;
				cin >> z;
				locations.push_back(new Point3D(x, y, z));
			}
			int index = locations.size() - 1;
			entities.push_back(new NPC(name));
			entities[index]->setLocation(*locations[index]);
		}

	}
	
}

void Environment::destroyEntities()
{
	// entities.size == locations.size 
	int size = entities.size();
	entities.erase(entities.begin(), entities.begin() + size);
	locations.erase(locations.begin(), locations.begin() + size);
}

Entity & Environment::getClosestAliveEntity(Player & cpy, type typePar)
{
	int closestIndex = 0;
	double minDistance = 100;

	for (int i = 0; i < entities.size(); i++) {
		if (entities[i]->isAlive()) {
			if (entities[i]->typeOfEntity == typePar) {
				double distance = entities[i]->getDistanceto(cpy);
				if (distance < minDistance) {
					minDistance = distance;
					closestIndex = i;
				}
			}
		}
	}

	return *entities[closestIndex];
}


Environment::~Environment()
{
}
