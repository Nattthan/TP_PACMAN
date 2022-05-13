#include "regularmove.h"

#ifdef ANIMATION
#include <QtStateMachine/QStateMachine>
#include <QWidget>
#include <QPropertyAnimation>
#include <QDebug>
#endif

RegularMove::RegularMove(int x, int y, Background* parent) : Movable(x, y, parent)
{
#ifdef ANIMATION
    machine = new QStateMachine(this);
    first_state = nullptr;
#endif
    timer = new QTimer(this);
    timer->setInterval(500);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(_update_pos()));
    timer->start();
}

void RegularMove::_update_pos()
{
    update_pos();
}

#ifdef ANIMATION
void RegularMove::positionner(int x, int y)
{
    if (parent)
    {
        double factor_x = (double)parent->width()/(double)parent->base_width();
        double factor_y = (double)parent->height()/(double)parent->base_height();
        QPoint offset = QPoint(x*sizeHint().width()*factor_x, y*sizeHint().height()*factor_y);

        QRect geom;
        geom.setTop(y*sizeHint().height()*factor_y);
        geom.setLeft(x*sizeHint().width()*factor_x);
        geom.setWidth(sizeHint().width()*factor_x);
        geom.setHeight(sizeHint().height()*factor_y);
        correct_margins(geom);
        pos_x = x;
        pos_y = y;
        mov_animation.setTargetObject(this);
        mov_animation.setPropertyName("geometry");
        mov_animation.setStartValue(this->geometry());
        mov_animation.setEndValue(geom);
        mov_animation.setDuration(300);
        mov_animation.start();
        qDebug() << pos_x << pos_y << this->geometry()  << geom;
    }
}

void RegularMove::add_animation(int start, int end, int loop, int duration, std::string pattern)
{
    add_animation(new QState(machine), start, end, loop, duration, pattern);
}

void RegularMove::add_animation(QState* state, int start, int end, int loop, int duration, std::string pattern)
{
    if (!first_state)
    {
        first_state = state;
    }
    connect(state, SIGNAL(entered()), &animation, SLOT(stop()));
    connect(state, SIGNAL(entered()), &animation, SLOT(start()));
    state->assignProperty(&animation, "startValue", start);
    state->assignProperty(&animation, "endValue", end+1);
    state->assignProperty(&animation, "loopCount", loop);
    state->assignProperty(&animation, "duration", duration);
    state->assignProperty(this, "basename", QString::fromStdString(pattern));
}

void RegularMove::start_animation(QState *initial)
{
    if (!initial)
    {
        initial = first_state;
    }
    animation.setPropertyName("frame");
    animation.setTargetObject(this);

    machine->setInitialState(initial);
    machine->start();

    animation.start();
}

int RegularMove::frame()
{
    return m_frame;
}

void RegularMove::setFrame(int frame)
{
    m_frame = frame;
    set_background_image(m_basename.arg(m_frame).toStdString());
}

QString RegularMove::_basename() const
{
    return m_basename;
}

void RegularMove::_setBasename(QString basename)
{
    this->m_basename = basename;
}


std::string RegularMove::direction() const
{
    return dir;
}

void RegularMove::set_direction(std::string direction)
{
    if (direction == "UP")
    {
        emit up();
    }
    else if (direction == "DOWN")
    {
        emit down();
    }
    else if (direction == "RIGHT")
    {
        emit right();
    }
    else if(direction == "LEFT")
    {
        emit left();
    }
    dir = direction;
}

void RegularMove::init_animation_perso()
{
    init_animation("pacman", 4);
    QState* st_go = new QState(machine);
    st_dr->addTransition(this, SIGNAL(collision()), st_go);
    st_ga->addTransition(this, SIGNAL(collision()), st_go);
    st_ba->addTransition(this, SIGNAL(collision()), st_go);
    st_ha->addTransition(this, SIGNAL(collision()), st_go);
    add_animation(st_go, 1, 4, 3, 500, "pacman_go_%1.png");
}

void RegularMove::init_animation_ennemi(std::string nom)
{
    init_animation(nom, 2);
}


void RegularMove::init_animation(std::string nom, int nb_frames)
{
    st_dr = new QState(machine);
    st_ga = new QState(machine);
    st_ha = new QState(machine);
    st_ba = new QState(machine);

    st_dr->addTransition(this, SIGNAL(left()), st_ga);
    st_dr->addTransition(this, SIGNAL(up()), st_ha);
    st_dr->addTransition(this, SIGNAL(down()), st_ba);

    st_ga->addTransition(this, SIGNAL(up()), st_ha);
    st_ga->addTransition(this, SIGNAL(down()), st_ba);
    st_ga->addTransition(this, SIGNAL(right()), st_dr);

    st_ha->addTransition(this, SIGNAL(left()), st_ga);
    st_ha->addTransition(this, SIGNAL(down()), st_ba);
    st_ha->addTransition(this, SIGNAL(right()), st_dr);

    st_ba->addTransition(this, SIGNAL(left()), st_ga);
    st_ba->addTransition(this, SIGNAL(up()), st_ha);
    st_ba->addTransition(this, SIGNAL(right()), st_dr);

    int duration = 500;
    add_animation(st_dr, 1, nb_frames, -1, duration, nom + "_dr_%1.png");
    add_animation(st_ga, 1, nb_frames,  -1, duration, nom + "_ga_%1.png");
    add_animation(st_ha, 1, nb_frames, -1, duration, nom + "_ha_%1.png");
    add_animation(st_ba, 1, nb_frames,  -1, duration, nom + "_ba_%1.png");
    start_animation(st_dr);
}
#endif
