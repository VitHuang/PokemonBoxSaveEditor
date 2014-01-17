/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "boxchangebutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenBox;
    QAction *actionSaveAll;
    QAction *actionSaveBox;
    QAction *actionOpenGba;
    QAction *actionSaveGba;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *spriteLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nicknameLabel;
    QLabel *genderLabel;
    QLabel *levelLabel;
    QGridLayout *gridLayout_5;
    QLabel *hpLabel;
    QLabel *hpIvLabel;
    QLabel *otLabel;
    QLabel *spDefLabel;
    QLabel *label_6;
    QLabel *label;
    QLabel *defenseLabel;
    QLabel *speedLabel;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *attackLabel;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *spAtkLabel;
    QLabel *label_5;
    QLabel *hpEvLabel;
    QLabel *attackIvLabel;
    QLabel *attackEvLabel;
    QLabel *defenseIvLabel;
    QLabel *defenseEvLabel;
    QLabel *spAtkIvLabel;
    QLabel *spAtkEvLabel;
    QLabel *spDefIvLabel;
    QLabel *spDefEvLabel;
    QLabel *speedIvLabel;
    QLabel *speedEvLabel;
    QLabel *natureLabel;
    QLabel *idLabel;
    QVBoxLayout *verticalLayout;
    QLabel *move0Label;
    QLabel *move1Label;
    QLabel *move2Label;
    QLabel *move3Label;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *storageBoxLayout;
    QLabel *boxLabel;
    BoxChangeButton *previousBoxButton;
    BoxChangeButton *nextBoxButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gbaBoxLayout;
    BoxChangeButton *gbaPreviousButton;
    BoxChangeButton *gbaNextButton;
    QLabel *gbaBoxLabel;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionOpenBox = new QAction(MainWindow);
        actionOpenBox->setObjectName(QStringLiteral("actionOpenBox"));
        actionSaveAll = new QAction(MainWindow);
        actionSaveAll->setObjectName(QStringLiteral("actionSaveAll"));
        actionSaveBox = new QAction(MainWindow);
        actionSaveBox->setObjectName(QStringLiteral("actionSaveBox"));
        actionOpenGba = new QAction(MainWindow);
        actionOpenGba->setObjectName(QStringLiteral("actionOpenGba"));
        actionSaveGba = new QAction(MainWindow);
        actionSaveGba->setObjectName(QStringLiteral("actionSaveGba"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        spriteLabel = new QLabel(centralWidget);
        spriteLabel->setObjectName(QStringLiteral("spriteLabel"));

        verticalLayout_2->addWidget(spriteLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nicknameLabel = new QLabel(centralWidget);
        nicknameLabel->setObjectName(QStringLiteral("nicknameLabel"));
        nicknameLabel->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(nicknameLabel);

        genderLabel = new QLabel(centralWidget);
        genderLabel->setObjectName(QStringLiteral("genderLabel"));
        genderLabel->setMinimumSize(QSize(10, 0));

        horizontalLayout_2->addWidget(genderLabel);

        levelLabel = new QLabel(centralWidget);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));

        horizontalLayout_2->addWidget(levelLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(6);
        hpLabel = new QLabel(centralWidget);
        hpLabel->setObjectName(QStringLiteral("hpLabel"));
        hpLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(hpLabel, 1, 1, 1, 1);

        hpIvLabel = new QLabel(centralWidget);
        hpIvLabel->setObjectName(QStringLiteral("hpIvLabel"));
        hpIvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(hpIvLabel, 1, 2, 1, 1);

        otLabel = new QLabel(centralWidget);
        otLabel->setObjectName(QStringLiteral("otLabel"));
        otLabel->setMinimumSize(QSize(60, 0));

        gridLayout_5->addWidget(otLabel, 0, 0, 1, 1);

        spDefLabel = new QLabel(centralWidget);
        spDefLabel->setObjectName(QStringLiteral("spDefLabel"));
        spDefLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(spDefLabel, 5, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_5->addWidget(label_6, 6, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_5->addWidget(label, 1, 0, 1, 1);

        defenseLabel = new QLabel(centralWidget);
        defenseLabel->setObjectName(QStringLiteral("defenseLabel"));
        defenseLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(defenseLabel, 3, 1, 1, 1);

        speedLabel = new QLabel(centralWidget);
        speedLabel->setObjectName(QStringLiteral("speedLabel"));
        speedLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(speedLabel, 6, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 7, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 4, 0, 1, 1);

        attackLabel = new QLabel(centralWidget);
        attackLabel->setObjectName(QStringLiteral("attackLabel"));
        attackLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(attackLabel, 2, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_5->addWidget(label_2, 2, 0, 1, 1);

        spAtkLabel = new QLabel(centralWidget);
        spAtkLabel->setObjectName(QStringLiteral("spAtkLabel"));
        spAtkLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(spAtkLabel, 4, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 5, 0, 1, 1);

        hpEvLabel = new QLabel(centralWidget);
        hpEvLabel->setObjectName(QStringLiteral("hpEvLabel"));
        hpEvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(hpEvLabel, 1, 3, 1, 1);

        attackIvLabel = new QLabel(centralWidget);
        attackIvLabel->setObjectName(QStringLiteral("attackIvLabel"));
        attackIvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(attackIvLabel, 2, 2, 1, 1);

        attackEvLabel = new QLabel(centralWidget);
        attackEvLabel->setObjectName(QStringLiteral("attackEvLabel"));
        attackEvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(attackEvLabel, 2, 3, 1, 1);

        defenseIvLabel = new QLabel(centralWidget);
        defenseIvLabel->setObjectName(QStringLiteral("defenseIvLabel"));
        defenseIvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(defenseIvLabel, 3, 2, 1, 1);

        defenseEvLabel = new QLabel(centralWidget);
        defenseEvLabel->setObjectName(QStringLiteral("defenseEvLabel"));
        defenseEvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(defenseEvLabel, 3, 3, 1, 1);

        spAtkIvLabel = new QLabel(centralWidget);
        spAtkIvLabel->setObjectName(QStringLiteral("spAtkIvLabel"));
        spAtkIvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(spAtkIvLabel, 4, 2, 1, 1);

        spAtkEvLabel = new QLabel(centralWidget);
        spAtkEvLabel->setObjectName(QStringLiteral("spAtkEvLabel"));
        spAtkEvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(spAtkEvLabel, 4, 3, 1, 1);

        spDefIvLabel = new QLabel(centralWidget);
        spDefIvLabel->setObjectName(QStringLiteral("spDefIvLabel"));
        spDefIvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(spDefIvLabel, 5, 2, 1, 1);

        spDefEvLabel = new QLabel(centralWidget);
        spDefEvLabel->setObjectName(QStringLiteral("spDefEvLabel"));
        spDefEvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(spDefEvLabel, 5, 3, 1, 1);

        speedIvLabel = new QLabel(centralWidget);
        speedIvLabel->setObjectName(QStringLiteral("speedIvLabel"));
        speedIvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(speedIvLabel, 6, 2, 1, 1);

        speedEvLabel = new QLabel(centralWidget);
        speedEvLabel->setObjectName(QStringLiteral("speedEvLabel"));
        speedEvLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(speedEvLabel, 6, 3, 1, 1);

        natureLabel = new QLabel(centralWidget);
        natureLabel->setObjectName(QStringLiteral("natureLabel"));

        gridLayout_5->addWidget(natureLabel, 7, 1, 1, 2);

        idLabel = new QLabel(centralWidget);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        idLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(idLabel, 0, 1, 1, 3);


        verticalLayout_2->addLayout(gridLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        move0Label = new QLabel(centralWidget);
        move0Label->setObjectName(QStringLiteral("move0Label"));

        verticalLayout->addWidget(move0Label);

        move1Label = new QLabel(centralWidget);
        move1Label->setObjectName(QStringLiteral("move1Label"));

        verticalLayout->addWidget(move1Label);

        move2Label = new QLabel(centralWidget);
        move2Label->setObjectName(QStringLiteral("move2Label"));

        verticalLayout->addWidget(move2Label);

        move3Label = new QLabel(centralWidget);
        move3Label->setObjectName(QStringLiteral("move3Label"));

        verticalLayout->addWidget(move3Label);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        storageBoxLayout = new QGridLayout();
        storageBoxLayout->setSpacing(6);
        storageBoxLayout->setObjectName(QStringLiteral("storageBoxLayout"));
        boxLabel = new QLabel(centralWidget);
        boxLabel->setObjectName(QStringLiteral("boxLabel"));
        boxLabel->setEnabled(false);

        storageBoxLayout->addWidget(boxLabel, 0, 2, 1, 2, Qt::AlignHCenter);

        previousBoxButton = new BoxChangeButton(centralWidget);
        previousBoxButton->setObjectName(QStringLiteral("previousBoxButton"));
        previousBoxButton->setEnabled(false);

        storageBoxLayout->addWidget(previousBoxButton, 0, 1, 1, 1);

        nextBoxButton = new BoxChangeButton(centralWidget);
        nextBoxButton->setObjectName(QStringLiteral("nextBoxButton"));
        nextBoxButton->setEnabled(false);

        storageBoxLayout->addWidget(nextBoxButton, 0, 4, 1, 1);


        verticalLayout_3->addLayout(storageBoxLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        gbaBoxLayout = new QGridLayout();
        gbaBoxLayout->setSpacing(6);
        gbaBoxLayout->setObjectName(QStringLiteral("gbaBoxLayout"));
        gbaPreviousButton = new BoxChangeButton(centralWidget);
        gbaPreviousButton->setObjectName(QStringLiteral("gbaPreviousButton"));
        gbaPreviousButton->setEnabled(false);

        gbaBoxLayout->addWidget(gbaPreviousButton, 0, 0, 1, 1);

        gbaNextButton = new BoxChangeButton(centralWidget);
        gbaNextButton->setObjectName(QStringLiteral("gbaNextButton"));
        gbaNextButton->setEnabled(false);

        gbaBoxLayout->addWidget(gbaNextButton, 0, 2, 1, 1);

        gbaBoxLabel = new QLabel(centralWidget);
        gbaBoxLabel->setObjectName(QStringLiteral("gbaBoxLabel"));
        gbaBoxLabel->setEnabled(false);

        gbaBoxLayout->addWidget(gbaBoxLabel, 0, 1, 1, 1, Qt::AlignHCenter);


        horizontalLayout->addLayout(gbaBoxLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpenBox);
        menuFile->addAction(actionOpenGba);
        menuFile->addAction(actionSaveBox);
        menuFile->addAction(actionSaveGba);
        menuFile->addAction(actionSaveAll);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pok\303\251mon Box: Ruby & Sapphire", 0));
        actionOpenBox->setText(QApplication::translate("MainWindow", "Open Pok\303\251mon Box save file...", 0));
        actionSaveAll->setText(QApplication::translate("MainWindow", "Save all", 0));
        actionSaveBox->setText(QApplication::translate("MainWindow", "Save Pok\303\251mon Box save file...", 0));
        actionOpenGba->setText(QApplication::translate("MainWindow", "Open GBA save file...", 0));
        actionSaveGba->setText(QApplication::translate("MainWindow", "Save GBA save file...", 0));
        spriteLabel->setText(QString());
        nicknameLabel->setText(QApplication::translate("MainWindow", "???", 0));
        genderLabel->setText(QString());
        levelLabel->setText(QApplication::translate("MainWindow", "Lv.?", 0));
        hpLabel->setText(QApplication::translate("MainWindow", "?", 0));
        hpIvLabel->setText(QString());
        otLabel->setText(QApplication::translate("MainWindow", "???", 0));
        spDefLabel->setText(QApplication::translate("MainWindow", "?", 0));
        label_6->setText(QApplication::translate("MainWindow", "Speed", 0));
        label->setText(QApplication::translate("MainWindow", "HP", 0));
        defenseLabel->setText(QApplication::translate("MainWindow", "?", 0));
        speedLabel->setText(QApplication::translate("MainWindow", "?", 0));
        label_7->setText(QApplication::translate("MainWindow", "Nature", 0));
        label_4->setText(QApplication::translate("MainWindow", "Sp. Atk", 0));
        attackLabel->setText(QApplication::translate("MainWindow", "?", 0));
        label_3->setText(QApplication::translate("MainWindow", "Defense", 0));
        label_2->setText(QApplication::translate("MainWindow", "Attack", 0));
        spAtkLabel->setText(QApplication::translate("MainWindow", "?", 0));
        label_5->setText(QApplication::translate("MainWindow", "Sp. Def", 0));
        hpEvLabel->setText(QString());
        attackIvLabel->setText(QString());
        attackEvLabel->setText(QString());
        defenseIvLabel->setText(QString());
        defenseEvLabel->setText(QString());
        spAtkIvLabel->setText(QString());
        spAtkEvLabel->setText(QString());
        spDefIvLabel->setText(QString());
        spDefEvLabel->setText(QString());
        speedIvLabel->setText(QString());
        speedEvLabel->setText(QString());
        natureLabel->setText(QApplication::translate("MainWindow", "---", 0));
        idLabel->setText(QApplication::translate("MainWindow", "?", 0));
        move0Label->setText(QApplication::translate("MainWindow", "---", 0));
        move1Label->setText(QApplication::translate("MainWindow", "---", 0));
        move2Label->setText(QApplication::translate("MainWindow", "---", 0));
        move3Label->setText(QApplication::translate("MainWindow", "---", 0));
        boxLabel->setText(QApplication::translate("MainWindow", "BOX 1", 0));
        previousBoxButton->setText(QApplication::translate("MainWindow", "<", 0));
        nextBoxButton->setText(QApplication::translate("MainWindow", ">", 0));
        gbaPreviousButton->setText(QApplication::translate("MainWindow", "<", 0));
        gbaNextButton->setText(QApplication::translate("MainWindow", ">", 0));
        gbaBoxLabel->setText(QApplication::translate("MainWindow", "BOX 1", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
