#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iconbutton.h"

#include "miscfunctions.h"

#include <QFile>
#include <QFileDialog>

#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    showEggSummary = true;
    showHiddenStats = true;
    boxCurrentBox = 0;
    currentPokemon = 0;
    ui->setupUi(this);
    for (int i = 0; i < 387; i++) {
        summarySprites[i] = new QPixmap(QString("Sprites/%1").arg(i));
        shinySprites[i] = new QPixmap(QString("ShinySprites/%1").arg(i));
    }
    summarySprites[387] = new QPixmap(QString("Sprites/egg.png"));
    ui->storageBoxLayout->addWidget(ui->previousBoxButton, 0, 0, 1, 2);
    ui->storageBoxLayout->addWidget(ui->boxLabel, 0, 2, 1, 8, Qt::AlignCenter);
    ui->storageBoxLayout->addWidget(ui->nextBoxButton, 0, 10, 1, 2);
    ui->gbaBoxLayout->addWidget(ui->gbaPreviousButton, 0, 0, 1, 2);
    ui->gbaBoxLayout->addWidget(ui->gbaBoxLabel, 0, 2, 1, 2, Qt::AlignCenter);
    ui->gbaBoxLayout->addWidget(ui->gbaNextButton, 0, 4, 1, 2);
    for (int i = 0; i < 60; i++) {
        iconButtons[i] = new IconButton(this);
        connect(iconButtons[i], SIGNAL(showPokemon(int)), this, SLOT(showSummary(int)));
        connect(iconButtons[i], SIGNAL(swapPokemon(int,int)), this, SLOT(swapPokemon(int,int)));
        ui->storageBoxLayout->addWidget(iconButtons[i], i / 12 + 1, i % 12, 1, 1);
    }
    for (int i = 0; i < 30; i++) {
        iconButtons[i + 60] = new IconButton(this);
        connect(iconButtons[i + 60], SIGNAL(showPokemon(int)), this, SLOT(showSummary(int)));
        connect(iconButtons[i + 60], SIGNAL(swapPokemon(int,int)), this, SLOT(swapPokemon(int,int)));
        ui->gbaBoxLayout->addWidget(iconButtons[i + 60], i / 6 + 1, i % 6, 1, 1);
    }
    ui->storageBoxLayout->update();
    connect(ui->nextBoxButton, SIGNAL(boxChanged()), this, SLOT(nextBox()));
    connect(ui->previousBoxButton, SIGNAL(boxChanged()), this, SLOT(previousBox()));
    connect(ui->gbaNextButton, SIGNAL(boxChanged()), this, SLOT(nextGbaBox()));
    connect(ui->gbaPreviousButton, SIGNAL(boxChanged()), this, SLOT(previousGbaBox()));
    refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadBoxSave(const QString &path)
{
    QFile file(path);
    if (!file.open(QFile::ReadOnly)) {
        return;
    }
    file.seek(0x2040);
    for (int i = 0; i < 58; i++) {
        boxSaveBlocks[i].load(&file);
    }
    file.close();
    quint32 saveCountA = boxSaveBlocks[0].getSaveCount();
    bool validA = true;
    quint32 saveCountB = boxSaveBlocks[23].getSaveCount();
    bool validB = true;
    for (int i = 0; i < 23; i++) {
        if (!boxSaveBlocks[i].isValid() || boxSaveBlocks[i].getSaveCount() != saveCountA) {
            validA = false;
        }
        if (!boxSaveBlocks[i + 23].isValid() || boxSaveBlocks[i + 23].getSaveCount() != saveCountB) {
            validB = false;
        }
    }
    if (validA && (!validB || saveCountA > saveCountB)) {
        for (int i = 0; i < 23; i++) {
            boxCurrentBlocks[boxSaveBlocks[i].getIndex()] = &boxSaveBlocks[i];
        }
    } else if (validB) {
        for (int i = 23; i < 46; i++) {
            boxCurrentBlocks[boxSaveBlocks[i].getIndex()] = &boxSaveBlocks[i];
        }
    } else {
        return;
    }
    boxData.clear();
    for (int i = 0; i < 23; i++) {
        boxData.append(boxCurrentBlocks[i]->getData());
    }
    for (int i = 0; i < 1500; i++) {
        storedPokemon[i].loadEncrypted(boxData.mid(i * 84 + 8, 84), true);
    }
    QByteArray nameData = boxData.mid(126008, 225);
    for (int i = 0; i < 25; i++) {
        boxNames[i] = MiscFunctions::decodeString(nameData.mid(i * 9, 9));
    }
    boxCurrentBox = boxCurrentBlocks[0]->getData().at(4);
    ui->nextBoxButton->setEnabled(true);
    ui->previousBoxButton->setEnabled(true);
    ui->boxLabel->setEnabled(true);
    refresh();
}

