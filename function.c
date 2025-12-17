#include <stdio.h>
#include <string.h>
#include "function.h"

// Struct untuk data buku
struct Buku {
    char Judul[50];
    char Kode[20];
    int Jumlah;
};

// Struct untuk data peminjaman
struct Peminjaman {
    char NamaPeminjam[50];
    char KodeBuku[20];
    char JudulBuku[50];
    int JumlahPinjam;
};

struct Buku perpustakaan[100];
struct Peminjaman daftarPeminjaman[200];
int totalBuku = 0;
int totalPeminjaman = 0;

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

void daftarPeminjam() {
    if (totalPeminjaman == 0) {
        printf("\n-- Belum ada data peminjaman --\n");
        return;
    }
    
    printf("\n=== DAFTAR PEMINJAMAN ===\n");
    printf("%-30s %-20s %-30s %-8s\n", "Nama Peminjam", "Kode Buku", "Judul Buku", "Jumlah");
    printf("------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < totalPeminjaman; i++) {
        printf("%-30s %-20s %-30s %-8d\n",
               daftarPeminjaman[i].NamaPeminjam,
               daftarPeminjaman[i].KodeBuku,
               daftarPeminjaman[i].JudulBuku,
               daftarPeminjaman[i].JumlahPinjam);
    }
    printf("====================================================================================\n");
}

void cariPeminjam() {
    char nama[50];
    int ditemukan = 0;
    
    printf("\n--- Cari Data Peminjaman ---\n");
    printf("Masukkan Nama Peminjam : ");
    scanf(" %[^\n]", nama);
    
    printf("\n=== HASIL PENCARIAN ===\n");
    
    for (int i = 0; i < totalPeminjaman; i++) {
        if (strstr(daftarPeminjaman[i].NamaPeminjam, nama) != NULL) {
            if (!ditemukan) {
                printf("%-30s %-20s %-30s %-8s\n", "Nama Peminjam", "Kode Buku", "Judul Buku", "Jumlah");
                printf("------------------------------------------------------------------------------------\n");
            }
            printf("%-30s %-20s %-30s %-8d\n",
                   daftarPeminjaman[i].NamaPeminjam,
                   daftarPeminjaman[i].KodeBuku,
                   daftarPeminjaman[i].JudulBuku,
                   daftarPeminjaman[i].JumlahPinjam);
            ditemukan = 1;
        }
    }
    
    if (!ditemukan) {
        printf("-- Tidak ada peminjaman atas nama '%s' --\n", nama);
    } else {
        printf("====================================================================================\n");
    }
}