// Se dă un șir de numere x1, x2, ..., xn. Să se calculeze sumele parțiale x1, x1+x2, x1+x2+x3, ..., x1+x2+...+xn, folosind câte un proces pentru fiecare sumă parțială.
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

 
int main()
{
    int arr[100] = {1,2,3,4,5,6,7,8,9,10};
    int len = 10;

    printf("The array is: ");
    for (int i=0; i<len; i++) {
        printf("%d", arr[i]);
        if (i != len-1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }

    for (int i=1; i<len; i++) {
        int id = fork();
        if (id > 0) {
            int s = 0;
            for (int j=i-1; j>=0; j--) {
                s += arr[j];
                printf("%d", arr[j]);
                if (j != 0) {
                    printf(" + ");
                }
                else {
                    printf(" = ");
                }
                
            }
            printf("%d\t<--- pid : %d\n", s, getpid());
            return 0;
        } 
    }

    return 0;
}