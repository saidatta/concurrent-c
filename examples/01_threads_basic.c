#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> // For exit()

// Function to be executed by the new thread
void* thread_function(void* arg) {
    // arg can be ignored or used as needed
    (void)arg; // Suppress unused parameter warning

    printf("Thread: Hello!\n");
    sleep(1); // Simulate some work
    printf("Thread: Exiting.\n");
    return NULL;
}

int main() {
    pthread_t tid; // Thread ID

    printf("Main: Starting.\n");

    // Create a new thread
    if (pthread_create(&tid, NULL, thread_function, NULL) != 0) {
        perror("pthread_create failed");
        exit(EXIT_FAILURE);
    }

    printf("Main: Created thread.\n");

    // Wait for the thread to finish
    if (pthread_join(tid, NULL) != 0) {
        perror("pthread_join failed");
        // Depending on the error, might not need to exit, but for simplicity:
        exit(EXIT_FAILURE);
    }

    printf("Main: Joined thread. Exiting.\n");

    return 0;
}