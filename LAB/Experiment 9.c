
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main() {
    int shmid = shmget(IPC_PRIVATE, 1024, 0666|IPC_CREAT);
    char *str = (char*) shmat(shmid, (void*)0, 0);
    char input[100];
    printf("Enter data to write to shared memory: ");
    scanf(" %[^\n]", input);
    strcpy(str, input);
    printf("Data written to shared memory: %s\n", str);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
