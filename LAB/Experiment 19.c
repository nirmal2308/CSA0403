
#include <stdio.h>
#include <pthread.h>
pthread_mutex_t lock; int counter = 0;
int limit;
void *inc(void *arg) {
    int id = *((int*)arg);
    for(int i=0; i<limit; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        printf("Thread %d incremented counter to: %d\n", id, counter);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
int main() {
    printf("Enter limit per thread: ");
    scanf("%d", &limit);
    pthread_t t1, t2; int id1=1, id2=2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1, NULL, inc, &id1); pthread_create(&t2, NULL, inc, &id2);
    pthread_join(t1, NULL); pthread_join(t2, NULL);
    printf("Final counter value: %d\n", counter);
    return 0;
}
