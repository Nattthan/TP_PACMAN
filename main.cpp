#include "mainwindow.h"
#include <iostream>
#include <string>

using namespace std;

#include <QApplication>
#include <string>

bool deplacer_personnage(int x, int y, std::string cmd);
void ExceptionBounds ();
void ExceptionCommand ();

int main(int argc, char** argv)
{
    do {
        string cmd;
        std::getline(cin, cmd);
        cout << "Vous avez saisi " << cmd << endl;
        int x = 5, y = 4;
        try {
            deplacer_personnage(x, y, cmd);
        }
        catch (std::out_of_range& ExceptionBounds){
            cout << "Vous allez dépasser les limites, faire un autre choix" << endl;
        }
        catch (std::string& ExceptionCommand){
            cout << "La commande de déplacement n'est pas reconnu" << endl;
        }

        cout << "x= " << x << "\n" << "y= " << y << endl;
        return 0;
    }while (true);
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
