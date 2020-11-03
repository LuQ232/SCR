#!/bin/bash
a=1;
while [ $a -le 30 ] ; do
    a=$[a + 1]
    sleep 1s
done

echo "Test"
