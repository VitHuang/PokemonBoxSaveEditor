#ifndef ICONBUTTON_H
#define ICONBUTTON_H

#include <QPushButton>

#include "pokemon.h"

class QMouseEvent;

class IconButton : public QPushButton
{
    Q_OBJECT
public:
    explicit IconButton(QWidget *parent);
    void setPokemon(const Pokemon *p);
    void setIndex(int index);

signals:
    void showPokemon(int index);
    void swapPokemon(int indexA, int indexB);

private slots:
    void clickedProxy();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    int index;
    QPoint dragStartPosition;
    const Pokemon *pokemon;
    static QPixmap *iconSprites[];
    static bool loadedIcons;

};

#endif // ICONBUTTON_H
