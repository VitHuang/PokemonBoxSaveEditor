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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionSave_as;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *storageBoxLayout;
    QFormLayout *summaryLayout;
    QLabel *spriteLabel;
    QLabel *label;
    QLabel *nicknameLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        storageBoxLayout = new QGridLayout();
        storageBoxLayout->setSpacing(6);
        storageBoxLayout->setObjectName(QStringLiteral("storageBoxLayout"));

        horizontalLayout_2->addLayout(storageBoxLayout);

        summaryLayout = new QFormLayout();
        summaryLayout->setSpacing(6);
        summaryLayout->setObjectName(QStringLiteral("summaryLayout"));
        summaryLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        spriteLabel = new QLabel(centralWidget);
        spriteLabel->setObjectName(QStringLiteral("spriteLabel"));

        summaryLayout->setWidget(0, QFormLayout::LabelRole, spriteLabel);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        summaryLayout->setWidget(1, QFormLayout::LabelRole, label);

        nicknameLabel = new QLabel(centralWidget);
        nicknameLabel->setObjectName(QStringLiteral("nicknameLabel"));

        summaryLayout->setWidget(1, QFormLayout::FieldRole, nicknameLabel);


        horizontalLayout_2->addLayout(summaryLayout);

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
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "&Load...", 0));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save &as...", 0));
        spriteLabel->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Nickname:", 0));
        nicknameLabel->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
