#include "Clyde.h"

void Clyde::new_pos()
{
    srand(time(NULL));
    int val1 = rand() % 10; //0 à 9 (max + 1)
    int val = rand() % 10; //0 à 9 (max + 1)
    int pos_x = val1;
    int pos_y = val;
}
