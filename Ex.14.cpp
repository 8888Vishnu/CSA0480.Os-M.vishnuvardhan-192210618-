#include <stdio.h>
#include <string.h>

#define MAX_FILES 100

struct file {
    char name[20];
    int size;
    int created_time;
};

int main() {
    int n, i, ch, created_time;
    struct file files[MAX_FILES];
    n = 0;

    printf("Enter the number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter file name:");
        scanf("%s",&files[i].name);
        printf("Enter file size:");
        scanf("%d", &files[i].size);
        printf("Enter file creation time (YYYY-MM-DD):");
        scanf("%d", &files[i].created_time);
       
    }

    printf("\n");

    do {
        printf("1. Display all files\n");
        printf("2. Search for a file\n");
        printf("3. Create a new file\n");
        printf("4. Delete a file\n");
        printf("5. Exit\n");

        scanf("%d", &ch);

        switch (ch) {
        case 1:
            for (i = 0; i < n; i++) {
                printf("file name: %s \nfile size: %d \nfile created_time: %d \n",files[i].name, files[i].size, files[i].created_time);
            }
            break;
        case 2:
            printf("Enter file name to search: ");
            scanf("%s", files[0].name);
            for (i = 0; i < n; i++) {
                if (strcmp(files[i].name, files[0].name) == 0) {
                    printf("File found: %s\n", files[i].name);
                    break;
                }
            }
            if (i == n) {
                printf("File not found\n");
            }
            break;
        case 3:
            printf("Enter new file name:\n ");
            scanf("%s", files[n].name);
            printf("Enter new file size:\n ");
            scanf("%d", &files[n].size);
            printf("Enter new file creation time (YYYY-MM-DD):\n");
            scanf("%d-%m-%d", &files[n].created_time);
            n++;
            break;
        case 4:
            printf("Enter file name to delete: ");
            scanf("%s", files[0].name);
            for (i = 0; i < n; i++) {
                if (strcmp(files[i].name, files[0].name) == 0) {
                    for (int j = i; j < n - 1; j++) {
                        files[j] = files[j + 1];
                    }
                    n--;
                    break;
                }
            }
            if (i == n) {
                printf("File not found\n");
            }
            break;
        default:
            break;
        }
    } while (ch != 5);

    return 0;
}
