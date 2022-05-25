#include <string>
#include <iostream>
#include <vector>

class ObserverCollision;
class NotifierCollision
{
private :
    std::vector <ObserverCollision*> observers;
public:
    void addObserver(ObserverCollision* obs);
    void removeObserver(ObserverCollision* obs);
	void notify(int x, int y);
};
