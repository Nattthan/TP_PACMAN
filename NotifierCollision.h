#include <string>
#include <iostream>
#include "Personnage.h"

class NotifierCollision {
private:

public:
	void addObserver(ObserverCollision obs);
	void removeObserver(ObserverCollision obs);
	void notify(int x, int y);
};