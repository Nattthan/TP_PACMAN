#include "Personnage.h"

Personnage::Personnage(int pos_x, int pos_y)
{
}

void Personnage::new_pos()
{
    
    if (cur_dep == "UP") {
        pos_y -= 1;
    }
    else if (cur_dep == "DOWN") {
        pos_y += 1;
    }
    else if (cur_dep == "LEFT") {
        pos_x -= 1;
    }
    else if (cur_dep == "RIGHT") {
        pos_x += 1;
    }
    else if (cur_dep == "IDLE") {}
    notify(pos_x, pos_y);
}

bool Personnage::test_collision(int x, int y)
{
    if (x == pos_x && y == pos_y) {
        return true;
    }
    else {
        return false;
    }
}

void Personnage::collision(NotifierCollision notifieur)
{
    std::cout << "Il y a eu une collsion!" << std::endl;
}

void Personnage::key_pressed(char key)
{
}

void Personnage::arrow_pressed(std::string cmd)
{
}

void Personnage::update_pos()
{
}
