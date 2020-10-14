#!/bin/bash
LC_ALL=C
full_day_name=$(date +"%A") # %A zwraca pełną nazwę dnia
set `date`  #wywoluje komende date, kolejne parametry 'date' są pod $1,$2,$3 itd..
DZIEN=$1 # pod zmienną dzień przypisuje pierwszy parametr komendy 'date'(czyli dzien)

if [ ${DZIEN} = 'sob,' ] || [ ${DZIEN} = 'nie,' ]
then
    echo "Dzis jest $full_day_name. WEEKEND!"
else
    echo "Dzis jest $full_day_name. DZIEN ROBOCZY!"
fi


exit

