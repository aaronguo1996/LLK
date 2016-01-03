/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuButton
{
public:
    QLabel *label;

    void setupUi(QWidget *MenuButton)
    {
        if (MenuButton->objectName().isEmpty())
            MenuButton->setObjectName(QString::fromUtf8("MenuButton"));
        MenuButton->resize(421, 347);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MenuButton->sizePolicy().hasHeightForWidth());
        MenuButton->setSizePolicy(sizePolicy);
        label = new QLabel(MenuButton);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 300, 100));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        retranslateUi(MenuButton);

        QMetaObject::connectSlotsByName(MenuButton);
    } // setupUi

    void retranslateUi(QWidget *MenuButton)
    {
        MenuButton->setWindowTitle(QApplication::translate("MenuButton", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MenuButton", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuButton: public Ui_MenuButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
