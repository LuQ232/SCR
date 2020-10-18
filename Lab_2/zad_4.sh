#!/bin/bash

help() { echo "Help: $0 [-m <maska nazwy pliku>] [-n <liczba N dni>] [-a <nazwa archiwum>]"; exit 1;}

DATE_IN_DAYS=""
NAME=""
TAR_NAME=""


while getopts ":m:n:a:" opt
do
	case "${opt}" in
		
		m) NAME="$OPTARG";;
		n) DATE_IN_DAYS=$OPTARG;;
		a) TAR_NAME=$OPTARG;;
		*) help;;
	esac
done

if [[ "" == $NAME ]]; then echo "Podaj maske nazwy pliku: "; read NAME; fi
if [[ "" == $DATE_IN_DAYS ]]; then echo "Podaj liczbe n dni: "; read DATE_IN_DAYS; fi
if [[ "" == $TAR_NAME ]]; then echo "Podaj nazwe archiwum: "; read TAR_NAME; fi			
find . -type f -mtime -$DATE_IN_DAYS -name "$NAME" | xargs tar  -czf $TAR_NAME.tar.gz




