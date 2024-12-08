#include <stdio.h>
#define SIZE 22
#define PAJAK 0.1

void printMenu(int harga[]);
void pesanan(int count, int pesan, int pilihan[], int stok[]);
void printHarga(int count, int pilihan[], int harga[], double hargaTotal);
void ubahHarga(int harga[]);
void updateStok(int stok[]);

int main() {
    int pilihan[SIZE];
    int harga[SIZE] = {
        15000, 17000, 20000, 7000, 6000, 5000, 3000, 2000, 2000, 2500,
        8000, 9000, 9000, 9000, 9000, 3000, 5000, 5000, 5000, 4000,
        6000, 4000
    };
    int stok[SIZE];
    for (int i = 0; i < SIZE; i++) stok[i] = 0; // Stok default 0

    while (1) {
        puts("1. Program Pemesanan\n2. Program Admin\n3. Keluar");
        int statusProgram;
        printf("Masukkan pilihan: ");
        scanf("%d", &statusProgram);

        if (statusProgram == 3) {
            puts("Terima kasih telah menggunakan program!");
            break;
        }

        switch (statusProgram) {
            case 1: {
                puts("Memulai Program Pemesanan...");
                while (1) {
                    printMenu(harga);
                    int pesan, count = 0;
                    double hargaTotal = 0.0;
                    while (1) {
                        printf("Pilih menu (-1 untuk pembayaran): ");
                        scanf("%d", &pesan);

                        if (pesan == -1) break;
                        if (pesan < 1 || pesan > SIZE) {
                            puts("Menu tidak valid! Silakan coba lagi.");
                            continue;
                        }
                        if (stok[pesan - 1] == 0) {
                            puts("Maaf, stok habis.");
                            continue;
                        }
                        pesanan(count, pesan, pilihan, stok);
                        count++;
                    }

                    printHarga(count, pilihan, harga, hargaTotal);

                    int metodePembayaran;
                    while (1) {
                        printf("Pilih metode pembayaran (1: Cash, 2: Cashless): ");
                        scanf("%d", &metodePembayaran);
                        if (metodePembayaran == 1 || metodePembayaran == 2) break;
                        puts("Metode pembayaran tidak valid!");
                    }
                    puts("Terima kasih atas pesanan Anda!");

                    int statusPesan;
                    printf("1. Pesan lagi\n2. Kembali ke menu utama: ");
                    scanf("%d", &statusPesan);
                    if (statusPesan == 2) break;
                }
                break;
            }

            case 2: {
                puts("Memulai Program Admin...");
                while (1) {
                    puts("1. Perbarui Stok\n2. Ubah Harga\n3. Kembali ke menu utama");
                    int fiturAdmin;
                    printf("Pilih fitur: ");
                    scanf("%d", &fiturAdmin);

                    if (fiturAdmin == 3) break;

                    switch (fiturAdmin) {
                        case 1:
                            updateStok(stok);
                            break;
                        case 2:
                            ubahHarga(harga);
                            break;
                        default:
                            puts("Fitur tidak valid! Silakan coba lagi.");
                    }
                }
                break;
            }

            default:
                puts("Pilihan tidak valid! Silakan coba lagi.");
        }
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
    stok[pesan - 1] -= 1;
    pilihan[count] = pesan;
}

void printHarga(int count, int pilihan[], int harga[], double hargaTotal) {
    for (int i = 0; i < count; i++) {
        hargaTotal += harga[pilihan[i] - 1];
    }
    hargaTotal += (hargaTotal * PAJAK);
    puts("TOTAL BELANJA:");
    printf("Rp%.2lf\n", hargaTotal);
    puts("Pilih metode pembayaran:\n1. Cash\n2. Cashless");
}

void ubahHarga(int harga[]) {
    int index, hargaBaru;
    printf("Masukkan nomor produk (1-%d): ", SIZE);
    scanf("%d", &index);
    if (index < 1 || index > SIZE) {
        puts("Nomor produk tidak valid!");
        return;
    }
    printf("Masukkan harga baru: ");
    scanf("%d", &hargaBaru);
    if (hargaBaru < 0) {
        puts("Harga tidak boleh negatif!");
        return;
    }
    harga[index - 1] = hargaBaru;
    puts("Harga berhasil diperbarui!");
}

void updateStok(int stok[]) {
    int fitur, index, stokBaru;
    puts("1. Perbarui stok satu produk\n2. Perbarui stok semua produk");
    printf("Pilih fitur: ");
    scanf("%d", &fitur);

    if (fitur == 1) {
        printf("Masukkan nomor produk (1-%d): ", SIZE);
        scanf("%d", &index);
        if (index < 1 || index > SIZE) {
            puts("Nomor produk tidak valid!");
            return;
        }
        printf("Masukkan stok baru: ");
        scanf("%d", &stokBaru);
        if (stokBaru < 0) {
            puts("Stok tidak boleh negatif!");
            return;
        }
        stok[index - 1] = stokBaru;
        puts("Stok berhasil diperbarui!");
    } else if (fitur == 2) {
        for (int i = 0; i < SIZE; i++) {
            printf("Masukkan stok baru untuk produk %d: ", i + 1);
            scanf("%d", &stokBaru);
            stok[i] = stokBaru;
        }
        puts("Semua stok berhasil diperbarui!");
    } else {
        puts("Fitur tidak valid!");
    }
}
