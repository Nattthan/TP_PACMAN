#include "ObserverCollision.h"

void ObserverCollision::collision(NotifierCollision notifieur)
{
	std::cout << "Il y a une collision!" << std::endl;
}

bool ObserverCollision::test_collision(int x, int y)
{
	if (x == Ennemi.new_pos()) {
		return true;
	}
	else {
		return false;
	}
}
