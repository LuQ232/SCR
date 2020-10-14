#!/bin/bash

NAME=$1
DATE_IN_DAYS=$2
TAR_NAME=$3


find ~/Pulpit -name "$NAME" -mtime -"$DATE_IN_DAYS" | tar -cvf  "$TAR_NAME".tar.gz -T -
exit


