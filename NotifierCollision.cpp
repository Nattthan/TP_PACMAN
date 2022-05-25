#include "NotifierCollision.h"
#include "ObserverCollision.h"

void NotifierCollision::addObserver(ObserverCollision* obs)
{
}

void NotifierCollision::removeObserver(ObserverCollision* obs)
{
}

void NotifierCollision::notify(int x, int y)
{
    int i;
    for (i=0; i < observers.size() ; i++)
    {
        ObserverCollision* obs = observers[i];
        if (obs->test_collision(x, y)) {
        obs->collision(this);
        }
	}

}
