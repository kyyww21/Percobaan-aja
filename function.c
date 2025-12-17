#include <stdio.h>
#include <string.h>
#include "function.h"

struct Buku {
    char Judul[50];
    char Kode[20];
    int jumlahTotal;
};
struct Peminjaman {
    char NamaPeminjam[50];
    char Kelas[10];
    char KodeBuku[20];
    char JudulBuku[50];
    int jumlahPinjam;
};

struct Buku perpustakaan[100];
struct Peminjaman daftarPeminjaman[200];
int totalBuku = 0;
int totalPeminjaman = 0;

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
            printf("Stok sekarang: %d\n", perpustakaan[i].jumlahTotal);
            printf("\nMasukkan jumlah yang ingin ditambahkan : ");
            scanf("%d", &jumlahTambah);

            perpustakaan[i].jumlahTotal += jumlahTambah;

            printf("\n-- Stok berhasil ditambahkan! --\n");
            printf("Stok baru: %d\n", perpustakaan[i].jumlahTotal);
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
        scanf(" %d", &perpustakaan[totalBuku].jumlahTotal);

        daftarPeminjaman[totalBuku].jumlahPinjam = 0;

        totalBuku++;
        printf("\n-- Buku baru berhasil ditambahkan --\n");
    }
}

void bubbleSortBuku() {
    struct Buku A;

    for (int i = 0; i < totalBuku - 1; i++) {
        for (int j = 0; j < totalBuku - i - 1; j++) {
            if (strcmp(perpustakaan[j].Judul, perpustakaan[j+1].Judul) > 0) {
                A = perpustakaan[j];
                perpustakaan[j] = perpustakaan[j+1];
                perpustakaan[j+1] = A;
            }
        }
    }
}

void peminjamanBuku() {
    char kode[20];
    char nama[50];
    char kelas[20];
    int ditemukan = 0;
    int jumlahPinjam;

    printf("\n--- Peminjaman Buku ---\n");

    printf("Masukkan Nama Peminjam : ");
    scanf(" %[^\n]", nama);

    printf("Masukkan Kelas         : ");
    scanf(" %[^\n]", kelas);

    printf("Masukkan Kode Buku     : ");
    scanf(" %[^\n]", kode);
    for (int i = 0; i < totalBuku; i++) {
        if (strcmp(perpustakaan[i].Kode, kode) == 0) {
            ditemukan = 1;

            printf("\n-- Buku Ditemukan --\n");
            printf("Judul Buku    : %s\n", perpustakaan[i].Judul);
            printf("Kode Buku     : %s\n", perpustakaan[i].Kode);

            if (perpustakaan[i].jumlahTotal > 0) {
                printf("\nMasukkan Jumlah yang Ingin Dipinjam : ");
                scanf("%d", &jumlahPinjam);

                if (jumlahPinjam <= 0) {
                    printf("\n-- Jumlah tidak valid! --\n");
                } else if (jumlahPinjam > perpustakaan[i].jumlahTotal) {
                    printf("\n-- Stok tidak mencukupi! --\n");
                    printf("Stok tersedia hanya %d buku\n", perpustakaan[i].jumlahTotal);
                } else {
                    strcpy(daftarPeminjaman[totalPeminjaman].NamaPeminjam, nama);
                    strcpy(daftarPeminjaman[totalPeminjaman].Kelas, kelas);
                    strcpy(daftarPeminjaman[totalPeminjaman].KodeBuku, kode);
                    strcpy(daftarPeminjaman[totalPeminjaman].JudulBuku, perpustakaan[i].Judul);
                    daftarPeminjaman[totalPeminjaman].jumlahPinjam = jumlahPinjam;
                    totalPeminjaman++;

                    perpustakaan[i].jumlahTotal -= jumlahPinjam;

                    printf("\n-- Peminjaman Berhasil! --\n");
                    printf("Nama Peminjam : %s\n", nama);
                    printf("Kelas / Guru  : %s\n", kelas);
                    printf("Nama Buku     : %s\n", perpustakaan[i].Judul);
                    printf("Kode Buku     : %s\n", kode);
                    printf("Jumlah Pinjam : %d\n", jumlahPinjam);
                }
            }
            break;
        }
    }

    if (!ditemukan) {
        printf("\n-- Buku dengan kode '%s' tidak ditemukan --\n", kode);
    }
}

