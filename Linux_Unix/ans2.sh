#!/bin/sh

# 编写一shell程序, 判断指定目录下所有文件类型，显示目录与文件项，并统计目录与文件数。

DIR_COUNT=0
NOR_COUNT=0

for file in `ls`
do
    if [ -d $file ]
    then
        DIR_COUNT=`expr $DIR_COUNT + 1`
        echo "(dir)$file"
    else
        NOR_COUNT=`expr $NOR_COUNT + 1`
        echo "$file"
    fi
done
echo "Total:  $DIR_COUNT directories, $NOR_COUNT files!"
