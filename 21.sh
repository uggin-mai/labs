#!/usr/bin/env bash
function CaesarCipher {
    cat $file | tr "[A-Za-z]" "[D-ZA-Cd-za-c]" > $file
    #printf "ok"
}
shopt -s globstar

#read input
#echo $1
if [ -z $1 ]
then
    read -p "Введите каталог для кодирования:" dir
elif [ $1 = "?" ]
then
    printf "CaesarCipher, использование - ./CS.sh [каталог для кодирования]\n"
    exit 0
else
    dir=$1
fi
#read -p "Введите каталог для кодирования:" dir

for file in ./$dir/**/* #input
do
    if [ -f "$file" ];
    then
        CaesarCipher "$file"
    fi
done