void MainWindow::loadGbaSave(const QString &path)
{
    QFile file(path);
    if (!file.open(QFile::ReadOnly)) {
        return;
    }
    for (int i = 0; i < 32; i++) {
        gbaSaveBlocks[i].load(&file);
    }
    file.close();
    quint32 saveCountA = gbaSaveBlocks[0].getSaveCount();
    bool validA = true;
    quint32 saveCountB = gbaSaveBlocks[14].getSaveCount();
    bool validB = true;
    for (int i = 0; i < 14; i++) {
        if (!gbaSaveBlocks[i].isValid() || gbaSaveBlocks[i].getSaveCount() != saveCountA) {
            qDebug() << "invalid block A" << i;
            validA = false;
        }
        if (!gbaSaveBlocks[i + 14].isValid() || gbaSaveBlocks[i + 14].getSaveCount() != saveCountB) {
            qDebug() << "invalid block B" << i;
            validB = false;
        }
    }
    if (validA && (!validB || saveCountA > saveCountB)) {
        for (int i = 0; i < 14; i++) {
            gbaCurrentBlocks[gbaSaveBlocks[i].getIndex()] = &gbaSaveBlocks[i];
        }
    } else if (validB) {
        for (int i = 14; i < 28; i++) {
            gbaCurrentBlocks[gbaSaveBlocks[i].getIndex()] = &gbaSaveBlocks[i];
        }
    } else {
        qDebug() << "invalid save";
        return;
    }
    gbaData.clear();
    for (int i = 0; i < 14; i++) {
        gbaData.append(gbaCurrentBlocks[i]->getData());
    }
    for (int i = 0; i < 420; i++) {
        storedPokemon[i + 1500].loadEncrypted(gbaData.mid(i * 80 + 0x4cb8, 80), false);
    }
    QByteArray nameData = gbaData.mid(0xcff8, 126);
    for (int i = 0; i < 14; i++) {
        gbaBoxNames[i] = MiscFunctions::decodeString(nameData.mid(i * 9, 9));
    }
    gbaCurrentBox = gbaCurrentBlocks[5]->getData().at(0);
    ui->gbaNextButton->setEnabled(true);
    ui->gbaPreviousButton->setEnabled(true);
    ui->gbaBoxLabel->setEnabled(true);
    refresh();
}

void MainWindow::saveGbaSave(const QString &path)
{
    for (int i = 0; i < 420; i++) {
        gbaData.replace(i * 80 + 0x4cb8, 80, storedPokemon[i + 1500].getEncryptedData().left(80));
    }
    int currentOffset = 0;
    for (int i = 0; i < 14; i++) {
        int length = gbaCurrentBlocks[i]->getLength();
        gbaCurrentBlocks[i]->setData(gbaData.mid(currentOffset, length));
        currentOffset += length;
    }
    QFile file(path);
    if (!file.open(QFile::WriteOnly)) {
        return;
    }
    for (int i = 0; i < 32; i++) {
        gbaSaveBlocks[i].save(&file);
    }
}

