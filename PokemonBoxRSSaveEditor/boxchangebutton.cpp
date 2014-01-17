#include "boxchangebutton.h"

#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QMimeData>

BoxChangeButton::BoxChangeButton(QWidget *parent) :
    QPushButton(parent)
{
    boxChangeTimer.setInterval(300);
    connect(this, SIGNAL(pressed()), &boxChangeTimer, SLOT(start()));
    connect(this, SIGNAL(pressed()), this, SIGNAL(boxChanged()));
    connect(this, SIGNAL(released()), &boxChangeTimer, SLOT(stop()));
    connect(&boxChangeTimer, SIGNAL(timeout()), this, SIGNAL(boxChanged()));
    setAcceptDrops(true);
}

void BoxChangeButton::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/pokemon-box-rs-index")) {
        event->acceptProposedAction();
        boxChangeTimer.start();
        emit boxChanged();
    }
}

void BoxChangeButton::dragLeaveEvent(QDragLeaveEvent *event)
{
    boxChangeTimer.stop();
}
