#ifndef DRAWABLEELEM_H
#define DRAWABLEELEM_H

#include "drawable.h"
#include "background.h"

class DrawableElem : public Drawable
{
    Q_OBJECT
public:
    DrawableElem(int x, int y, Background* parent);

    QSize sizeHint() const {  return QSize(40, 40);}

public slots:
    void resized(double, double);


protected:
    void correct_margins(QRect& geom);
    int pos_x, pos_y;
};

#endif // DRAWABLEELEM_H
