#include "NotifierCollision.h"

void NotifierCollision::addObserver(ObserverCollision obs)
{
}

void NotifierCollision::removeObserver(ObserverCollision obs)
{
}

void NotifierCollision::notify(int x, int y)
{
	NotifierCollision.test_collision(x, y);
	if (NotifierCollision.test_collision(x, y) == true) {
		NotifierCollision.collision(NotifierCollision notifieur);
	}

}
