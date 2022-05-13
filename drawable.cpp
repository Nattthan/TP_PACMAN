#include "drawable.h"
#include "consts.h"
#include "background.h"

Drawable::Drawable(QWidget *parent) :
    QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground, true);
}

void Drawable::remove_inheritance()
{
    this->setStyleSheet("border-image: none; background-color:none");
}


void Drawable::set_background_image(std::string filename)
{
    QString stylesheet = "border-image: url(";
    stylesheet += IMG_PATH + QString::fromStdString(filename) + ");";
    this->setStyleSheet(stylesheet);
    qDebug() << this->styleSheet();
}

void Drawable::set_background_color(int r, int g, int b, int a)
{
    QColor color(r, g, b, a);
    QString stylesheet = "border-image: none;"
                         "background-color: rgba(%1, %2, %3, %4);";
    stylesheet = stylesheet.arg(color.red()).arg(color.green()).arg(color.blue()).arg(color.alpha());
    this->setStyleSheet(stylesheet);
}
