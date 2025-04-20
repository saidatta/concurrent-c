# Concurrency Topics Specification

This document outlines the core concurrency concepts to be covered in this project, focusing on C programming for low-level OS internals understanding.

## Core Topics

*   **Threads:**
    *   Creation and termination (e.g., `pthread_create`, `pthread_join`)
    *   Thread lifecycle management
    *   Thread-specific data
*   **Mutexes (Mutual Exclusion Locks):**
    *   Initialization, locking, unlocking, destruction (e.g., `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`)
    *   Deadlock concepts and avoidance strategies
    *   Recursive mutexes
*   **Semaphores:**
    *   Initialization, wait (decrement), post (increment), destruction (e.g., `sem_init`, `sem_wait`, `sem_post`, `sem_destroy`)
    *   Counting vs. Binary semaphores
    *   Producer-Consumer problem patterns
*   **Condition Variables:**
    *   Initialization, waiting, signaling, broadcasting, destruction (e.g., `pthread_cond_init`, `pthread_cond_wait`, `pthread_cond_signal`, `pthread_cond_broadcast`, `pthread_cond_destroy`)
    *   Usage with mutexes for guarded waits
    *   Spurious wakeups
*   **Atomic Operations:**
    *   Using C11 `<stdatomic.h>` or compiler intrinsics (e.g., GCC's `__atomic_*` builtins)
    *   Compare-and-Swap (CAS)
    *   Fetch-and-Add, Fetch-and-Sub, etc.
    *   Memory ordering guarantees (e.g., `memory_order_relaxed`, `memory_order_acquire`, `memory_order_release`, `memory_order_seq_cst`)
*   **Reader-Writer Locks:**
    *   Allowing concurrent reads but exclusive writes (e.g., `pthread_rwlock_init`, `pthread_rwlock_rdlock`, `pthread_rwlock_wrlock`, `pthread_rwlock_unlock`, `pthread_rwlock_destroy`)
*   **Memory Barriers / Fences:**
    *   Ensuring memory visibility across threads/cores (compiler barriers vs. hardware fences)

## Inter-Process Communication (IPC) Mechanisms

*   **Pipes:**
    *   Unnamed pipes (`pipe()`) for related processes
    *   Named pipes (FIFOs - `mkfifo()`) for unrelated processes
*   **Shared Memory:**
    *   System V (`shmget`, `shmat`, `shmdt`, `shmctl`)
    *   POSIX (`shm_open`, `ftruncate`, `mmap`, `munmap`, `shm_unlink`)
    *   Synchronization requirements when using shared memory
*   **Message Queues:**
    *   System V (`msgget`, `msgsnd`, `msgrcv`, `msgctl`)
    *   POSIX (`mq_open`, `mq_send`, `mq_receive`, `mq_close`, `mq_unlink`)