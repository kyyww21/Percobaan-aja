#include <stdio.h>
#include <string.h>

struct Buku
{
    char Judul[50];
    char Kode[20];
    int JumlahTotal;
    int JumlahDipinjam;
};
struct Buku perpustakaan[100];
int totalBuku = 0;

void penambahanBuku() {
    char kode[20];
    int jumlahTambah;
    int ditemukan = 0;

    printf("\n--- Tambah Buku ---\n");
    printf("Masukkan Kode Buku  : ");
    scanf(" %[^\n]", kode);

    // Cek apakah buku dengan kode tersebut sudah ada
    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].Kode, kode) == 0) {
            ditemukan = 1;

            printf("\n-- Buku ditemukan! --\n");
            printf("Judul: %s\n", perpustakaan[i].Judul);
            printf("Stok sekarang: %d\n", perpustakaan[i].JumlahTotal);
            printf("\nMasukkan jumlah yang ingin ditambahkan : ");
            scanf("%d", &jumlahTambah);

            perpustakaan[i].JumlahTotal += jumlahTambah;

            printf("\n-- Stok berhasil ditambahkan! --\n");
            printf("Stok baru: %d\n", perpustakaan[i].JumlahTotal);
            break;
        }
    }

    // Jika buku belum ada, buat entry baru
    if (!ditemukan) {
        if (totalBuku >= 100) {
            printf("Penyimpanan penuh!\n");
            return;
        }

        printf("\n-- Buku baru, silakan lengkapi data --\n");

        strcpy(perpustakaan[totalBuku].Kode, kode);

        printf("Masukkan Judul Buku : ");
        scanf(" %[^\n]", perpustakaan[totalBuku].Judul);

        printf("Masukkan Jumlah     : ");
        scanf(" %d", &perpustakaan[totalBuku].JumlahTotal);

        perpustakaan[totalBuku].JumlahDipinjam = 0;

        totalBuku++;
        printf("\n-- Buku yang baru berhasil ditambahkan --\n");
    }
}