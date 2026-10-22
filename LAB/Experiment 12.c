
#include <stdio.h>
#include <pthread.h>
pthread_mutex_t chopstick[5];
void *philosopher(void *num) {
    int i = *(int *)num;
    pthread_mutex_lock(&chopstick[i]);
    pthread_mutex_lock(&chopstick[(i+1)%5]);
    printf("Philosopher %d is eating\n", i+1);
    pthread_mutex_unlock(&chopstick[i]);
    pthread_mutex_unlock(&chopstick[(i+1)%5]);
    return NULL;
}
int main() {
    pthread_t thread_id[5]; int a[5], n;
    printf("Enter number of philosophers: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) pthread_mutex_init(&chopstick[i], NULL);
    for(int i=0; i<n; i++) { a[i]=i; pthread_create(&thread_id[i], NULL, philosopher, &a[i]); }
    for(int i=0; i<n; i++) pthread_join(thread_id[i], NULL);
    return 0;
}
