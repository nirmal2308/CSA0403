
#include <stdio.h>
#include <pthread.h>
void *myThreadFun(void *vargp) {
    int id = *((int *)vargp);
    printf("Printing from Thread %d\n", id);
    return NULL;
}
int main() {
    pthread_t threads[2];
    int thread_args[2], n;
    printf("Enter number of threads to create: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        thread_args[i] = i+1;
        pthread_create(&threads[i], NULL, myThreadFun, &thread_args[i]);
    }
    for(int i=0; i<n; i++) pthread_join(threads[i], NULL);
    printf("All threads finished.\n");
    return 0;
}
