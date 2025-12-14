#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    vector<double> features;
    int label;
};

double distance(const vector<double>& a, const vector<double>& b) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++)
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    return sqrt(sum);
}

int main() {
    vector<Point> data = {
        {{1,2},0}, {{2,3},0}, {{3,3},1}, {{6,5},1}
    };
    vector<double> q = {2.5, 2.7};
    int k = 3;

    vector<pair<double,int>> d;
    for (auto &p : data)
        d.push_back({distance(p.features,q), p.label});

    sort(d.begin(), d.end());
    cout << d[0].second;
    return 0;
}
