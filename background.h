#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "drawable.h"

class Background : public Drawable
{
    Q_OBJECT
public:
    explicit Background(QWidget* parent);

    void subscribe(Drawable* child);

    int base_width() const;
    int base_height() const;

    void resizeEvent(QResizeEvent* event);

private:
    const QSize base_size = QSize(1280, 600);

signals:
    void resized(double, double);
};

#endif // BACKGROUND_H
