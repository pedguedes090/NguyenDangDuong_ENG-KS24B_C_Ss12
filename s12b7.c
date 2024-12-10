#include <stdio.h>

void taoMaTran(int arr[10][10], int soHang, int soCot) {
    printf("Nhap gia tri cho ma tran:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("Nhap gia tri cho phan tu [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void inMaTran(int arr[10][10], int soHang, int soCot) {
    printf("Ma tran vua nhap la:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[10][10];
    int soHang, soCot;
    printf("Nhap so hang: ");
    scanf("%d", &soHang);
    printf("Nhap so cot: ");
    scanf("%d", &soCot);

    taoMaTran(arr, soHang, soCot);
    inMaTran(arr, soHang, soCot);

    return 0;
}

