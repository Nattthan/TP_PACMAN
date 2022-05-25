#include <string>

class NotifierCollision;
class ObserverCollision
{
public:
    virtual void collision(NotifierCollision* notifieur)=0;
    virtual bool test_collision(int x, int y)=0;
};
