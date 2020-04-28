#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int fd1, fd2, fd3;
    char * myfifo1 = "/tmp/myfifo1";
    char * myfifo2 = "/tmp/myfifo2";
    char * myfifo3 = "/tmp/myfifo3";

    int pid1, pid2, pid3;
    pid1 = fork();
    if (pid1 == 0) pid2 = fork();
    if (pid1 == 0 && pid2 == 0) pid3 = fork();

    if (pid1 == 0 && pid2 == 0 && pid3 == 0) {
        mkfifo(myfifo1, 0666);
        mkfifo(myfifo2, 0666);
        mkfifo(myfifo3, 0666);
        while (1) {

            char str[30];

            printf("Enter a line :");
            fgets(str, 30, stdin);

            printf("You entered: ");
            puts(str);

            if (('a' <= str[0] && str[0] <= 'z') || ('A' <= str[0] && str[0] <= 'Z')) {
                fd1 = open(myfifo1, O_WRONLY);
                write(fd1, &str, strlen(str)+1);
                close(fd1);
            } else if ('0' <= str[0] && str[0] <= '9') {
                fd2 = open(myfifo2, O_WRONLY);
                write(fd2, &str, 30);
                close(fd2);
            } else {
                fd3 = open(myfifo3, O_WRONLY);
                write(fd3, &str, 30);
                close(fd3);
            }       
        }

        return 0;
    }

    while (1) {
        mkfifo(myfifo1, 0666);
        mkfifo(myfifo2, 0666);
        mkfifo(myfifo3, 0666);

        char receivedArr[30];
        int ln;

        if (pid1 != 0) {
            ln = 1;
            fd1 = open(myfifo3, O_RDONLY);
            read(fd1, &receivedArr, 30);
            close(fd3);
        } else if (pid2 != 0) {
            ln = 2;
            fd2 = open(myfifo2, O_RDONLY);
            read(fd2, &receivedArr, 30);
            close(fd2);
        } else {
            ln = 3;
            fd3 = open(myfifo3, O_RDONLY);
            read(fd3, &receivedArr, 30);
            close(fd3);        
        }

        printf("received in child process %d the line: %s\n", ln, receivedArr);
    }
}