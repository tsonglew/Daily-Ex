#!/bin/bash
# 编写一shell程序,读入学生姓名与三门功课成绩，求每个学生的三门课程总分，以及所
# 有学生各门功课的的平均分。

FIR_ALL=0
SEC_ALL=0
THI_ALL=0
COUNT=0

echo "Input Student Name: (Press ^D to Stop)"
while read NAME
do
    ALL=0
    echo "Input Grades of Student $NAME"
    echo "first: "
    read FIR
    ALL=$[ALL+FIR]
    echo "second:"
    read SEC
    ALL=$[ALL+SEC]
    echo "third:"
    read THI
    ALL=$[ALL+THI]
    echo "Sum of this $NAME's grades: $ALL"

    FIR_ALL=$[FIR_ALL+FIR]
    SEC_ALL=$[SEC_ALL+SEC]
    THI_ALL=$[THI_ALL+THI]
    COUNT=$[COUNT+1]
    echo "\nInput Student Name: (Press ^D to Stop)"
done

FIR_AVG=$[FIR_ALL/COUNT]
SEC_AVG=$[SEC_ALL/COUNT]
THI_AVG=$[THI_ALL/COUNT]

echo "\nAverage of first: $FIR_AVG"
echo "Average of second: $SEC_AVG"
echo "Average of third: $THI_AVG"
