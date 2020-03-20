# Pentru o listă de directoare date ca parametri (și din subdirectoarele
# acestora) să se șteargă toate fișierele al căror nume sunt date în fișierul
# dat ca prim parametru.

cat $1 | while read line
do
    for var in "$@"
    do
        if [ "$1" == "$var" ]; # skip first arg, see below explanation
        then
            continue
        fi
        find $var -type f -name $line | xargs rm 2> /dev/null # to avoid noise
    done
done

# My approach doesn't take into account when first arg is named like one of
# the files. I couldn't find a way to iterate starting from the second arg
# Tried evaluating arg using integer like so:
# n = 2
# echo "${$n}" # or echo "${!n}"
# HELP!
