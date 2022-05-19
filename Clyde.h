#include <string>
#include <ctime>
#include <random>

srand(time(NULL));
int val = rand() % 10; //0 à 9 (max + 1)

class Clyde : public Ennemi
{
public:
	void new_pos();
};