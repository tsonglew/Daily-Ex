#!/bin/sh

C1=0
C2=0
C3=0
COUNT=0

echo "Input name: (^D to quit)"
while read NAME
do
    ALL=0
    echo "C1 grade: "
    read C1G
    C1=`expr $C1G + $C1`
    echo "C2 grade: "
    read C2G
    C2=`expr $C2G + $C2`
    echo "C3 grade: "
    read C3G
    C3=`expr $C3G + $C3`
    ALL=`expr $C1G + $C2G + $C3G`
    echo "total for $NAME: $ALL"
    COUNT=`expr $COUNT + 1`
    echo "Input name: (^D to quit)"
done
echo "average C1: `expr $C1 / $COUNT`"
echo "average C2: `expr $C2 / $COUNT`"
echo "average C3: `expr $C3 / $COUNT`"
