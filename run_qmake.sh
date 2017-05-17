#!/bin/bash
qmake -qt=qt5 -project -o test.pro
match='INCLUDEPATH += .'
insert='QT += widgets\nQT += svg'
file='test.pro'

sed -i "/$match/a $insert" $file

#./insert_text_inline.sh
qmake -qt=qt5 test.pro
make
# awk '/QT/{ print NR }' test.pro
