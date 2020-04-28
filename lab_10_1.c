#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    char str[30];

    printf("Enter a value :");
    fgets(str, 30, stdin);

    printf("You entered: ");
    puts(str);


    // Create the first process
	int fd1[2];  // parent to child 1 (1 - 2 from diagram)
	// create pipe descriptors
	pipe(fd1);
    int pid1 = fork();

    if (pid1 > 0) {
        char receivedArr[30];

        read(fd1[0], &receivedArr, 30);

        printf("from child process 1: %s\n", receivedArr);

        return 0;
    }

    // Create the second process
    int fd2[2];  // parent to child 2 (1 - 3 from diagram)
    pipe(fd2);
    int pid2 = fork();
    if (pid2 > 0) {
        char receivedArr[30];

        read(fd2[0], &receivedArr, 30);

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
        letters[in] = '\0';
        write(fd1[1], &numbers, 30);
        write(fd2[1], &letters, 30);
    } else {
        printf("Something went wrong when creating the processes!");
    }

    return 0;
    
	// // fork() returns 0 for child process, child-pid for parent process.
	// if (fork() != 0) {
    // 	int childID = 19;
	// 	// parent: writing only, so close read-descriptor.
	// 	close(fd[0]);

	// 	// send the childID on the write-descriptor.
	// 	childID = 129;
	// 	write(fd[1], &childID, sizeof(childID));
	// 	printf("Parent(%d) send childID: %d\n", getpid(), childID);

	// 	// close the write descriptor
	// 	close(fd[1]);
	// } else {
    //     int childID = 1;
	// 	// child: reading only, so close the write-descriptor
	// 	close(fd[1]);

	// 	// now read the data (will block until it succeeds)
	// 	read(fd[0], &childID, sizeof(childID));
	// 	printf("Child(%d) received childID: %d\n", getpid(), childID);

	// 	// close the read-descriptor
	// 	close(fd[0]);
	// }
	// return 0;
}