void MainWindow::refresh()
{
    int boxStart = boxCurrentBox * 60;
    int gbaBoxStart = 1500 + gbaCurrentBox * 30;
    for (int i = 0; i < 60; i++) {
        const Pokemon &p = storedPokemon[boxStart + i];
        iconButtons[i]->setIndex(boxStart + i);
        iconButtons[i]->setPokemon(&p);
        iconButtons[i]->setChecked(false);
    }
    for (int i = 0; i < 30; i++) {
        const Pokemon &p = storedPokemon[gbaBoxStart + i];
        iconButtons[i + 60]->setIndex(gbaBoxStart + i);
        iconButtons[i + 60]->setPokemon(&p);
        iconButtons[i + 60]->setChecked(false);
    }
    iconButtons[currentPokemon]->setChecked(true);
    ui->boxLabel->clear();
    ui->boxLabel->setText(boxNames[boxCurrentBox]);
    ui->gbaBoxLabel->clear();
    ui->gbaBoxLabel->setText(gbaBoxNames[gbaCurrentBox]);
    if (currentPokemon < 60) {
        showSummary(boxStart + currentPokemon);
    } else {
        showSummary(gbaBoxStart + currentPokemon - 60);
    }
}

void MainWindow::setSelectedIndex(int index)
{
    iconButtons[currentPokemon]->setChecked(false);
    currentPokemon = index;
    iconButtons[index]->setChecked(true);
}

const Pokemon &MainWindow::getPokemon(int index) const
{
    if (index < 60) {
        return storedPokemon[boxCurrentBox * 60 + index];
    } else {
        return storedPokemon[gbaCurrentBox * 30 + index - 60 + 1500];
    }
}

void MainWindow::setPokemon(int index, Pokemon p)
{
    storedPokemon[index] = p;
    refresh();
}

void MainWindow::swapPokemon(int indexA, int indexB)
{
    Pokemon temp = storedPokemon[indexA];
    storedPokemon[indexA] = storedPokemon[indexB];
    storedPokemon[indexB] = temp;
    if (indexB < 1500) {
        setSelectedIndex(indexB % 60);
    } else {
        setSelectedIndex(indexB % 30 + 60);
    }
    refresh();
}

