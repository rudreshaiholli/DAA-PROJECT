#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(3);
    pq.push(10);
    pq.push(1);

    cout << "Highest Priority Outage: " << pq.top();
    return 0;
}
