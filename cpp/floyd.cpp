#include <iostream>
using namespace std;

int partition(int a[], int l, int h) {
    int p = a[h], i = l - 1;
    for (int j = l; j < h; j++)
        if (a[j] <= p) swap(a[++i], a[j]);
    swap(a[i + 1], a[h]);
    return i + 1;
}

void quickSort(int a[], int l, int h) {
    if (l < h) {
        int pi = partition(a, l, h);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, h);
    }
}

int main() {
    int a[] = {40, 10, 30, 20};
    quickSort(a, 0, 3);
    for (int x : a) cout << x << " ";
}
