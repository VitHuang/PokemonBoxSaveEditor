#include "iconbutton.h"

#include <QMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>

#include "mainwindow.h"

QPixmap *IconButton::iconSprites[388];
bool IconButton::loadedIcons = false;

IconButton::IconButton(QWidget *parent) :
    QPushButton(parent)
{
    if (!loadedIcons) {
        for (int i = 0; i < 387; i++) {
            iconSprites[i] = new QPixmap(QString("Icons/%1.png").arg(i, 3, 10, QChar('0')));
        }
        iconSprites[387] = new QPixmap(QString("Icons/egg.png"));
    }
    setIcon(*iconSprites[0]);
    setIconSize(iconSprites[0]->size());
    setAcceptDrops(true);
    setCheckable(true);
    this->index = index;
    connect(this, SIGNAL(clicked()), this, SLOT(clickedProxy()));
}

void IconButton::setPokemon(const Pokemon *p)
{
    pokemon = p;
    if (p->isEgg()) {
        setIcon(QIcon(*iconSprites[387]));
    } else {
        setIcon(QIcon(*iconSprites[p->getSpecies()]));
    }
}

void IconButton::setIndex(int index)
{
    this->index = index;
}

void IconButton::clickedProxy()
{
    emit showPokemon(index);
}

void IconButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragStartPosition = event->pos();
    }
    QPushButton::mousePressEvent(event);
}

void IconButton::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton)) {
        return;
    }
    if ((event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance()) {
        return;
    }
    QDrag *drag = new QDrag(this);
    QMimeData *data = new QMimeData;
    data->setData("application/pokemon-box-rs-index", QByteArray::number(index));
    drag->setMimeData(data);
    drag->setPixmap(*iconSprites[pokemon->getSpecies()]);
    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    QPushButton::mouseMoveEvent(event);
}

void IconButton::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/pokemon-box-rs-index")) {
        event->acceptProposedAction();
    }
}

void IconButton::dropEvent(QDropEvent *event)
{
    const QByteArray &bytes = event->mimeData()->data("application/pokemon-box-rs-index");
    emit swapPokemon(bytes.toInt(), index);
}
