#include <stdio.h>

void main() {
    int n = 20, frame = 3, frames[10];
    int pages[50] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    for(int i = 0; i < frame; i++) {
        frames[i] = -1; // -1 indicates empty frame
    }
    int j = 0, fault = 0; // j is the frame number where new page will be inserted
    printf("Ref. string         Page Frames\n");
    printf("-----------    --------------------\n");
    for(int i = 0; i < n; i++) {
        printf("\t%d\t", pages[i]); // Print the reference string
        int exist = 0; // check if the page already exist in the frames array
        for(int k = 0; k < frame; k++) {
            if(pages[i] == frames[k]) {
                exist = 1;
            }
        }
        if(!exist) {
            frames[j] = pages[i];
            j = (j + 1) % frame;
            fault++;
            for(int k = 0; k < frame; k++) { // print the contents of frames array
                printf("%d\t", frames[k]);
            }
        }
        printf("\n");
    }
    printf("Page fault: %d\n", fault);
}