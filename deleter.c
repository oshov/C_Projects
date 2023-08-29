#include <stdio.h>
#define MAX_SIZE 100

void deleteKSmaller(int arr[], int n, int k) {
    int top = -1;
    int temp[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[i] > temp[top] && k > 0) {
            top--;
            k--;
        }
        temp[++top] = arr[i];
    }

    int i = 0;
    while (k > 0 && i <= top) {
        top--;
        k--;
    }

    for (int j = 0; j <= top; j++) {
        printf("%d ", temp[j]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k >= n) {
        printf("Invalid input: k should be less than n.\n");
        return 1;
    }

    printf("Output after deleting %d elements:\n", k);
    deleteKSmaller(arr, n, k);

    return 0;
}
