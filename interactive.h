#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include "regularmove.h"
#include <QKeyEvent>
#include <string>

class Interactive : public RegularMove
{
    Q_OBJECT
public:
    Interactive(int x, int y, Background *parent);
    virtual void key_pressed(char key)=0;
    virtual void arrow_pressed(std::string cmd)=0;

    void keyPressEvent(QKeyEvent* event);
};

#endif // INTERACTIVE_H
