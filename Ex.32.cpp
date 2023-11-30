#include <stdio.h>

#define FRAME_SIZE 3
#define PAGE_REFERENCE_SEQUENCE_SIZE 10

int findLRU(int time[], int n) {
    int min = time[0], minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int main() {
    int frames[FRAME_SIZE];
    int pageReferenceSequence[PAGE_REFERENCE_SEQUENCE_SIZE] = {0, 1, 2, 3, 2, 4, 5, 3, 4, 1};
    int pageFaults = 0;
    int time[FRAME_SIZE] = {0};

    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < PAGE_REFERENCE_SEQUENCE_SIZE; i++) {
        int currentPage = pageReferenceSequence[i];
        int pageFound = 0;
        
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                time[j] = i;
                break;
            }
        }

        if (!pageFound) {
            int lruIndex = findLRU(time, FRAME_SIZE);
            frames[lruIndex] = currentPage;
            time[lruIndex] = i;
            pageFaults++;

            printf("Page %d caused a page fault. Frames: ", currentPage);
            for (int j = 0; j < FRAME_SIZE; j++) {
                if (frames[j] != -1) {
                    printf("%d ", frames[j]);
                }
            }
            printf("\n");
        }
    }

    printf("Total page faults: %d\n", pageFaults);

    return 0;
}
