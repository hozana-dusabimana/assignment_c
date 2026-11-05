#include <stdio.h>

void inputMarks(int arr[], int size);
int findTotal(int arr[], int size);
float findAverage(int total, int size);
int findMax(int arr[], int size);
int findMin(int arr[], int size);
int countPass(int arr[], int size);

void inputMarks(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Enter mark for student %d: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] < 0 || arr[i] > 100) {
            printf("Invalid! Mark must be between 0 and 100. Try again.\n");
            i--;
        }
    }
}

int findTotal(int arr[], int size) {
    int i, total = 0;
    for (i = 0; i < size; i++)
        total += arr[i];
    return total;
}

float findAverage(int total, int size) {
    return (float)total / size;
}

int findMax(int arr[], int size) {
    int i, max = arr[0];
    for (i = 1; i < size; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

int findMin(int arr[], int size) {
    int i, min = arr[0];
    for (i = 1; i < size; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}

int countPass(int arr[], int size) {
    int i, count = 0;
    for (i = 0; i < size; i++)
        if (arr[i] >= 50) count++;
    return count;
}

int main() {
    int marks[5];
    int total, max, min, passed, failed, i;
    float average;

    printf("=== Student Result Processing System ===\n\n");
    inputMarks(marks, 5);

    total   = findTotal(marks, 5);
    average = findAverage(total, 5);
    max     = findMax(marks, 5);
    min     = findMin(marks, 5);
    passed  = countPass(marks, 5);
    failed  = 5 - passed;

    printf("\n=== All Entered Marks ===\n");
    for (i = 0; i < 5; i++)
        printf("  Student %d: %d\n", i + 1, marks[i]);

    printf("\n=== Summary ===\n");
    printf("  Total Marks   : %d\n", total);
    printf("  Average Mark  : %.2f\n", average);

    if (max == min) {
        printf("  All marks are identical.\n");
    } else {
        printf("  Highest Mark  : %d\n", max);
        printf("  Lowest Mark   : %d\n", min);
    }

    printf("  Passed        : %d\n", passed);
    printf("  Failed        : %d\n", failed);

    if (passed == 0)
        printf("\nNo student passed.\n");
    else if (passed == 5)
        printf("\nAll students passed.\n");

    printf("\nPerformance: ");
    if (average >= 70)
        printf("Excellent\n");
    else if (average >= 50)
        printf("Moderate\n");
    else
        printf("Poor\n");

    return 0;
}
