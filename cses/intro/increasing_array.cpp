#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long res = 0;
    int prev;
    cin >> prev;

    for (int i = 1; i < n; i++) {
        int curr;
        cin >> curr;
        if (curr < prev) {
            res += (prev - curr);
        } else {
            prev = curr;
        }
    }

    cout << res << endl;

    return 0;
}
