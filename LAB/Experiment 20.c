
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t wrt; pthread_mutex_t mutex; int readcount = 0;
int n_ops;
void *writer(void *wno) {
    sem_wait(&wrt);
    printf("Writer %d modified data\n", *((int*)wno));
    sem_post(&wrt); return NULL;
}
void *reader(void *rno) {
    pthread_mutex_lock(&mutex);
    readcount++;
    if(readcount == 1) sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);
    printf("Reader %d reading data\n", *((int*)rno));
    pthread_mutex_lock(&mutex);
    readcount--;
    if(readcount == 0) sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
    return NULL;
}
int main() {
    printf("Enter number of operations: ");
    scanf("%d", &n_ops);
    pthread_t r[10], w[10]; int a[10];
    pthread_mutex_init(&mutex, NULL); sem_init(&wrt, 0, 1);
    for(int i=0; i<n_ops; i++) {
        a[i] = i+1;
        pthread_create(&w[i], NULL, writer, &a[i]);
        pthread_create(&r[i], NULL, reader, &a[i]);
    }
    for(int i=0; i<n_ops; i++) { pthread_join(w[i], NULL); pthread_join(r[i], NULL); }
    return 0;
}
