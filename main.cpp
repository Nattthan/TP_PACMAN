#include <iostream>
#include <string>

bool detecter_collision(int ennemis_x[], int ennemis_y[], int nb_ennemis,
    int x, int y);

class ExceptionSizeTab{

};

int main(int argc, char** argv)
{
    int x = 5, y = 4;
    int enn_x[4] = { 1, 2, 3, 4 }, enn_y[4] = { 1, 2, 3, 4 };
    try{
        if (detecter_collision(enn_x, enn_y, 4, x, y))
        {
            std::cout << "Collision" << std::endl;
        }
    }
    catch (ExceptionSizeTab& est)
    {
        std::cout << "Nombre d'ennemis est inférieur à 1" << std::endl;
    }

    return 0;
}

bool detecter_collision(int ennemis_x[], int ennemis_y[], int nb_ennemis, int x, int y) {

    int i;
    if (nb_ennemis>0)
    {
        for (i=0; i<nb_ennemis ; i++)
        {
            if (ennemis_x[i]== x && ennemis_y[i] == y)
                return true;
        }
        return false;
    }
    throw ExceptionSizeTab();//abcd
}
