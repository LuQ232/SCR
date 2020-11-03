#!/bin/bash
a=1;
while [ $a -le 20 ] ; do
    a=$[a + 1]
    sleep 1s
    ./skrypt_1.sh &
done

echo "Test"
