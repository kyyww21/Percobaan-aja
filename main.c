#include <stdio.h>
#include <string.h>

struct Buku
{
    char Judul[50];
    char Kode[20];
    int JumlahTotal;
    int JumlahDipinjam;
};

struct Siswa
{
    char namaSiswa[50];
    char kelasSiswa[50];
};


struct Buku perpustakaan[100];
struct Siswa pinjam[500];

int totalBuku = 0;

void peminjamanBuku() {
    char kode[20];
    int ditemukan = 0;

    printf("\n--- Peminjaman Buku ---\n");
    printf("Masukan Nama Anda : ");
    scanf(" %[^\n]", pinjam.namaSiswa);
    printf("Masukkan Kode Buku : ");
    scanf(" %[^\n]", kode);

    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].Kode, kode) == 0) {
            ditemukan = 1;
            int tersedia = perpustakaan[i].JumlahTotal - perpustakaan[i].JumlahDipinjam;

            if (tersedia > 0) {
                perpustakaan[i].JumlahDipinjam++;
                printf("\n-- Peminjaman berhasil! --\n");
                printf("Buku '%s' telah dipinjam\n", perpustakaan[i].Judul);
                printf("Sisa tersedia: %d\n", tersedia - 1);
            } else {
                printf("\n-- Maaf, buku '%s' sedang tidak tersedia --\n", perpustakaan[i].Judul);
            }
            break;
        }
    }

    if (!ditemukan) {
        printf("\n-- Buku dengan kode '%s' tidak ditemukan --\n", kode);
    }
}

void pengembalianBuku() {
    char kode[20];
    int ditemukan = 0;

    printf("\n--- Pengembalian Buku ---\n");
    printf("Masukkan Kode Buku : ");
    scanf(" %[^\n]", kode);

    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].Kode, kode) == 0) {
            ditemukan = 1;

            if (perpustakaan[i].JumlahDipinjam > 0) {
                perpustakaan[i].JumlahDipinjam--;
                printf("\n-- Pengembalian berhasil! --\n");
                printf("Buku '%s' telah dikembalikan\n", perpustakaan[i].Judul);
                int tersedia = perpustakaan[i].JumlahTotal - perpustakaan[i].JumlahDipinjam;
                printf("Tersedia sekarang: %d\n", tersedia);
            } else {
                printf("\n-- Tidak ada peminjaman aktif untuk buku '%s' --\n", perpustakaan[i].Judul);
            }
            break;
        }
    }

    if (!ditemukan) {
        printf("\n-- Buku dengan kode '%s' tidak ditemukan --\n", kode);
    }
}
