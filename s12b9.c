#include <stdio.h>

void importArr(int arr[100][100], int a, int b) {
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            printf("Nhap gia tri cua array[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void printArr(int arr[100][100], int a, int b) {
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void cornerArr(int arr[100][100], int a, int b) {
    printf("%d ", arr[0][0]);
    printf("%d ", arr[0][b-1]);
    printf("%d ", arr[a-1][0]);
    printf("%d ", arr[a-1][b-1]);
}

void borderArr(int arr[100][100], int a, int b) {
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            if(i == 0 || i == a-1 || j == 0 || j == b-1) {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}

void mainDiagonal(int arr[100][100], int a, int b) {
    if(a != b) {
        printf("Khong co duong cheo chinh\n");
    } else {
        printf("Duong cheo chinh la:\n");
        for(int i = 0; i < a; i++) {
            printf("%d ", arr[i][i]);
        }
        printf("\n");
    }
}

void secondaryDiagonal(int arr[100][100], int a, int b) {
    if(a != b) {
        printf("Khong co duong cheo phu\n");
    } else {
        printf("Duong cheo phu la:\n");
        for(int i = 0; i < a; i++) {
            printf("%d ", arr[i][a-i-1]);
        }
        printf("\n");
    }
}

int isPrime(int n) {
    if(n < 2) return 0;
    for(int i = 2; i <= n/2; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

void primeNumbers(int arr[100][100], int a, int b) {
    printf("Cac phan tu la so nguyen to theo ma tran:\n");
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            if(isPrime(arr[i][j])) {
                printf("%d ", arr[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void printMenu() {
    printf("\nMENU\n");
    printf("1. Nhap gia tri cac phan tu cua mang\n");
    printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
    printf("3. In ra cac phan tu o goc theo ma tran\n");
    printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
    printf("5. In ra cac phan tu nam tren duong cheo chinh va duong cheo phu theo ma tran\n");
    printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
    printf("7. Thoat chuong trinh\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    int arr[100][100];
    int ans;
    int rows, columns;
    int flag = 0;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &columns);

    do {
        printMenu();
        scanf("%d", &ans);
        switch(ans) {
            case 1:
                flag = 1;
                importArr(arr, rows, columns);
                break;
            case 2:
                if(flag == 1) {
                    printArr(arr, rows, columns);
                } else {
                    printf("Vui long nhap mang truoc\n");
                }
                break;
            case 3:
                if(flag == 1) {
                    cornerArr(arr, rows, columns);
                } else {
                    printf("Vui long nhap mang truoc\n");
                }
                break;
            case 4:
                if(flag == 1) {
                    borderArr(arr, rows, columns);
                } else {
                    printf("Vui long nhap mang truoc\n");
                }
                break;
            case 5:
                if(flag == 1) {
                    mainDiagonal(arr, rows, columns);
                    secondaryDiagonal(arr, rows, columns);
                } else {
                    printf("Vui long nhap mang truoc\n");
                }
                break;
            case 6:
                if(flag == 1) {
                    primeNumbers(arr, rows, columns);
                } else {
                    printf("Vui long nhap mang truoc\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while(ans != 7);

    return 0;
}

