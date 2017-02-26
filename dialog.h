#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QtCore>
#include<QtGui>
#include<QLineF>
#include"mysquare.h"
#include "mygroup.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    MyGroup *group;
    //MyGroup *group2;
    MySquare *square;
    MySquare *square2;

};

#endif // DIALOG_H
