// Sa se numere cuvintele fiecarei linii dintr-un fisier. Nu se vor face presupuneri referitoare la lungimea maxima a unei linii.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int countWords(char str[]) {
    int i, words;

    words = 1;
    for (int i=0; i<strlen(str); i++) {
        if(str[i]==' ' || str[i]=='\t') {
            words++;
        }
    }

    return words;
}


int main( int argc, char *argv[] )  {
   if( argc != 2 ) {
      return -1;
   }

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;

    fp = fopen(argv[1], "r");

    while ((read = getline(&line, &len, fp)) != -1) {
        int e = countWords(line);
        printf("There are %d words on line: %s", e, line);
    }

    fclose(fp);

    return 0;
}