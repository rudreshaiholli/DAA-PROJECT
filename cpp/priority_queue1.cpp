#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> load;
    load.push(300);
    load.push(150);
    load.push(500);

    cout << "Peak Load: " << load.top();
    return 0;
}
