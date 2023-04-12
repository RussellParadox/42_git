#!/bin/bash

line_qt=$(wc -l $1 | cut -d ' ' -f 1)
word_qt=$(head -n 1 $1 | tail -n 1 | wc -w | cut -d ' ' -f 1)
echo $word_qt
#for (( i=1; i<=$line_qt; i++ )); do
#	
#done
