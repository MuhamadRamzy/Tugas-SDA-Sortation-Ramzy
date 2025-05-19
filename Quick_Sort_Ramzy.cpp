#include <iostream>
using namespace std;

// Fungsi untuk mencetak array
void cetakArray(int arr[], int jumlah) {
    for (int i = 0; i < jumlah; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Fungsi untuk membagi array dan menentukan posisi pivot
int partisi(int arr[], int kiri, int kanan, int &langkah) {
    int pivot = arr[kanan]; // pivot adalah elemen paling kanan
    int i = kiri - 1;

    cout << "Langkah " << langkah++ << ": pivot = " << pivot << " di indeks " << kanan << endl;

    for (int j = kiri; j < kanan; ++j) {
        if (arr[j] <= pivot) {
            i++;
            cout << "  Tukar arr[" << i << "]=" << arr[i] << " dengan arr[" << j << "]=" << arr[j] << endl;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[kanan]);
    cout << "  Pindah pivot ke indeks " << i + 1 << endl;
    cetakArray(arr, kanan + 1); // Cetak sampai indeks terakhir saat ini

    return i + 1;
}

// Fungsi Quick Sort rekursif
void quickSort(int arr[], int kiri, int kanan, int &langkah, int jumlah) {
    if (kiri < kanan) {
        int indeksPivot = partisi(arr, kiri, kanan, langkah);
        quickSort(arr, kiri, indeksPivot - 1, langkah, jumlah);
        quickSort(arr, indeksPivot + 1, kanan, langkah, jumlah);
    }
}

// Fungsi utama
int main() {
    int jumlah;
    cout << "Masukkan jumlah elemen: ";
    cin >> jumlah;

    int* data = new int[jumlah];
    for (int i = 0; i < jumlah; ++i) {
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    cout << "\nSebelum diurutkan: ";
    cetakArray(data, jumlah);

    int langkah = 1;
    cout << "\n-- Proses Quick Sort --\n";
    quickSort(data, 0, jumlah - 1, langkah, jumlah);

    cout << "Setelah diurutkan: ";
    cetakArray(data, jumlah);

    delete[] data;
    return 0;
}

