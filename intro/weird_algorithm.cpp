#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    while (n != 1) {
        cout << n << " ";
        if (n % 2 != 0) {
            n = (3 * n) + 1;
        } else {
            n /= 2;
        }
    }
    cout << "1\n";

    return 0;
}
