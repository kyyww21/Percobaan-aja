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

void selesai() {
    printf("\nOke, Terimakasih ;)\n");
}

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

int main() {
    menu();
    return 0;
}