#!/bin/bash
#Să se afișeze pentru fiecare fișier: numele acestuia, și numărul mediu de cuvinte per linie per fișier (media numărului de cuvinte pentru liniile fișierului). Se va afișa și media numărului de cuvinte pentru toate fișierele luate la un loc.

i=0;
for var in "$@"   
do
	avg_words=$(awk '$0=NF' $var | awk '{s+=$1}END{print int(s/NR)}'); # I can't do float division here hence the number is rounded, HELP!
	echo "$var has $avg_words average words per line";
	i=$(($i+$avg_words))
done
echo "There are $(($i/$#)) average words!";


