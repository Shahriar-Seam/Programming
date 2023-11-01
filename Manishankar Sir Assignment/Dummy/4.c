#include <stdio.h>

int main() {
    int arr[1000];
    int i;
    
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (i = 10; i >= 3; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[3] = 45;
    
    for (i = 0; i < 11; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}