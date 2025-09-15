#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;   // semaphores
int read_count = 0; // number of active readers
int shared_data = 0; // the shared resource

void *reader(void *arg) {
    int id = *((int *)arg);

    sem_wait(&mutex);
    read_count++;
    if (read_count == 1) {
        sem_wait(&wrt);  // first reader locks writers
    }
    sem_post(&mutex);

    // Critical Section (reading)
    printf("Reader %d: read shared_data = %d\n", id, shared_data);
    sleep(1);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0) {
        sem_post(&wrt); // last reader unlocks writers
    }
    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg) {
    int id = *((int *)arg);

    sem_wait(&wrt);

    // Critical Section (writing)
    shared_data += 10;
    printf("Writer %d: wrote shared_data = %d\n", id, shared_data);
    sleep(1);

    sem_post(&wrt);

    return NULL;
}

int main() {
    pthread_t r[5], w[2];
    int id[5] = {1, 2, 3, 4, 5};

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create writers
    for (int i = 0; i < 2; i++) {
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    // Create readers
    for (int i = 0; i < 5; i++) {
        pthread_create(&r[i], NULL, reader, &id[i]);
    }

    // Wait for writers
    for (int i = 0; i < 2; i++) {
        pthread_join(w[i], NULL);
    }

    // Wait for readers
    for (int i = 0; i < 5; i++) {
        pthread_join(r[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
