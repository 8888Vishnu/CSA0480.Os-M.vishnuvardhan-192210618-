#include <stdio.h>
#include <limits.h>

#define FRAME_SIZE 3
#define PAGE_REFERENCE_SEQUENCE_SIZE 10

int findOptimal(int pages[], int n, int startIdx, int frame[]) {
    int res = -1, farthest = startIdx;
    for (int i = 0; i < FRAME_SIZE; i++) {
        int j;
        for (j = startIdx; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (res == -1) ? 0 : res;
}

int main() {
    int pages[PAGE_REFERENCE_SEQUENCE_SIZE] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int frame[FRAME_SIZE];
    int pageFaults = 0;

    for (int i = 0; i < FRAME_SIZE; i++) {
        frame[i] = -1; // Initialize frames as empty
    }

    for (int i = 0; i < PAGE_REFERENCE_SEQUENCE_SIZE; i++) {
        int currentPage = pages[i];
        int pageFound = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frame[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            int idx = findOptimal(pages, PAGE_REFERENCE_SEQUENCE_SIZE, i + 1, frame);
            frame[idx] = currentPage;
            pageFaults++;

            printf("Page %d caused a page fault. Frames: ", currentPage);
            for (int j = 0; j < FRAME_SIZE; j++) {
                if (frame[j] != -1) {
                    printf("%d ", frame[j]);
                }
            }
            printf("\n");
        }
    }

    printf("Total page faults: %d\n", pageFaults);

    return 0;
}
