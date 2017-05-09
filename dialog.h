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
#include"mygraphicsview.h"
//#include"mygraphicsscene.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    QPropertyAnimation* posAnimation(MySquare* ptr,
            int duration,QPointF startValue,
            QPointF endValue, QEasingCurve easing);
    QPropertyAnimation* opacityAnimation(MySquare* ptr,
            int duration,qreal startValue,
            qreal endValue, QEasingCurve easing);
    QPropertyAnimation* sizeAnimation(MySquare* ptr,
            int duration,QSizeF startValue,
            QSizeF endValue, QEasingCurve easing);
    ~Dialog();
public slots:
    void firstPage();
    void partnersPage();
    void setFirstPage();
    void animateSecondPage();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    //MyGraphicsScene *scene;
    QList<MySquare *> items;
    QList<MySquare *> items2;
    QParallelAnimationGroup * groupAnim_1;
    QParallelAnimationGroup * groupAnim_2;
    QParallelAnimationGroup * groupAnim_3;

};

#endif // DIALOG_H
