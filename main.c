#include <stdio.h>
#define SIZE 22
#define PAJAK 0.1

void printMenu(int harga[]);
void pesanan(int count, int pesan, int pilihan[], int stok[]);
void printHarga(int count, int pilihan[], int harga[], double hargaTotal);
void ubahHarga(int index, int harga[]);
void updateStok(int index, int stok[]);

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
    int stok[SIZE];
    for(int i = 0; i < SIZE; i++) {
        stok[i] = 0;
    }

    // Program utama
    while(1) {
        puts("1. Program pemesanan\n2. Program Admin");
        int statusProgram;
        int statusPesan;
        int statusAdmin;
        while (1){
            //Pemilihan antara program Pemesanan dan program Admin
            scanf("%d", &statusProgram);
            switch(statusProgram){
                    case 1:
                    puts("Memulai program pemesanan");

                    //Program pemesanan
                    while(1) {
                        double hargaTotal = 0.0;
                        int count = 0;
                        printMenu(harga);
                        while(1){
                            int pesan;
                            puts("Pilih menu yang diinginkan (-1 untuk melakukan pembayaran): ");
                            //Error handling pada pilihan makanan
                            while(1) {
                                scanf("%d", &pesan);
                                if(pesan == -1) break;
                                if(stok[pesan] == 0) {
                                    printf("Maaf stok untuk produk %d sedang habis. Silakan pilih menu lain", pesan);
                                    puts("");
                                } else {
                                    pesanan(count, pesan, pilihan, stok);
                                    count++;
                                }
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
                                puts("Masukan salah! Silakan isi kembali!");
                            }
                        if(metodePembayaran == 1 || metodePembayaran == 2) break;
                        }
                        printf("Terima kasih telah bertransaksi!");
                        printf("Silakan ditunggu masakannya!");

                        //Pemilihan untuk program Pemesanan
                        puts("1. Memulai kembali program Pemesanan\n 2. Keluar dari program Pemesanan");
                        while (1){
                            scanf("%d", &statusPesan);
                            switch(statusPesan){
                                    case 1:
                                    puts("Memulai program Pemesanan");
                                    break;
                                    case 2:
                                    puts("Mengakhiri program Pemesanan");
                                    break;
                                    default:
                                    puts("Masukan salah! Silakan isi kembali!");
                                }
                        }
                        if (statusPesan == 2) break;
                    }
                    break;
                    case 2:
                    puts("Memulai program Admin");
                    while(1) {
                        //program Admin
                        int index;
                        int fitur;
                        puts("Pilih fitur yang ingin digunakan:\n1. Pembaruan stok\n2. Pembaruan harga");
                        scanf("%d", &fitur);
                        switch(fitur) {
                            case 1:
                            updateStok(index, stok);
                            break;
                            case 2:
                            ubahHarga(index, harga);
                            break;
                            default:
                            puts("Maaf, fitur tidak tersedia");
                        }

                        //Pemilihan untuk akhir program Admin
                        puts("1. Memulai kembali program Admin\n 2. Keluar dari program Admin");
                            scanf("%d", &statusAdmin);
                        switch(statusAdmin){
                                case 1:
                                puts("Memulai program Admin");
                                break;
                                case 2:
                                puts("Mengakhiri program Admin");
                                break;
                                default:
                                puts("Masukan salah! Silakan isi kembali!");
                            }
                    }
                    break;
                    default:
                    puts("Masukan salah! Silakan isi kembali!");
                }
            }
        }
        if (statusPesan == 2 || statusAdmin == 2) break;
    }
    

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


void pesanan(int count, int pesan, int pilihan[], int stok[]) {
    stok[pesan] -= 1;
    pilihan[count] = pesan;
}

void printHarga(int count, int pilihan[], int harga[], double hargaTotal) {
    for(int i = 0; i < count; i++){
        hargaTotal += harga[pilihan[i] - 1];
    }
    hargaTotal += (hargaTotal * PAJAK);
    puts("TOTAL BELANJA:");
    printf("Rp%.2lf\n", hargaTotal);
    puts("Pilih metode pembayaran:\n1. Cash\n2. Cashless");
}

void ubahHarga(int index, int harga[]) {
    int hargaBaru;
    puts("Masukkan produk yang ingin diubah: ");
    scanf("%d", &index);
    puts("Masukkan jumlah harga yang baru: ");
    harga[index - 1] = hargaBaru; 
}

void updateStok(int index, int stok[]) {
    int stokBaru;
    int fitur2;
    puts("Pilih fitur yang diinginkan:\n1. Update stok sebuah produk\n2. Update stok semua produk");
    scanf("%d", &fitur2);
    switch(fitur2) {
        case 1:
        puts("Masukkan produk yang ingin diubah: ");
        scanf("%d", index);
        puts("Masukkan stok  terbaru: ");
        scanf("%d", &stokBaru);
        stok[index - 1] = stokBaru; 
        printf("Stok produk %d berhasil diperbarui", index);
        puts("");
        break;
        case 2:
        for(int i = 0; i < SIZE; i++) {
            printf("Masukkan stok baru untuk produk %d: ", i + 1);
            scanf("%d", &stokBaru);
            stok[i] = stokBaru; 
        }
        puts("Semua stok berhasil diperbarui");
        default:
        puts("Masukkan salah! Silakan coba kembali!");
    }
}