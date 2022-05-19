#include <string>

class Ennemi : public ObserverCollision
{
private:
	int pos_x;
	int pos_y;
public:
	virtual new_pos();
	void deplacer(int x, int y);
};