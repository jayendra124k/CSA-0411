#include <stdio.h>

int main() {
    int bSize[10], pSize[10], bNo, pNo;
    int alloc[10];
    
    printf("Enter number of blocks: ");
    scanf("%d", &bNo);
    printf("Enter size of each block:\n");
    for(int i = 0; i < bNo; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &bSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &pNo);
    printf("Enter size of each process:\n");
    for(int i = 0; i < pNo; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &pSize[i]);
        alloc[i] = -1; // initially not allocated
    }

    // First Fit Allocation
    for(int i = 0; i < pNo; i++) {
        for(int j = 0; j < bNo; j++) {
            if(bSize[j] >= pSize[i]) {
                alloc[i] = j;
                bSize[j] -= pSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i = 0; i < pNo; i++) {
        printf("%d\t\t%d\t\t", i + 1, pSize[i]);
        if(alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

