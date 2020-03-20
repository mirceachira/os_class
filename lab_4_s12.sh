# Să se înlocuiască într-un fișier text toate aparițiile unor numere formate
# dintr-o singură cifră astfel: numărul format din cifra 1 se va locui cu
# cuvântul 'un', numărul 2 cu cuvântul 'doi', etc. Numerele din 2 sau mai
# multe cifre nu se schimbă (de ex. 11).
sed -r '
    s/(^|[^0-9])1([^0-9]|$)/\1un\2/g
    s/(^|[^0-9])1([^0-9]|$)/\1un\2/g
    s/(^|[^0-9])2([^0-9]|$)/\1doi\2/g
    s/(^|[^0-9])2([^0-9]|$)/\1doi\2/g
    s/(^|[^0-9])3([^0-9]|$)/\1trei\2/g
    s/(^|[^0-9])3([^0-9]|$)/\1trei\2/g
    s/(^|[^0-9])4([^0-9]|$)/\1patru\2/g
    s/(^|[^0-9])4([^0-9]|$)/\1patru\2/g
    s/(^|[^0-9])5([^0-9]|$)/\1cinci\2/g
    s/(^|[^0-9])5([^0-9]|$)/\1cinci\2/g
    s/(^|[^0-9])6([^0-9]|$)/\1sase\2/g
    s/(^|[^0-9])6([^0-9]|$)/\1sase\2/g
    s/(^|[^0-9])7([^0-9]|$)/\1sapte\2/g
    s/(^|[^0-9])7([^0-9]|$)/\1sapte\2/g
    s/(^|[^0-9])8([^0-9]|$)/\1opt\2/g
    s/(^|[^0-9])8([^0-9]|$)/\1opt\2/g
    s/(^|[^0-9])9([^0-9]|$)/\1noua\2/g
    s/(^|[^0-9])9([^0-9]|$)/\1noua\2/g
    ' $1

# Breakdown:
#   (^|[^0-9]) - beggining or nondigit character
#   ([^0-9]|$) - nondigit character or end
#   \1 and \2  - replace with previously matched group