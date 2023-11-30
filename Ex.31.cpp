#include <stdio.h>

#define FRAME_SIZE 3
#define PAGE_REFERENCE_SEQUENCE_SIZE 10

int main() {
    int frames[FRAME_SIZE];
    int pageReferenceSequence[PAGE_REFERENCE_SEQUENCE_SIZE] = {0, 1, 2, 3, 2, 4, 5, 3, 4, 1};
    int pageFaults = 0;
    int currentIndex = 0;

    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i] = -1; 
    }

    for (int i = 0; i < PAGE_REFERENCE_SEQUENCE_SIZE; i++) {
        int currentPage = pageReferenceSequence[i];
        int pageFound = 0;

        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            frames[currentIndex] = currentPage;
            currentIndex = (currentIndex + 1) % FRAME_SIZE;
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
