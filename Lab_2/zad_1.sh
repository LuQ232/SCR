#!/bin/bash
export LC_ALL=C
FULL_DAY_NAME=$(date +"%A") # %A zwraca pełną nazwę dnia
set `date`  #wywoluje komende date, kolejne parametry 'date' są pod $1,$2,$3 itd..
DAY=$1 # pod zmienną dzień przypisuje pierwszy parametr komendy 'date'(czyli dzien)
if [ ${DAY} = 'Sat' ] || [ ${DAY} = 'Sun' ]
then
    echo "Today is $FULL_DAY_NAME. WEEKEND!"
else
    echo "Today is $FULL_DAY_NAME. WORKDAY!"
fi


exit

