#!/bin/bash
if [ $# -eq 1 ]; then
    cd /home/simp1e/windows/d/code/leetcode
    git add .
    git commit -m "$1"
    git push origin master
else
    echo $#
    echo "usage: $0 <msg>"
    exit
fi
