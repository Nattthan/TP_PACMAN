#include <iostream>
#include <mainwindow.h>
#include <string>
using namespace std;
#include <QApplication>
#include "Personnage.h"

bool detecter_collision(int ennemis_x[], int ennemis_y[], int nb_ennemis,
    int x, int y);
bool deplacer_personnage(int x, int y, std::string cmd);
void ExceptionBounds();
void ExceptionCommand();
class ExceptionSizeTab {

};

int main(int argc, char** argv)
{
    int x = 5, y = 4;
    Personnage perso();

    int enn_x[4] = { 1, 2, 3, 4 }, enn_y[4] = { 1, 2, 3, 4 };
    try {
        if (detecter_collision(enn_x, enn_y, 4, x, y))
        {
            std::cout << "Collision" << std::endl;
        }
    }
    catch (ExceptionSizeTab& est)
    {
        std::cout << "Nombre d'ennemis est inférieur à 1" << std::endl;
    }
    do {
        string cmd;
        std::getline(cin, cmd);
        cout << "Vous avez saisi " << cmd << endl;
        int x = 5, y = 4;
        try {
            deplacer_personnage(x, y, cmd);
        }
        catch (std::out_of_range& ExceptionBounds) {
            cout << "Vous allez dépasser les limites, faire un autre choix" << endl;
        }
        catch (std::string& ExceptionCommand) {
            cout << "La commande de déplacement n'est pas reconnu" << endl;
        }

        cout << "x= " << x << "\n" << "y= " << y << endl;
        return 0;
    } while (true);

    return 0;
}

bool detecter_collision(int ennemis_x[], int ennemis_y[], int nb_ennemis, int x, int y) {

    int i;
    if (nb_ennemis > 0)
    {
        for (i = 0; i < nb_ennemis; i++)
        {
            if (ennemis_x[i] == x && ennemis_y[i] == y)
                return true;
        }
        return false;
    }
    throw ExceptionSizeTab();//abcd
}

bool deplacer_personnage(int x, int y, std::string cmd) {
    const int xmin = 0;
    const int xmax = 32;
    const int ymin = 0;
    const int ymax = 15;

    if (cmd == "UP") {
        y -= 1;
        if (y < ymin) {
            return false;
        }
        else return true;
    }
    else if (cmd == "DOWN") {
        y += 1;
        if (y > ymax) {
            return false;
        }
        else return true;
    }
    else if (cmd == "LEFT") {
        x -= 1;
        if (x < xmin) {
            return false;
        }
        else return true;
    }
    else if (cmd == "RIGHT") {
        x += 1;
        if (x > xmax) {
            return false;
        }
        else return true;
    }
    else if (cmd == "IDLE") {
        return false;
    }
    else return false;

}
