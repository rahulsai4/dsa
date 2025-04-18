#include <iostream>
#include <string>
using namespace std;

int main() {
    string t;
    cin >> t;

    int res = 0;
    int i = 0;
    
    while (i < t.length()) {
        char c = t[i];
        int j = i;
        while (j < t.length() && t[j] == c) j++;
        res = max(res, j - i);
        i = j;
    }

    cout << res << endl;

    return 0;
}
