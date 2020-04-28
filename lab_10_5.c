#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
	int fd1[2], fd2[2], fd3[2];

	pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    int pid1, pid2, pid3;
    pid1 = fork();
    if (pid1 == 0) pid2 = fork();
    if (pid1 == 0 && pid2 == 0) pid3 = fork();

    if (pid1 == 0 && pid2 == 0 && pid3 == 0) {
        while (1) {
            char str[30];

            printf("Enter a line :");
            fgets(str, 30, stdin);

            printf("You entered: ");
            puts(str);

            char numbers[30], letters[30];
            int in=0, il=0;

            if (('a' <= str[0] && str[0] <= 'z') || ('A' <= str[0] && str[0] <= 'Z')) {
                write(fd1[1], &str, 30);
            } else if ('0' <= str[0] && str[0] <= '9') {
                write(fd2[1], &str, 30);
            } else {
                write(fd3[1], &str, 30);
            }       
        }
        return 0;
    }

    while (1) {
        char receivedArr[30];
        int ln;

        if (pid1 != 0) {
            ln = 1;
            read(fd1[0], &receivedArr, 30);
        } else if (pid2 != 0) {
            ln = 2;
            read(fd2[0], &receivedArr, 30);
        } else {
            ln = 3;
            read(fd3[0], &receivedArr, 30);
        }

        printf("received in child process %d the line: %s\n", ln, receivedArr);

    }
}