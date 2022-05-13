#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QWidget>

class Drawable : public QWidget
{
    Q_OBJECT
public:
    Drawable(QWidget *parent);
    void set_background_image(std::string filename);
    void set_background_color(int r, int g, int b, int a=255);
    void remove_inheritance();

};

#endif // DRAWABLE_H
