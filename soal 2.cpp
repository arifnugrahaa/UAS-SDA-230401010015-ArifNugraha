#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi binary search sederhana untuk menemukan semua indeks kemunculan elemen
vector<int> binarySearchAllIndices(const vector<int>& arr, int x) {
    vector<int> indices;
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            // Temukan semua indeks dari elemen yang sama
            int start = mid, end = mid;
            while (start >= 0 && arr[start] == x) {
                indices.push_back(start);
                start--;
            }
            while (end < arr.size() && arr[end] == x) {
                if (end != mid) { // Menghindari duplikasi dari mid
                    indices.push_back(end);
                }
                end++;
            }
            break;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    sort(indices.begin(), indices.end()); // Mengurutkan indeks
    return indices;
}

int main() {
    vector<int> arr = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    
    cout << "Array Sebelum diurutkan: ";
    for (int num : arr) {
        cout << num << ",";
    }
    cout << endl;
    
    sort(arr.begin(), arr.end()); // Mengurutkan array

    // Menampilkan array yang telah diurutkan
    cout << "Array Setelah Diurutkan: ";
    for (int num : arr) {
        cout << num << ",";
    }
    cout << endl;

    int n;
    cout << "===============================================================" << endl;
    cout << "=== SILAHKAN MASUKAN TERLEBIH DAHULU UNTUK JUMLAH TEST CASE ===" << endl;
    cout << "Masukkan jumlah test case: ";
    cin >> n;

    vector<int> testCases(n);
    for (int i = 0; i < n; ++i) {
        cout << "Masukkan Test Case ke-" << i + 1 << ": ";
        cin >> testCases[i];
    }
    
    cout << "===============================================================" << endl;
    cout << "=== BERIKUT UNTUK HASIL ===" << endl;

    // Melakukan pencarian untuk setiap test case
    for (int test : testCases) {
        vector<int> indices = binarySearchAllIndices(arr, test);
        if (!indices.empty()) {
            cout << "Angka " << test << " ada di indeks ke ";
            for (size_t i = 0; i < indices.size(); ++i) {
                cout << indices[i];
                if (i < indices.size() - 1) {
                    cout << " dan ";
                }
            }
            cout << endl;
        } else {
            cout << "Angka " << test << " tidak ada dalam array" << endl;
        }
    }
    
    cout << "=== TERIMA KASIH ===" << endl;
    return 0;
}
