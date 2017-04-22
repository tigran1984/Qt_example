#ifndef DIALOG_H
#define DIALOG_H

#include<iostream>
#include<QDebug>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include<QTimer>
#include<QHBoxLayout>
#include<QGraphicsView>
#include<QPushButton>
#include <QDialog>
#include<QtCore>
#include<QtGui>
#include<QLineF>
#include"mysquare.h"
#include "mygroup.h"
#include"arrow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void firstPage();
    void partnersPage();
    void setFirstPage();
    void setPartnersPage();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    MyGroup *group;
    //MyGroup *group2;
    MySquare *square;
    MySquare *square2;
    QParallelAnimationGroup * groupAnim_1;
    QParallelAnimationGroup * groupAnim_2;

};

#endif // DIALOG_H
