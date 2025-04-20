#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For sleep

// Define a simple struct to hold thread data
typedef struct {
    int id;
    const char* message;
} ThreadData;

// Function executed by the thread
void* thread_function(void* arg) {
    // Cast the void* argument back to the ThreadData struct pointer
    ThreadData* data = (ThreadData*)arg;

    printf("Thread %d: Received message - '%s'\n", data->id, data->message);
    fflush(stdout);

    // Simulate some work

    // Allocate memory for the return message
    size_t buffer_size = 50;
    char* return_message = malloc(buffer_size);
    if (return_message == NULL) {
        perror("malloc failed in thread");
        return NULL; // Return NULL on allocation failure
    }

    // Safely format the return message
    int written = snprintf(return_message, buffer_size, "Result from thread %d", data->id);

    // Check for snprintf errors or truncation
    if (written < 0 || written >= (int)buffer_size) {
        fprintf(stderr, "Thread %d: snprintf error or truncation (written=%d, size=%zu)\n", data->id, written, buffer_size);
        free(return_message); // Free allocated memory before returning NULL
        return NULL;
    }

    printf("Thread %d: Exiting and returning result: '%s'\n", data->id, return_message);
    fflush(stdout);

    // Return the pointer to the newly allocated and formatted string
    return (void*)return_message;
}

int main() {
    pthread_t tid;          // Thread ID
    ThreadData thread_arg;  // Struct to pass arguments
    void* thread_return_value; // Pointer to hold the return value

    // Initialize the argument struct
    thread_arg.id = 1;
    thread_arg.message = "Hello from Main!";

    printf("Main: Starting.\n");
    fflush(stdout);

    // Create the thread, passing the address of the argument struct
    if (pthread_create(&tid, NULL, thread_function, &thread_arg) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    printf("Main: Created thread, passing ID %d and message '%s'.\n", thread_arg.id, thread_arg.message);
    fflush(stdout);

    // Wait for the thread to finish and get its return value
    if (pthread_join(tid, &thread_return_value) != 0) {
        perror("pthread_join failed");
        // Even if join fails, try to free if return value was potentially set
        if (thread_return_value != NULL) {
            free(thread_return_value);
        }
        return 1;
    }

    printf("Main: Joined thread.\n");
    fflush(stdout);

    // Check if the thread returned a valid value
    if (thread_return_value != NULL) {
        // Cast the void* return value back to char*
        printf("Main: Thread returned: '%s'\n", (char*)thread_return_value);
        fflush(stdout);

        // Free the memory allocated by the thread
        free(thread_return_value);
        printf("Main: Freed memory returned by thread.\n");
        fflush(stdout);
    } else {
        printf("Main: Thread returned NULL (possibly due to an error).\n");
        fflush(stdout);
    }

    printf("Main: Exiting.\n");
    fflush(stdout);
    return 0;
}