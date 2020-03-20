# Read a number from standard input and check if it is prime
read n 
i=2
  
while test $i -le `expr $n / 2`
do  
	if test `expr $n % $i` -eq 0  
	then
		echo "$n is NOT prime"
		exit 0
	fi
	
	i=`expr $i + 1` 
done

echo "$n is prime"
