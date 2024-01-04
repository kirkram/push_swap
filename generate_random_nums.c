#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# ifndef MAX_RANGE
#  define MAX_RANGE 1000
# endif

int main() {
    int numbers[MAX_RANGE];
    int n, start, i, j, temp;

    // Ask for the starting number
    printf("Enter the starting number: ");
    scanf("%d", &start);

    // Initialize array with numbers starting from 'start'
    for (i = 0; i < MAX_RANGE; i++) {
        numbers[i] = start + i;
    }

    // Seed random number generator
    srand(time(NULL));

    // Shuffle array to get random order
    for (i = MAX_RANGE - 1; i > 0; i--) {
        j = rand() % (i + 1);

        // Swap numbers[i] and numbers[j]
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Ask for number of random numbers to generate
    printf("Enter number of random numbers to generate (1-%d): ", MAX_RANGE);
    scanf("%d", &n);

    // Check for valid input
    if (n < 1 || n > MAX_RANGE) {
        printf("Invalid input. Please enter a number between 1 and %d\\n", MAX_RANGE);
        return 1;
    }

    // Output the first n numbers
    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
