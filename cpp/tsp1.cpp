#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n = 4;
int dist[4][4] = {
    {0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}
};

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) return dist[pos][0];
    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
        if (!(mask & (1 << city)))
            ans = min(ans, dist[pos][city] +
                tsp(mask | (1 << city), city));
    return ans;
}

int main() {
    cout << tsp(1, 0);
}
