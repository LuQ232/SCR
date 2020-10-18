#!/bin/sh

Passwd="Zdamscr1"
Mail="bednarek_zda_scr@onet.pl"
Title="tytul"

set `wc -l adresy.txt | cat adresy.txt`

K=1; 
echo $
while [ $K -le $# ] ; do

    sendEmail -f $Mail -t `sed -n ${K}p adresy.txt` -a `find -name "spec*.pdf"` -u "`echo $Title`" -m "` cat tresc.txt`" -s smtp.poczta.onet.pl:25 -xu $Mail -xp `echo $Passwd`
K=$(($K + 1))
done

exit
