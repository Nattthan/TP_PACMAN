#include "drawableelem.h"
#include <QDebug>

DrawableElem::DrawableElem(int x, int y, Background* parent) : Drawable(parent), pos_x(x), pos_y(y)
{
    parent->subscribe(this);
}


void DrawableElem::resized(double fx, double fy)
{
    QRect geom;
    // redimensionnement sans marge
    geom.setTop(pos_y*sizeHint().height()*fy);
    geom.setLeft(pos_x*sizeHint().width()*fx);
    geom.setWidth(sizeHint().width()*fx);
    geom.setHeight(sizeHint().height()*fy);

    correct_margins(geom);
    this->setGeometry(geom);
}


void DrawableElem::correct_margins(QRect& geom)
{
    // ajout de marges pour respecter l'aspect ratio
    if (geom.width() > geom.height())
    {
        geom.setLeft(geom.left()+(geom.width()-geom.height())/2);
        geom.setWidth(geom.height());
    }
    else if (geom.height() > geom.width())
    {
        geom.setTop(geom.top()+(geom.height()-geom.width())/2);
        geom.setHeight(geom.width());
    }
}
