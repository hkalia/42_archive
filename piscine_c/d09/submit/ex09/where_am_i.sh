#!/bin/sh

var=$(ifconfig | grep "inet " | cut -d' ' -f2)
if test -z "$var"
then
	echo "Je suis perdu!\n"
else
	echo $var | tr ' ' '\n'
fi