void MainWindow::showSummary(int index)
{
    if (index < 1500) {
        setSelectedIndex(index % 60);
    } else {
        setSelectedIndex(index % 30 + 60);
    }
    const Pokemon &p = storedPokemon[index];
    if (p.getSpecies() == 0) {
        ui->nicknameLabel->setText("???");
        ui->levelLabel->setText(QString("Lv.?"));
    } else if (p.isEgg()) {
        ui->nicknameLabel->setText("Egg");
        ui->levelLabel->setText(QString("Lv.?"));
    } else {
        ui->nicknameLabel->setText(p.getNickname());
        ui->levelLabel->setText(QString("Lv.%1").arg(p.getLevel()));
    }
    if (p.getSpecies() == 0 || (p.isEgg() && !showEggSummary)) {
        ui->genderLabel->setText("");
        ui->otLabel->setText("???");
        ui->idLabel->setText("?");
        ui->move0Label->setText("---");
        ui->move1Label->setText("---");
        ui->move2Label->setText("---");
        ui->move3Label->setText("---");
        ui->hpLabel->setText("?");
        ui->attackLabel->setText("?");
        ui->defenseLabel->setText("?");
        ui->spAtkLabel->setText("?");
        ui->spDefLabel->setText("?");
        ui->speedLabel->setText("?");
        ui->natureLabel->setText("---");
        if (p.isEgg()) {
            ui->spriteLabel->setPixmap(*summarySprites[387]);
        } else {
            ui->spriteLabel->setPixmap(*summarySprites[0]);
        }
    } else {
        int gender = p.getGender();
        if (gender == 0) {
            ui->genderLabel->setText(QString::fromUtf8("\u2642"));
        } else if (gender == 1) {
            ui->genderLabel->setText(QString::fromUtf8("\u2640"));
        } else {
            ui->genderLabel->setText("");
        }
        ui->otLabel->setText(p.getOtName());
        if (showHiddenStats) {
            ui->idLabel->setText(QString("%1/%2").arg(p.getTid(), 5, 10, QChar('0')).arg(p.getSid(), 5, 10, QChar('0')));
        } else {
            ui->idLabel->setText(QString("%1").arg(p.getTid(), 5, 10, QChar('0')));
        }
        ui->move0Label->setText(MiscFunctions::getMoveName(p.getMove(0).id));
        ui->move1Label->setText(MiscFunctions::getMoveName(p.getMove(1).id));
        ui->move2Label->setText(MiscFunctions::getMoveName(p.getMove(2).id));
        ui->move3Label->setText(MiscFunctions::getMoveName(p.getMove(3).id));
        ui->hpLabel->setText(QString::number(p.getStat(0)));
        ui->attackLabel->setText(QString::number(p.getStat(1)));
        ui->defenseLabel->setText(QString::number(p.getStat(2)));
        ui->spAtkLabel->setText(QString::number(p.getStat(4)));
        ui->spDefLabel->setText(QString::number(p.getStat(5)));
        ui->speedLabel->setText(QString::number(p.getStat(3)));
        if (showHiddenStats) {
            ui->hpIvLabel->setText(QString::number(p.getIv(0)));
            ui->attackIvLabel->setText(QString::number(p.getIv(1)));
            ui->defenseIvLabel->setText(QString::number(p.getIv(2)));
            ui->spAtkIvLabel->setText(QString::number(p.getIv(4)));
            ui->spDefIvLabel->setText(QString::number(p.getIv(5)));
            ui->speedIvLabel->setText(QString::number(p.getIv(3)));
            ui->hpEvLabel->setText(QString::number(p.getEv(0)));
            ui->attackEvLabel->setText(QString::number(p.getEv(1)));
            ui->defenseEvLabel->setText(QString::number(p.getEv(2)));
            ui->spAtkEvLabel->setText(QString::number(p.getEv(4)));
            ui->spDefEvLabel->setText(QString::number(p.getEv(5)));
            ui->speedEvLabel->setText(QString::number(p.getEv(3)));
        }
        ui->natureLabel->setText(MiscFunctions::getNatureName(p.getNature()));
        if (p.isShiny()) {
            ui->spriteLabel->setPixmap(*shinySprites[p.getSpecies()]);
        } else {
            ui->spriteLabel->setPixmap(*summarySprites[p.getSpecies()]);
        }
    }
}

void MainWindow::nextBox()
{
    boxCurrentBox += 1;
    if (boxCurrentBox >= 25) {
        boxCurrentBox = 0;
    }
    refresh();
}

void MainWindow::previousBox()
{
    boxCurrentBox -= 1;
    if (boxCurrentBox < 0) {
        boxCurrentBox = 24;
    }
    refresh();

}

void MainWindow::nextGbaBox()
{
    gbaCurrentBox += 1;
    if (gbaCurrentBox >= 14) {
        gbaCurrentBox = 0;
    }
    refresh();
}


void MainWindow::previousGbaBox()
{
    gbaCurrentBox -= 1;
    if (gbaCurrentBox < 0) {
        gbaCurrentBox = 13;
    }
    refresh();

}

void MainWindow::on_actionOpenBox_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Pokémon Box save file..."), "", tr("Gamecube save files (*.gci);;All files (*.*)"));
    if (filename.isNull()) {
        return;
    }
    loadBoxSave(filename);
}

void MainWindow::on_actionOpenGba_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open GBA Pokémon save file..."), "", tr("Game Boy Advance save files (*.sav);;All files (*.*)"));
    if (filename.isNull()) {
        return;
    }
    loadGbaSave(filename);
}

void MainWindow::on_actionSaveGba_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save GBA Pokémon save file..."), "", tr("Game Boy Advance save files (*.sav)"));
    if (filename.isNull()) {
        return;
    }
    saveGbaSave(filename);
}
