#include <stdio.h>
#include <string.h>
#include "function.h"


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
        printf("\n-- Buku baru berhasil ditambahkan --\n");
    }
}

void cariBuku() {
    char kode[20];
    int ditemukan = 0;

    printf("\n--- Pencarian Buku ---\n");
    printf("Masukkan Kode Buku : ");
    scanf(" %[^\n]", kode);

    // Mencari buku berdasarkan kode
    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].Kode, kode) == 0) {
            int tersedia = perpustakaan[i].JumlahTotal - perpustakaan[i].JumlahDipinjam;

            printf("\n=== INFORMASI BUKU ===\n");
            printf("Judul Buku        : %s\n", perpustakaan[i].Judul);
            printf("Kode Buku         : %s\n", perpustakaan[i].Kode);
            printf("Total Buku        : %d\n", perpustakaan[i].JumlahTotal);
            printf("Sedang Dipinjam   : %d\n", perpustakaan[i].JumlahDipinjam);
            printf("Tersedia          : %d\n", tersedia);
            printf("======================\n");

            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan) {
        printf("\n-- Buku dengan kode '%s' tidak ditemukan --\n", kode);
    }
}

void daftarBuku() {
    if (totalBuku == 0) {
        printf("\n-- Belum ada buku di perpustakaan --\n");
        return;
    }

    printf("\n=== DAFTAR SEMUA BUKU ===\n");
    printf("%-30s %-15s %-8s %-10s %-10s\n", "Judul", "Kode", "Total", "Dipinjam", "Tersedia");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalBuku; i++) {
        int tersedia = perpustakaan[i].JumlahTotal - perpustakaan[i].JumlahDipinjam;
        printf("%-30s %-15s %-8d %-10d %-10d\n",
               perpustakaan[i].Judul,
               perpustakaan[i].Kode,
               perpustakaan[i].JumlahTotal,
               perpustakaan[i].JumlahDipinjam,
               tersedia);
    }
    printf("================================================================================\n");
}

void peminjamanBuku() {
    char kode[20];
    char nama[50];
    int ditemukan = 0;
    int jumlahPinjam;
    
    printf("\n--- Peminjaman Buku ---\n");
    
    // Input nama peminjam
    printf("Masukkan Nama Peminjam : ");
    scanf(" %[^\n]", nama);
    
    // Input kode buku
    printf("Masukkan Kode Buku     : ");
    scanf(" %[^\n]", kode);
    
    // Cari buku berdasarkan kode
    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].Kode, kode) == 0) {
            ditemukan = 1;
            
            printf("\n-- Buku Ditemukan --\n");
            printf("Judul         : %s\n", perpustakaan[i].Judul);
            printf("Stok Tersedia : %d\n", perpustakaan[i].Jumlah);
            
            if (perpustakaan[i].Jumlah > 0) {
                printf("\nMasukkan Jumlah yang Ingin Dipinjam : ");
                scanf("%d", &jumlahPinjam);
                
                // Validasi input
                if (jumlahPinjam <= 0) {
                    printf("\n-- Jumlah tidak valid! --\n");
                } else if (jumlahPinjam > perpustakaan[i].Jumlah) {
                    printf("\n-- Stok tidak mencukupi! --\n");
                    printf("Stok tersedia hanya %d buku\n", perpustakaan[i].Jumlah);
                } else {
                    // Simpan data peminjaman
                    strcpy(daftarPeminjaman[totalPeminjaman].NamaPeminjam, nama);
                    strcpy(daftarPeminjaman[totalPeminjaman].KodeBuku, kode);
                    strcpy(daftarPeminjaman[totalPeminjaman].JudulBuku, perpustakaan[i].Judul);
                    daftarPeminjaman[totalPeminjaman].JumlahPinjam = jumlahPinjam;
                    totalPeminjaman++;
                    
                    // Kurangi stok
                    perpustakaan[i].Jumlah -= jumlahPinjam;
                    
                    printf("\n-- Peminjaman Berhasil! --\n");
                    printf("Peminjam : %s\n", nama);
                    printf("Buku     : %s\n", perpustakaan[i].Judul);
                    printf("Jumlah   : %d\n", jumlahPinjam);
                    printf("Sisa stok: %d\n", perpustakaan[i].Jumlah);
                }
            } else {
                printf("\n-- Maaf, stok buku habis! --\n");
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
void bubbleSortBuku() {
    struct Buku temp;

    for (int i = 0; i < totalBuku - 1; i++) {
        for (int j = 0; j < totalBuku - i - 1; j++) {
            if (strcmp(perpustakaan[j].Judul, perpustakaan[j+1].Judul) > 0) {
                temp = perpustakaan[j];
                perpustakaan[j] = perpustakaan[j+1];
                perpustakaan[j+1] = temp;
            }
        }
    }
}

void selesai() {
    printf("\nOke, Terimakasih \n");
}

void menu();

void subMenu1() {
    int subOpsi1;

    printf("\n=== MENU OPERATOR ===\n");
    printf("1. Penambahan Buku\n");
    printf("2. Pencarian Buku\n");
    printf("3. Daftar Buku\n");
    printf("4. Kembali\n");
    printf("5. Selesai\n");
    printf("Masukkan Opsi Anda : ");
    scanf("%d", &subOpsi1);

    switch (subOpsi1){
        case 1:
            penambahanBuku();
            bubbleSortBuku();
            printf("\n-- Perubahan Telah Disimpan --\n");
            subMenu1();
            break;
        case 2:
            cariBuku();
            subMenu1();
            break;
        case 3:
            daftarBuku();
            subMenu1();
            break;
        case 4:
            menu();
            break;
        case 5:
            selesai();
            break;
        default:
            printf("\nTidak Ada Opsi %d di dalam daftar opsi, Silahkan pilih kembali\n", subOpsi1);
            subMenu1();
            break;
    }
}

void subMenu2() {
    int subOpsi2;

    printf("\n=== MENU PENGUNJUNG ===\n");
    printf("1. Peminjaman Buku\n");
    printf("2. Pengembalian Buku\n");
    printf("3. Pencarian Buku\n");
    printf("4. Kembali\n");
    printf("5. Selesai\n");
    printf("Masukkan Opsi Anda : ");
    scanf("%d", &subOpsi2);

    switch (subOpsi2){
        case 1:
            peminjamanBuku();
            subMenu2();
            break;
        case 2:
            pengembalianBuku();
            subMenu2();
            break;
        case 3:
            cariBuku();
            subMenu2();
            break;
        case 4:
            menu();
            break;
        case 5:
            selesai();
            break;
        default:
            printf("\nTidak Ada Opsi %d di dalam daftar opsi, Silahkan pilih kembali\n", subOpsi2);
            subMenu2();
            break;
    }
}

void menu() {
    int opsi;

    printf("\n=== SISTEM PERPUSTAKAAN ===\n");
    printf("1. Operator\n");
    printf("2. Pengunjung\n");
    printf("3. Selesai\n");
    printf("Masukkan Opsi Anda : ");
    scanf("%d", &opsi);

    switch (opsi) {
        case 1:
            subMenu1();
            break;
        case 2:
            subMenu2();
            break;
        case 3:
            selesai();
            break;
        default:
            printf("\nTidak Ada Opsi %d di dalam daftar opsi, Silahkan pilih kembali\n", opsi);
            menu();
            break;
    }
}