// Sa se afiseze la iesirea standard continutul unui fiser text adaugand cate o linie goala dupa fiecare linie de text. Nu se vor face presupuneri referitoate la lungimea maxima a unei linii. Numele fisierului se va transmite programului ca si parametru in linia de comanda.
#include <stdio.h>
#include <stdlib.h>

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
        printf("%s\n", line);
    }

    fclose(fp);

    return 0;
}