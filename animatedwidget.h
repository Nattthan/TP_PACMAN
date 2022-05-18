#ifndef ANIMATEDWIDGET_H
#define ANIMATEDWIDGET_H

#include <QtStateMachine/QStateMachine>
#include <QWidget>
#include <QPropertyAnimation>
#include "regularmove.h"

class AnimatedWidget : public RegularMove
{
    Q_OBJECT
    Q_PROPERTY(int frame READ frame WRITE setFrame)
    Q_PROPERTY(QString basename READ basename WRITE setBasename);
    Q_PROPERTY(int fillwidth READ fillwidth WRITE setFillwidth);

public:
    explicit AnimatedWidget(int x, int y, Background *parent = nullptr);
    int frame();
    void setFrame(int frame);

    QString basename() const;
    void setBasename(QString basename);

    int fillwidth() const;
    void setFillwidth(int fillwidth);

    void add_animation(int, int, int, int, QString, int fillwidth=0);
    void add_animation(QState*, int, int, int, int, QString, int fillwidth=0);
    void start_animation(QState* initial=nullptr);

protected:
    int m_frame;
    int m_fillwidth;
    QString m_basename;
    QStateMachine* machine;
    QPropertyAnimation animation;
    QState* first_state;
};

#endif // ANIMATEDWIDGET_H
