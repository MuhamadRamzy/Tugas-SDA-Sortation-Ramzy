#include <iostream>
using namespace std;

// Fungsi untuk menampilkan array
void tampilkanArray(int data[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Fungsi Selection Sort dengan langkah
void selectionSort(int data[], int jumlah) {
    cout << "\n-- Proses Selection Sort --\n";
    for (int i = 0; i < jumlah - 1; i++) {
        int indeksMin = i;
        for (int j = i + 1; j < jumlah; j++) {
            if (data[j] < data[indeksMin]) {
                indeksMin = j;
            }
        }
        cout << "Langkah " << i + 1 << ": Tukar data[" << i << "]=" << data[i]
             << " dengan data[" << indeksMin << "]=" << data[indeksMin] << endl;
        swap(data[i], data[indeksMin]);
        tampilkanArray(data, jumlah);
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
    tampilkanArray(data, jumlah);

    selectionSort(data, jumlah);

    cout << "Data setelah diurutkan: ";
    tampilkanArray(data, jumlah);

    delete[] data;
    return 0;
}

