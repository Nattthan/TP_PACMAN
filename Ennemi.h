#include <string>
#include "ObserverCollision.h"

class Ennemi : public ObserverCollision
{
private:
	int pos_x;
	int pos_y;
public:
    virtual void new_pos();
	void deplacer(int x, int y);
};
