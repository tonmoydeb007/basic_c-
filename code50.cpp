#include <cstdio>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr + n);
    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
