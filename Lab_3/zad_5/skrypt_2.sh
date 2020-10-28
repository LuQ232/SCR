#!/bin/bash
a=1;
trap "echo przechwycone sygnaly:" {1..15} 
while [ $a -le 20 ] ; do
    a=$[a + 1]
    date | awk '{print $5}'
    sleep 1s
done
