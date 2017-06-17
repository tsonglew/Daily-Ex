#!/bin/sh

PATHPR=$1
FC=0
DC=0
for FILE in `ls $PATHPR`
do
    if [ -d ${PATHPR}/${FILE} ]
    then
        echo "(dir)$FILE"
        DC=`expr $DC + 1`
    else
        echo "$FILE"
        FC=`expr $FC + 1`
    fi
done
echo "Directory: $DC, Files: $FC"
