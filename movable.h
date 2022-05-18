#ifndef MOVABLE_H
#define MOVABLE_H

#include "drawableelem.h"

class Movable : public DrawableElem
{
    Q_OBJECT
public:
    Movable(int x, int y, Background *parent);

    void positionner(int x, int y);
    int get_pos_x() const;
    int get_pos_y() const;


protected:
    Background* parent;
};

#endif // MOVABLE_H
