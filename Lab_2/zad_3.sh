#!/bin/bash

NAME=$1
DATE_IN_DAYS=$2
TAR_NAME=$3


find . -type f -mtime -"$DATE_IN_DAYS" -name "$NAME"  | xargs tar -czf  "$TAR_NAME".tar.gz 
exit


