#include <iostream>
using namespace std;

// Fungsi untuk menampilkan bagian array
void tampilkanSubArray(int data[], int kiri, int kanan) {
    for (int i = kiri; i <= kanan; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Fungsi untuk menggabungkan dua bagian array yang sudah terurut
void gabung(int data[], int kiri, int tengah, int kanan, int &langkah) {
    int panjangKiri = tengah - kiri + 1;
    int panjangKanan = kanan - tengah;

    int* kiriArr = new int[panjangKiri];
    int* kananArr = new int[panjangKanan];

    for (int i = 0; i < panjangKiri; i++) kiriArr[i] = data[kiri + i];
    for (int j = 0; j < panjangKanan; j++) kananArr[j] = data[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;

    cout << "Langkah " << langkah++ << ": Gabungkan indeks [" << kiri << ".." << tengah
         << "] dan [" << tengah + 1 << ".." << kanan << "]\n";

    while (i < panjangKiri && j < panjangKanan) {
        if (kiriArr[i] <= kananArr[j]) {
            data[k++] = kiriArr[i++];
        } else {
            data[k++] = kananArr[j++];
        }
    }

    while (i < panjangKiri) data[k++] = kiriArr[i++];
    while (j < panjangKanan) data[k++] = kananArr[j++];

    tampilkanSubArray(data, kiri, kanan);

    delete[] kiriArr;
    delete[] kananArr;
}

// Fungsi rekursif Merge Sort
void mergeSort(int data[], int kiri, int kanan, int &langkah) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        mergeSort(data, kiri, tengah, langkah);
        mergeSort(data, tengah + 1, kanan, langkah);
        gabung(data, kiri, tengah, kanan, langkah);
    }
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah elemen: ";
    cin >> jumlah;

    int* data = new int[jumlah];
    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    cout << "\nData sebelum diurutkan: ";
    tampilkanSubArray(data, 0, jumlah - 1);

    int langkah = 1;
    cout << "\n-- Proses Merge Sort --\n";
    mergeSort(data, 0, jumlah - 1, langkah);

    cout << "Data setelah diurutkan: ";
    tampilkanSubArray(data, 0, jumlah - 1);

    delete[] data;
    return 0;
}

