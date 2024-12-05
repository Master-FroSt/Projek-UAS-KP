#include <stdio.h>
#define SIZE 64
#define PAJAK 0.1

void printMenu(int harga[]);
void pesanan(int count, int pesan, int pilihan[]);
void printHarga(int count, int pilihan[], int harga[], double hargaTotal);

int main(){
    //deklarasi dan inisialisasi
    int pilihan[SIZE];
    int harga[SIZE] = {
        15000, // Paket Hemat
        17000, // Paket Spesial
        20000, // Paket Komplit
        7000,  // Ayam Goreng Dada
        6000,  // Ayam Goreng Paha
        5000,  // Ayam Goreng Sayap
        3000,  // Ayam Goreng Kepala
        2000,  // Ayam Goreng Ceker
        2000,  // Nasi Putih
        2500,  // Nasi Uduk
        8000,  // Ayam Rica-Rica
        9000,  // Sambal Goreng Udang
        9000,  // Ayam Geprek
        9000,  // Ayam Bakar
        9000,  // Ayam Teriyaki
        3000,  // Es Teh/Es Jeruk
        5000,  // Jus Buah
        5000,  // Es Teler
        5000,  // Es Campur
        4000,  // Es Cincau
        6000,  // Es Kelapa Muda
        4000   // Es Cappucino
    };
    double hargaTotal = 0.0;

    int count = 0;
    printMenu(harga);
    while(1){
        int pesan;
        printf("Pilih menu yang diinginkan (-1 untuk melakukan pembayaran): ");
        scanf("%d", &pesan);
        pesanan(count, pesan, pilihan);
        count++;
        if(pesan == -1) break;
    }

    //Konfirmasi pembayaran
    int metodePembayaran;
    printHarga(count, pilihan, harga, hargaTotal);
    while(1){
        scanf("%d", &metodePembayaran);
        switch(metodePembayaran){
            case 1:
            puts("Metode Cash dipilih.");
            break;
            case 2:
            puts("Metode Cashless dipilih");
            break;
            default:
            puts("Masukan salah, silakan isi kembali!");
        }
    if(metodePembayaran == 1 || metodePembayaran == 2) break;
    }
    printf("Terima kasih telah bertransaksi!");
    printf("Silakan ditunggu masakannya!");

    return 0;
}

void printMenu(int harga[]) {
    for (int i = 0; i < 44; i++) {
        printf("=");
    } 
    printf(" Menu Paket ");
    for (int i = 0; i < 43; i++) {
        printf("=");
    }
    printf("\n");

    printf("1. Paket Hemat    (Ayam Goreng, Nasi Putih, Sambal, Es Teh/Es Jeruk)                   = Rp. %d\n", harga[0]);
    printf("2. Paket Spesial  (Ayam Goreng, Nasi Putih, Sambal, Telur, Es Teh/Es Jeruk)            = Rp. %d\n", harga[1]);
    printf("3. Paket Komplit  (Ayam Goreng, Nasi Putih, Sambal, Telur, Sayur, Es Teh/Es Jeruk)     = Rp. %d\n", harga[2]);

    printf("\n");

    for (int i = 0; i < 44; i++) {
        printf("=");
    } 
    printf(" Menu Single ");
    for (int i = 0; i < 42; i++) {
        printf("=");
    }
    printf("\n");

    printf("4. Ayam Goreng Dada                                                                    = Rp. %d\n", harga[3]);
    printf("5. Ayam Goreng Paha (Paha Atas/Paha Bawah)                                             = Rp. %d\n", harga[4]);
    printf("6. Ayam Goreng Sayap                                                                   = Rp. %d\n", harga[5]);
    printf("7. Ayam Goreng Kepala                                                                  = Rp. %d\n", harga[6]);
    printf("8. Ayam Goreng Ceker                                                                   = Rp. %d\n", harga[7]);
    printf("9. Nasi Putih                                                                          = Rp. %d\n", harga[8]);
    printf("10. Nasi Uduk                                                                          = Rp. %d\n", harga[9]);
    printf("11. Ayam Rica-Rica                                                                     = Rp. %d\n", harga[10]);
    printf("12. Sambal Goreng Udang                                                                = Rp. %d\n", harga[11]);
    printf("13. Ayam Geprek                                                                        = Rp. %d\n", harga[12]);
    printf("14. Ayam Bakar                                                                         = Rp. %d\n", harga[13]);
    printf("15. Ayam Teriyaki                                                                      = Rp. %d\n", harga[14]);

    printf("\n");
    for (int i = 0; i < 45; i++) {
        printf("=");
    } 
    printf(" Minuman ");
    for (int i = 0; i < 45; i++) {
        printf("=");
    }
    printf("\n");

    printf("16. Es Teh/Es Jeruk                                                                    = Rp. %d\n", harga[15]);
    printf("17. Jus Buah (Jeruk, Apel, Melon, dst)                                                 = Rp. %d\n", harga[16]);
    printf("18. Es Teler                                                                           = Rp. %d\n", harga[17]);
    printf("19. Es Campur                                                                          = Rp. %d\n", harga[18]);
    printf("20. Es Cincau                                                                          = Rp. %d\n", harga[19]);
    printf("21. Es Kelapa Muda                                                                     = Rp. %d\n", harga[20]);
    printf("22. Es Cappucino                                                                       = Rp. %d\n", harga[21]);
}


void pesanan(int count, int pesan, int pilihan[]) {
    pilihan[count] = pesan;
}

void printHarga(int count, int pilihan[], int harga[], double hargaTotal) {
    for(int i = 0; i < count; i++){
        hargaTotal += harga[pilihan[i] - 1];
    }
    hargaTotal += (hargaTotal * PAJAK);
    printf("Rp%.2lf\n", hargaTotal);
    puts("Pilih metode pembayaran:\n1. Cash\n2. Cashless");
}