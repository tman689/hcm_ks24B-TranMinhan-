#include <stdio.h>

int isPerfectNumber(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}
int findSecondLargest(int arr[], int n) {
    int max = -1, secondMax = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        } else if (arr[i] > secondMax && arr[i] < max) {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

int addElement(int arr[], int *n, int value, int position) {
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*n)++;
    return 0;
}

int deleteElement(int arr[], int *n, int position) {
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return 0;
}

int insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return 0;
}
int sortEvenOdd(int arr[], int n) {
    int temp[100];
    int evenIndex = 0, oddIndex = n - 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            temp[evenIndex++] = arr[i];
        } else {
            temp[oddIndex--] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    return 0;
}
int main() {
    int arr[100], n = 0, choice;

    do {
        printf("\nMENU:\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong cac so hoan hao trong mang\n");
        printf("4. Tim gia tri lon thu 2 trong mang\n");
        printf("5. Them mot phan tu vao vi tri ngau nhien trong mang\n");
        printf("6. Xoa phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu tang dan (Insertion sort)\n");
        printf("8. Tim kiem phan tu trong mang (Binary search)\n");
        printf("9. Sap xep mang sao cho so chan dung truoc, so le dung sau\n");
        printf("10. Dao nguoc thu tu cac phan tu trong mang\n");
        printf("0. Thoat\n");

        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri cho arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                break;
            case 4:
                printf("Gia tri lon thu 2: %d\n", findSecondLargest(arr, n));
                break;
            case 5: {
                int value, position;
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them: ");
                scanf("%d", &position);
                if (position >= 0 && position <= n) {
                    addElement(arr, &n, value, position);
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;
            }
            case 6: {
                int position;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &position);
                if (position >= 0 && position < n) {
                    deleteElement(arr, &n, position);
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;
            }
            case 7:
                insertionSort(arr, n);
                printf("Mang sau khi sap xep: \n");
                printArray(arr, n);
                break;
            case 8: 
                break;
            case 9:
                sortEvenOdd(arr, n);
                printf("Mang sau khi sap xep chan truoc le sau: \n");
                printArray(arr, n);
                break;
            case 10:
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}

