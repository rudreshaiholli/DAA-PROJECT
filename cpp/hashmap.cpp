#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> complaints;
    complaints["Water"]++;
    complaints["Electricity"]++;
    complaints["Water"]++;

    cout << "Water Complaints: " << complaints["Water"];
    return 0;
}
