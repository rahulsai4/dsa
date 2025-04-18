#include <iostream>

using namespace std;

int main() {
    long long n, sum = 0;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;
        sum += num;
    }

    cout << (n * (n + 1) / 2) - sum << endl;

    return 0;
}
