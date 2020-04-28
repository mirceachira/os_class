#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 


int main(int argc, char *argv[]) {
    int fd1, fd2;

    char * myfifo1 = "/tmp/myfifo11";
    char * myfifo2 = "/tmp/myfifo22";

    char str[30];

    printf("Enter a value :");
    fgets(str, 30, stdin);

    printf("You entered: ");
    puts(str);


    int pid1 = fork();
    if (pid1 > 0) {
        char receivedArr[30];

        fd1 = open(myfifo1, O_RDONLY); 
        read(fd1, receivedArr, 30); 
        close(fd1);

        printf("from child process 1: %s\n", receivedArr);

        return 0;
    }

    int pid2 = fork();
    if (pid2 > 0) {
        char receivedArr[30];

        fd2 = open(myfifo2, O_RDONLY); 
        read(fd2, receivedArr, 30); 
        close(fd2);

        int i = 0;
        while (receivedArr[i] != '\0') {
            if ('a' <= receivedArr[i] && receivedArr[i] <= 'z') {
                receivedArr[i] -= 32;
            }
            i++;
        }

        printf("from child process 2: %s\n", receivedArr);

        return 0;
    }

    if (pid1 == 0 && pid2 == 0) {
        char numbers[30], letters[30];
        int in=0, il=0;

        int i=0;
        while (str[i] != '\0') {
            if ('0' <= str[i] && str[i] <= '9') {
                numbers[in] = str[i];
                in++;
            } else if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')) {
                letters[il] = str[i];
                il++;
            }
            i++;
        }

        numbers[in] = '\0';
        letters[il] = '\0';

        fd1 = open(myfifo1, O_WRONLY); 
        write(fd1, numbers, strlen(numbers));
        close(fd1);

        fd2 = open(myfifo2, O_WRONLY); 
        write(fd2, letters, strlen(letters));
        close(fd2);
    } else {
        printf("Something went wrong when creating the processes!");
    }

    return 0;
}