#include "animatedwidget.h"

AnimatedWidget::AnimatedWidget(int x, int y, Background *parent) : RegularMove(x, y, parent)
{
    machine = new QStateMachine(this);
    first_state = nullptr;
}

void AnimatedWidget::add_animation(int start, int end, int loop, int duration, QString pattern, int fillwidth)
{
    add_animation(new QState(machine), start, end, loop, duration, pattern, fillwidth);
}

void AnimatedWidget::add_animation(QState* state, int start, int end, int loop, int duration, QString pattern, int fillwidth)
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
    state->assignProperty(this, "basename", pattern);
    state->assignProperty(this, "fillwidth", fillwidth);
}

void AnimatedWidget::start_animation(QState *initial)
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

int AnimatedWidget::frame()
{
    return m_frame;
}

void AnimatedWidget::setFrame(int frame)
{
    m_frame = frame;
    set_background_image(m_basename.arg(m_frame, m_fillwidth, 10, QChar('0')).toStdString());
}

QString AnimatedWidget::basename() const
{
    return m_basename;
}

void AnimatedWidget::setBasename(QString basename)
{
    this->m_basename = basename;
}

int AnimatedWidget::fillwidth() const
{
    return m_fillwidth;
}

void AnimatedWidget::setFillwidth(int fillwidth)
{
    m_fillwidth = fillwidth;
}
