#include <string>
class Personnage : public NotifierCollision;class Personnage : public ObserverCollision
{
private:
	std::string cur_dep;
public:
	void Personnage(int pos_x, int pos_y);
	void new_pos();
	bool test_collision(int x, int y);
	void collision(NotifierCollision notifieur);
	void key_pressed(char key);
	void arrow_pressed(std::string cmd);
	void update_pos();
}