#include <stdio.h>
#define SIZE 100

void ubahArray(int index, int nilai, int array[]);

int main(){
    int a, b, arr[SIZE] = {1, 2, 3}; //tes perubahan array dengan 3 anggota
    printf("Nilai array sebelum diubah\n");
    for(size_t i = 0; i < 3; ++i) {
        printf("%d ", arr[i]);
    }
    puts("");

    //Loop untuk mengubah nilai array
    while(1) {
        printf("Pilih index array yang akan diubah (-1 untuk keluar): ");
        scanf("%d", &a);
        if(a == -1) {
            break; //keluar dari loop pengubah array
        } else if(a < 0 || a > SIZE) {
            printf("Masukan salah! ulangi\n");
        } else {
            printf("Masukkan nilai baru: ");
            scanf("%d", &b);
            ubahArray(a, b, arr);
        }
    }

    printf("Nilai array setelah diubah\n");
    for(size_t i = 0; i < 3; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void ubahArray(int index, int nilai, int array[]) {
    array[index] = nilai;
}