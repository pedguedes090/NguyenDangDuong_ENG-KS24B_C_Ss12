#include <stdio.h>

void menu() {
    printf("\nMENU\n");
    printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
    printf("2. In ra gia tri cac phan tu dang quan ly\n");
    printf("3. Them mot phan tu vao vi tri chi dinh\n");
    printf("4. Sua mot phan tu o vi tri chi dinh\n");
    printf("5. Xoa mot phan tu o vi tri chi dinh\n");
    printf("6. Sap xep cac phan tu\n");
    printf("7. Tim kiem phan tu nhap vao\n");
    printf("8. Thoat\n");
    printf("Moi ban nhap lua chon: ");
}

void addAllItem(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Moi ban nhap gia tri thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void showAllItem(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Phan tu arr[%d] co gia tri %d\n", i, arr[i]);
    }
}

int addItem(int arr[], int size, int value, int index) {
    if(index < 0 || index > size || size >= 100) {
        printf("Vi tri hoac kich thuoc khong hop le.\n");
        return size;
    }
    for(int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
    return size;
}

int deleteItem(int arr[], int size, int index) {
    if(index < 0 || index >= size) {
        printf("Vi tri khong hop le.\n");
        return size;
    }
    for(int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    return size;
}

void updateItem(int arr[], int size, int value, int index) {
    if(index >= 0 && index < size) {
        arr[index] = value;
    } else {
        printf("Vi tri khong hop le.\n");
    }
}

void sortItems(int arr[], int size, int order) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if((order == 0 && arr[i] > arr[j]) || (order == 1 && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void linearSearch(int arr[], int size, int value) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == value) {
            printf("Gia tri %d duoc tim thay o vi tri %d.\n", value, i);
            return;
        }
    }
    printf("Gia tri %d khong duoc tim thay.\n", value);
}

void binarySearch(int arr[], int size, int value) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == value) {
            printf("Gia tri %d duoc tim thay o vi tri %d.\n", value, mid);
            return;
        } else if(arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Gia tri %d khong duoc tim thay.\n", value);
}

int main() {
    int arr[100];
    int size = 0;
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Moi ban nhap so phan tu: ");
                scanf("%d", &size);
                addAllItem(arr, size);
                break;
            }
            case 2: {
                showAllItem(arr, size);
                break;
            }
            case 3: {
                int value, index;
                printf("Moi ban nhap vi tri can them: ");
                scanf("%d", &index);
                printf("Moi ban nhap gia tri: ");
                scanf("%d", &value);
                size = addItem(arr, size, value, index);
                break;
            }
            case 4: {
                int value, index;
                printf("Moi ban nhap vi tri can sua: ");
                scanf("%d", &index);
                printf("Moi ban nhap gia tri moi: ");
                scanf("%d", &value);
                updateItem(arr, size, value, index);
                break;
            }
            case 5: {
                int index;
                printf("Moi ban nhap vi tri can xoa: ");
                scanf("%d", &index);
                size = deleteItem(arr, size, index);
                break;
            }
            case 6: {
                int sortChoice;
                printf("Chon cach sap xep:\n");
                printf("1. Giam dan\n");
                printf("2. Tang dan\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &sortChoice);
                sortItems(arr, size, sortChoice - 1);
                break;
            }
            case 7: {
                int searchChoice, value;
                printf("Moi ban nhap gia tri can tim: ");
                scanf("%d", &value);
                printf("Chon cach tim kiem:\n");
                printf("1. Tim kiem tuyen tinh\n");
                printf("2. Tim kiem nhi phan\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &searchChoice);
                if(searchChoice == 1) {
                    linearSearch(arr, size, value);
                } else if(searchChoice == 2) {
                    sortItems(arr, size, 1); // Sap xep tang dan truoc khi tim kiem nhi phan
                    binarySearch(arr, size, value);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            }
            case 8: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le! Vui long chon lai.\n");
            }
        }
    } while(choice != 8);

    return 0;
}

