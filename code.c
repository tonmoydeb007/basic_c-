
#include <stdio.h>

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void insertAtPosition(int arr[], int *size, int value, int pos) {
    if (pos > *size || pos < 0) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
    {}
    void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, value, position;


    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

  
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    if (n > 10) {
        /reverseArray(arr, n);
        printf("Reversed array: ");
        printArray(arr, n);
      
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    if (n > 10) {
    
        reverseArray(arr, n);
        printf("Reversed array: ");
        printArray(arr, n);