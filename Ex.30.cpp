#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    printf("Inside the new thread\n");
    sleep(3);
    pthread_exit(NULL);
}

int main() {
    pthread_t my_thread;
    int ret;
    ret = pthread_create(&my_thread, NULL, thread_function, NULL);
    if (ret != 0) {
        perror("pthread_create");
        return 1;
    }

    ret = pthread_join(my_thread, NULL);
    if (ret != 0) {
        perror("pthread_join");
        return 1;
    }

    pthread_t main_thread = pthread_self();
    if (pthread_equal(main_thread, my_thread)) {
        printf("Main thread and new thread are equal\n");
    } else {
        printf("Main thread and new thread are not equal\n");
    }

    pthread_exit(NULL);

    return 0;
}

