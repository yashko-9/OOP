#include "NPC.h"



NPC::NPC()
{
	typeOfEntity = npcE;
}

NPC::NPC(string namePar)
{
	typeOfEntity = npcE;
	name = namePar;
}


bool NPC::isAlive() const
{
	return true;
}

void NPC::print() const
{
	cout << "I'm a NPC, how can I help you?" << endl;
}

NPC::~NPC()
{
}
