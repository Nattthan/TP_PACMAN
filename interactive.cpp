#include "interactive.h"


Interactive::Interactive(int x, int y, Background* parent):RegularMove(x, y, parent)
{
    setFocus();
}

void Interactive::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
        arrow_pressed("UP");
        break;
    case Qt::Key_Down:
        arrow_pressed("DOWN");
        break;
    case Qt::Key_Left:
        arrow_pressed("LEFT");
        break;
    case Qt::Key_Right:
        arrow_pressed("RIGHT");
        break;
    default:
        QString text = event->text();
        if (text.size() == 1)
        {
            QChar ch = text[0];
            if (ch.isLetterOrNumber())
            {
                key_pressed(ch.toLatin1());
            }
        }
    }
}
