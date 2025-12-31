#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int i = 0b00011101;
    cout << "popcount: " << __builtin_popcount(i) << endl;
}