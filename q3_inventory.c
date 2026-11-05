#include <stdio.h>

void inputStock(int arr[], int size);
int totalStock(int arr[], int size);
void findLowStock(int arr[], int size);
void sortStock(int arr[], int size);
void updateStock(int *item);

void inputStock(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Enter stock for product %d: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] < 0) {
            printf("Invalid! Stock cannot be negative. Try again.\n");
            i--;
        }
    }
}

int totalStock(int arr[], int size) {
    int i, total = 0;
    for (i = 0; i < size; i++)
        total += arr[i];
    return total;
}

void findLowStock(int arr[], int size) {
    int i, found = 0, allLow = 1;
    for (i = 0; i < size; i++) {
        if (arr[i] >= 5) { allLow = 0; break; }
    }
    if (allLow) {
        printf("All products are low in stock.\n");
        return;
    }
    for (i = 0; i < size; i++) {
        if (arr[i] < 5) {
            printf("  Slot %d: stock = %d (LOW)\n", i + 1, arr[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No low-stock products.\n");
}

void sortStock(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp    = arr[j];
                arr[j]  = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void updateStock(int *item) {
    int newStock;
    printf("Enter new stock value: ");
    scanf("%d", &newStock);
    if (newStock < 0) {
        printf("Invalid! Stock cannot be negative. Update cancelled.\n");
    } else {
        *item = newStock;
        printf("Stock updated successfully.\n");
    }
}

int main() {
    int stock[8];
    int index, i;

    printf("=== Inventory Management System ===\n\n");
    inputStock(stock, 8);

    printf("\nEnter product index to update (1-8): ");
    scanf("%d", &index);

    if (index < 1 || index > 8) {
        printf("Invalid product index!\n");
    } else {
        updateStock(&stock[index - 1]);
    }

    sortStock(stock, 8);

    printf("\n=== Updated Stock List (Sorted Ascending) ===\n");
    for (i = 0; i < 8; i++)
        printf("  Slot %d: %d\n", i + 1, stock[i]);

    printf("\n  Total Stock: %d\n", totalStock(stock, 8));

    printf("\n=== Low Stock Report ===\n");
    findLowStock(stock, 8);

    return 0;
}
