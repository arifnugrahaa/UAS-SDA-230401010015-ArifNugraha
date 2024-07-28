#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct User {
    string nama;
    string alamat;
};

// Fungsi untuk menampilkan data
void display(const vector<User>& data) {
    for (const auto& user : data) {
        cout << user.nama << " | " << user.alamat << endl;
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(vector<User>& data) {
    int n = data.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (data[j].nama > data[j+1].nama) {
                swap(data[j], data[j+1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(vector<User>& data) {
    int n = data.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (data[j].nama < data[min_idx].nama) {
                min_idx = j;
            }
        }
        swap(data[min_idx], data[i]);
    }
}

// fungsi untuk sorting
void sortData(vector<User>& data, bool useBubbleSort = false) {
    if (useBubbleSort) {
        bubbleSort(data);
    } else {
        selectionSort(data);
    }
}

int main() {
    vector<User> data = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };
    
    cout << "========================================" << endl;
    cout << "=== INI UNTUK DATA AWAL ===" << endl;
    display(data);

    // Bubble Sort
    vector<User> bubbleSortedData = data;
    sortData(bubbleSortedData, true);
    cout << "=== HASIL BUBBLE SORT ===" << endl;
    display(bubbleSortedData);

    // Selection Sort
    vector<User> selectionSortedData = data;
    sortData(selectionSortedData, false);
    cout << "=== HASIL SELECTION SORT ===" << endl;
    display(selectionSortedData);

    cout << "=== TERIMA KASIH ===" << endl;
    return 0;
}
