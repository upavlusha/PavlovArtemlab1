#include <iostream>

using namespace std;

int get(int** a, int n, int i, int j) {
    if (i + j < n - 1) {
        return 0;
    }
    return a[i][j - (n - 1 - i)];
}

int main() {
    int n;
    cout << "Vvedite n: ";
    cin >> n;

    if (n <= 0 || n > 10) {
        cout << "Error" << endl;
        return 1;
    }

    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[i + 1];
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < i + 1; k++) {
            int j = n - 1 - i + k;
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][k];
        }
    }

    cout << "\nMatritsa:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << get(a, n, i, j) << "\t";
        }
        cout << "\n";
    }

    cout << "\nSummy strok:\n";
    for (int i = 0; i < n; i++) {
        bool neg = false;
        int s = 0;
        for (int j = 0; j < n; j++) {
            int val = get(a, n, i, j);
            if (val < 0) {
                neg = true;
            }
            s += val;
        }
        if (!neg) {
            cout << "Stroka " << i << ": " << s << endl;
        }
    }

    if (n > 1) {
        int mn = get(a, n, 0, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int x = get(a, n, i, j);
                    if (x < mn) {
                        mn = x;
                    }
                }
            }
        }
        cout << "\nMin: " << mn << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}