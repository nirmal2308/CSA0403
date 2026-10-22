
#include <stdio.h>
#include <pthread.h>
void *thread_func(void *arg) { 
    printf("Inside the newly created thread.\n");
    pthread_exit(NULL); 
}
int main() {
    pthread_t t1, t2;
    int choice;
    printf("Enter 1 to run thread operations: ");
    scanf("%d", &choice);
    if(choice == 1) {
        pthread_create(&t1, NULL, thread_func, NULL);
        t2 = t1;
        if(pthread_equal(t1, t2)) printf("Threads t1 and t2 are equal.\n");
        pthread_join(t1, NULL);
        printf("Thread joined successfully.\n");
    }
    return 0;
}
