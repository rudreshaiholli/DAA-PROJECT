#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

double dist(vector<double> a, vector<double> b) {
    double s = 0;
    for (int i = 0; i < a.size(); i++)
        s += pow(a[i] - b[i], 2);
    return sqrt(s);
}

int main() {
    vector<vector<double>> data = {{1,2},{2,3},{5,6}};
    vector<int> label = {0,0,1};
    vector<double> q = {2,2};

    int best = 0;
    double d = 1e9;
    for (int i = 0; i < data.size(); i++) {
        double cd = dist(data[i], q);
        if (cd < d) d = cd, best = label[i];
    }

    cout << best;
}
