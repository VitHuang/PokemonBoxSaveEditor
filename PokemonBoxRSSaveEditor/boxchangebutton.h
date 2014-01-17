#ifndef BOXCHANGEBUTTON_H
#define BOXCHANGEBUTTON_H

#include <QPushButton>
#include <QTimer>

class BoxChangeButton : public QPushButton
{
    Q_OBJECT
public:
    explicit BoxChangeButton(QWidget *parent = 0);

signals:
    void boxChanged();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);

public slots:

private:
    QTimer boxChangeTimer;

};

#endif // BOXCHANGEBUTTON_H
