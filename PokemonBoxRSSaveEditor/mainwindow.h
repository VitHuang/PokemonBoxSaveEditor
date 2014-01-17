#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include "pokemon.h"
#include "saveblock.h"
#include "gbasaveblock.h"

class IconButton;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void loadBoxSave(const QString &path);
    void loadGbaSave(const QString &path);
    void saveGbaSave(const QString &path);
    void refresh();
    void setSelectedIndex(int index);
    const Pokemon &getPokemon(int index) const;
    QPixmap *getIconSprite(int species) const;

public slots:
    void setPokemon(int index, Pokemon p);
    void swapPokemon(int indexA, int indexB);

private slots:
    void nextBox();
    void previousBox();
    void nextGbaBox();
    void previousGbaBox();
    void showSummary(int index);

    void on_actionOpenBox_triggered();

    void on_actionOpenGba_triggered();

    void on_actionSaveGba_triggered();

private:
    bool showEggSummary;
    bool showHiddenStats;
    int boxCurrentBox;
    int currentPokemon;
    int gbaCurrentBox;
    Ui::MainWindow *ui;
    IconButton *iconButtons[90];
    QPixmap *summarySprites[388];
    QPixmap *shinySprites[388];
    QString boxNames[25];
    QString gbaBoxNames[14];
    QByteArray boxData;
    QByteArray gbaData;
    Pokemon storedPokemon[1920];
    SaveBlock boxSaveBlocks[58];
    SaveBlock *boxCurrentBlocks[23];
    GbaSaveBlock gbaSaveBlocks[32];
    GbaSaveBlock *gbaCurrentBlocks[14];
};

#endif // MAINWINDOW_H
