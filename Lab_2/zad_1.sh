#!/bin/bash
export LC_ALL=C
full_day_name=$(date +"%A") # %A zwraca pełną nazwę dnia
set `date`  #wywoluje komende date, kolejne parametry 'date' są pod $1,$2,$3 itd..
DZIEN=$1 # pod zmienną dzień przypisuje pierwszy parametr komendy 'date'(czyli dzien)
if [ ${DZIEN} = 'Sat' ] || [ ${DZIEN} = 'Sun' ]
then
    echo "Today is $full_day_name. WEEKEND!"
else
    echo "Today is $full_day_name. WORKDAY!"
fi


exit

