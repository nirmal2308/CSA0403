
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t empty, full;
int items;
void* producer(void* arg) {
    for(int i=0; i<items; i++) { sem_wait(&empty); printf("Produced item %d\n", i+1); sem_post(&full); }
    return NULL;
}
void* consumer(void* arg) {
    for(int i=0; i<items; i++) { sem_wait(&full); printf("Consumed item %d\n", i+1); sem_post(&empty); }
    return NULL;
}
int main() {
    printf("Enter number of items to produce/consume: ");
    scanf("%d", &items);
    pthread_t pt, ct;
    sem_init(&empty, 0, items); sem_init(&full, 0, 0);
    pthread_create(&pt, NULL, producer, NULL);
    pthread_create(&ct, NULL, consumer, NULL);
    pthread_join(pt, NULL); pthread_join(ct, NULL);
    return 0;
}