void pengembalianBuku() {
    char nama[50];
    char kode[20];
    int ditemukan = 0;
    int jumlahKembali;

    printf("\n--- Pengembalian Buku ---\n");

    printf("Masukkan Nama Peminjam : ");
    scanf(" %[^\n]", nama);

    printf("Masukkan Kode Buku     : ");
    scanf(" %[^\n]", kode);

    // Cari data peminjaman yang sesuai
    for (int i = 0; i < totalPeminjaman; i++) {
        if (strcmp(daftarPeminjaman[i].NamaPeminjam, nama) == 0 &&
            strcmp(daftarPeminjaman[i].KodeBuku, kode) == 0) {
            ditemukan = 1;

            printf("\n-- Data Peminjaman Ditemukan --\n");
            printf("Nama Peminjam : %s\n", daftarPeminjaman[i].NamaPeminjam);
            printf("Kelas / Guru  : %s\n", daftarPeminjaman[i].Kelas);
            printf("Judul Buku    : %s\n", daftarPeminjaman[i].JudulBuku);
            printf("Kode Buku     : %s\n", daftarPeminjaman[i].KodeBuku);
            printf("Jumlah Pinjam : %d\n", daftarPeminjaman[i].jumlahPinjam);

            printf("\nMasukkan Jumlah yang Ingin Dikembalikan : ");
            scanf("%d", &jumlahKembali);

            if (jumlahKembali <= 0) {
                printf("\n-- Jumlah tidak valid! --\n");
            } else if (jumlahKembali > daftarPeminjaman[i].jumlahPinjam) {
                printf("\n-- Jumlah pengembalian melebihi jumlah pinjaman! --\n");
                printf("Jumlah yang dipinjam hanya %d buku\n", daftarPeminjaman[i].jumlahPinjam);
            } else {
                // Tambahkan stok buku kembali ke perpustakaan
                for (int j = 0; j < totalBuku; j++) {
                    if (strcmp(perpustakaan[j].Kode, kode) == 0) {
                        perpustakaan[j].jumlahTotal += jumlahKembali;
                        break;
                    }
                }

                // Update jumlah pinjaman
                daftarPeminjaman[i].jumlahPinjam -= jumlahKembali;

                printf("\n-- Pengembalian Berhasil! --\n");
                printf("Nama Peminjam : %s\n", nama);
                printf("Kelas / Guru  : %s\n", daftarPeminjaman[i].Kelas);
                printf("Nama Buku     : %s\n", daftarPeminjaman[i].JudulBuku);
                printf("Kode Buku     : %s\n", kode);
                printf("Jumlah Kembali: %d\n", jumlahKembali);

                // Jika semua buku sudah dikembalikan, hapus data peminjaman
                if (daftarPeminjaman[i].jumlahPinjam == 0) {
                    printf("\n-- Semua buku telah dikembalikan! Data peminjaman dihapus. --\n");

                    // Geser data peminjaman
                    for (int k = i; k < totalPeminjaman - 1; k++) {
                        daftarPeminjaman[k] = daftarPeminjaman[k + 1];
                    }
                    totalPeminjaman--;
                } else {
                    printf("Sisa Pinjaman : %d buku\n", daftarPeminjaman[i].jumlahPinjam);
                }
            }
            break;
        }
    }

    if (!ditemukan) {
        printf("\n-- Data peminjaman tidak ditemukan! --\n");
        printf("Pastikan nama dan kode buku sudah benar.\n");
    }
}

void daftarBuku() {
    if (totalBuku == 0) {
        printf("\n-- Belum ada buku di perpustakaan --\n");
    }
    printf("\n=== DAFTAR SEMUA BUKU ===\n");
    printf("%-30s %-15s %-8s %-10s %-10s\n", "Judul", "Kode", "Total", "Dipinjam", "Tersedia");  // Printf -> printf
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < totalBuku; i++) {
        int tersedia = perpustakaan[i].jumlahTotal - daftarPeminjaman[i].jumlahPinjam;  // Perpustakaan -> perpustakaan, tambah ;
        printf("%-30s %-15s %-8d %-10d %-10d\n",  // Tambah tanda kutip "
               perpustakaan[i].Judul,              // Perpustakaan -> perpustakaan
               perpustakaan[i].Kode,               // Perpustakaan -> perpustakaan
               perpustakaan[i].jumlahTotal,        // Perpustakaan -> perpustakaan
               daftarPeminjaman[i].jumlahPinjam,     // daftarPeminjaman -> perpustakaan
               tersedia);
        }
        printf("===============================================================\n");

}

void menu();

void selesai() {
    printf("Oke, Terimakasih ;)");
}

void selesaiPerubahan() {
    printf("Perubahan Telah Disimpan, Terimakasih ;)\n");
}

void subMenu1() {
    int subOpsi1;
    printf("\n===OPSI===\n1. Penambahan Buku\n2. Penghapusan Buku\n3. Status Buku\n4. Daftar Buku\n5. Kembali\n6. Selesai\nMasukkan Opsi Anda : ");
    scanf("%d", &subOpsi1);

        switch(subOpsi1) {
            case 1:
                penambahanBuku();
                bubbleSortBuku();
                selesaiPerubahan();
                subMenu1();
                break;
            case 2:
                selesaiPerubahan();
                subMenu1();
                break;
            case 3:
                selesaiPerubahan();
                subMenu1();
                break;
            case 4:
                daftarBuku();
                selesaiPerubahan();
                subMenu1();
                break;
            case 5:
                menu();
                break;
            case 6:
                selesai();
                break;
            default:
                printf("\nTidak ada Opsi %d di dalam daftar Opsi, Silahkan Pilih Kembali");
                subMenu1();
                break;
        }
}

void subMenu2() {
    int subOpsi2;
    printf("\n===OPSI===\n1. Peminjaman Buku2. Pengembalian Buku\n3. Kembali\n4. Selesai\nMasukkan Opsi Anda : ");
    scanf("%d", &subOpsi2);

        switch(subOpsi2) {
            case 1:
                peminjamanBuku();
                selesaiPerubahan();
                subMenu2();
                break;
            case 2:
                pengembalianBuku();
                selesaiPerubahan();
                subMenu2();
                break;
            case 3:
                menu();
                break;
            case 4:
                selesai();
                break;
            default:
                printf("\nTidak ada Opsi %d di dalam daftar Opsi, Silahkan Pilih Kembali");
                subMenu2();
                break;
        }
}

void menu() {
    int opsi;

    printf("\n===OPSI===\n1. Operator\n2. Pengunjung\n3. Selesai\nMasukkan Opsi Anda : ");
    scanf("%d", &opsi);

    switch(opsi) {
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
            printf("\nTidak ada Opsi %d di dalam daftar Opsi, Silahkan Pilih Kembali");
            subMenu1();
            break;
    }
}