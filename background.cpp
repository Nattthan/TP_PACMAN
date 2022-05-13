#include "background.h"
#include <QResizeEvent>

Background::Background(QWidget *parent) : Drawable(parent)
{
    set_background_image("background.png");
}

void Background::resizeEvent(QResizeEvent* event)
{
    double fx, fy;
    fx = (double)this->width()/(double)base_size.width();
    fy = (double)this->height()/(double)base_size.height();
    emit resized(fx, fy);
}


void Background::subscribe(Drawable* child)
{
    connect(this, SIGNAL(resized(double, double)), child, SLOT(resized(double, double)));
}


int Background::base_width() const
{
    return base_size.width();
}

int Background::base_height() const
{
    return base_size.height();
}
