#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int main() {
    int requests[MAX_REQUESTS];
    int numRequests;
    int headPosition;
    int direction;
    int totalSeekTime = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);

    printf("Enter the disk requests:\n");
    for (int i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &headPosition);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    for (int i = 0; i < numRequests - 1; i++) {
        for (int j = 0; j < numRequests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    printf("Disk Scheduling Order:\n");
    if (direction == 1) { 
        for (int i = headPosition; i <= 199; i++) {
            for (int j = 0; j < numRequests; j++) {
                if (requests[j] == i) {
                    totalSeekTime += abs(headPosition - requests[j]);
                    headPosition = requests[j];
                    printf("%d ", headPosition);
                }
            }
        }
        totalSeekTime += abs(headPosition - 199);
        headPosition = 199;
        printf("%d ", headPosition);
    } else { 
        for (int i = headPosition; i >= 0; i--) {
            for (int j = numRequests - 1; j >= 0; j--) {
                if (requests[j] == i) {
                    totalSeekTime += abs(headPosition - requests[j]);
                    headPosition = requests[j];
                    printf("%d ", headPosition);
                }
            }
        }
        totalSeekTime += abs(headPosition - 0);
        headPosition = 0;
        printf("%d ", headPosition);
    }

    printf("\nTotal Seek Time: %d\n", totalSeekTime);

    return 0;
}
