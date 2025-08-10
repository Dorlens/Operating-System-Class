#include <stdio.h>

int main(void) {
    int ch;
    int inTag = 0;       // Whether we're currently inside a tag
    int tagCount = 0;

    printf("*** START OF HTML TAGS ***\n\n");

    while ((ch = getchar()) != EOF) {
        if (ch == '<') {   // Start of tag
            inTag = 1;
            tagCount++;
            putchar('<');
        }
        else if (ch == '>') { // End of tag
            putchar('>');
            putchar('\n');    // New line after the tag
            inTag = 0;
        }
        else if (inTag) {    // Inside a tag
            putchar(ch);
        }
    }

    printf("\nTotal number of tags found: %d\n", tagCount);

    return 0;
}