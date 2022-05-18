#ifndef REGULARMOVE_H
#define REGULARMOVE_H

//#define ANIMATION
#ifdef ANIMATION
#include <QState>
#include <QPropertyAnimation>
#endif

#include "movable.h"
#include <QTimer>

class RegularMove : public Movable
{
    Q_OBJECT
#ifdef ANIMATION
    Q_PROPERTY(int frame READ frame WRITE setFrame)
    Q_PROPERTY(QString basename READ _basename WRITE _setBasename);
#endif

public:
    RegularMove(int x, int y, Background *parent);
    virtual void update_pos()=0;

#ifdef ANIMATION
    std::string direction() const;
    void set_direction(std::string);

    void init_animation_perso();
    void init_animation_ennemi(std::string);
    void positionner(int x, int y);
    void show_collision() {emit collision();}
#endif

private:
#ifdef ANIMATION
    void init_animation(std::string nom, int nb_frames);

    QString _basename() const;
    void _setBasename(QString basename);

    int frame();
    void setFrame(int frame);

    QState* st_dr;
    QState* st_ga;
    QState* st_ha;
    QState* st_ba;
#endif
    QTimer* timer;

private slots:
    void _update_pos();

#ifdef ANIMATION
signals:
    void left();
    void right();
    void up();
    void down();
    void collision();

protected:
    int m_frame;
    QString m_basename;
    QStateMachine* machine;
    std::string dir;
    QPropertyAnimation animation;
    QPropertyAnimation mov_animation;
    QState* first_state;

    void add_animation(int, int, int, int, std::string);
    void add_animation(QState*, int, int, int, int, std::string);
    void start_animation(QState* initial=nullptr);
#endif
};

#endif // REGULARMOVE_H
