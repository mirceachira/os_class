#!/bin/bash
#Să se afișeze dintr-o listă de fișiere numele acelui fișier care are număr maxim de cuvinte și numărul cuvintelor.

i=0;
fname="";
for var in "$@"   
do
	nr_words=$(awk '$0=NF' $var | awk '{s+=$1}END{print int(s)}');
	if [ "$nr_words" > "$i" ]
	then
		i=$nr_words;
		fname=$var
	fi
done
echo "Biggest file is $fname with a total of $i words!";


