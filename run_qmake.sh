#!/bin/bash
qmake -project -o test.pro
match='INCLUDEPATH += .'
insert='QT += widgets\nQT += svg'
file='test.pro'

sed -i "/$match/a $insert" $file

#./insert_text_inline.sh
qmake test.pro
make
# awk '/QT/{ print NR }' test.pro
