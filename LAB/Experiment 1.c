
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child Process: PID=%d, Parent PID=%d\n", getpid(), getppid());
    } else if (pid > 0) {
        wait(NULL);
        printf("Parent Process: PID=%d, Child PID=%d\n", getpid(), pid);
    }
    return 0;
}
