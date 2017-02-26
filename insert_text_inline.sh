#!/bin/bash

match='INCLUDEPATH += .'
insert='QT += widgets'
file='test.pro'

sed -i "/$match/a $insert" $file
