#include <stdio.h>

void main()
{
    int n = 20, frame = 3;
    int pages[50] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int frames[10];
    int last_used[10]; // Array to store the last used time of each frame
    for (int i = 0; i < frame; i++)
    {
        frames[i] = -1;    // -1 indicates an empty frame
        last_used[i] = -1; // Initialize the last used time for each frame
    }

    int time = 0, fault = 0; // `time` keeps track of each access time
    printf("Ref. string         Page Frames\n");
    printf("-----------    --------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t", pages[i]); // Print the reference page

        int exist = 0; // Check if the page already exists in a frame
        for (int k = 0; k < frame; k++)
        {
            if (pages[i] == frames[k])
            {
                exist = 1;
                last_used[k] = time; // Update last used time for the frame
                break;
            }
        }

        if (!exist)
        { // If the page is not in any frame, it's a page fault
            int lru_index = 0;
            for (int k = 1; k < frame; k++)
            { // Find the LRU frame index
                if (last_used[k] < last_used[lru_index])
                {
                    lru_index = k;
                }
            }

            frames[lru_index] = pages[i]; // Replace the LRU page
            last_used[lru_index] = time;  // Update last used time for the new page
            fault++;

            for (int k = 0; k < frame; k++)
            { // Print the frames content
                printf("%d\t", frames[k]);
            }
        }
        printf("\n");
        time++; // Increment time for each page access
    }
    printf("Page fault: %d\n", fault);
}

