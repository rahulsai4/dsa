#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n;

	set<int> st;
	st.insert(0);
	long long res = 0;
	while (n--) {
		cin >> x;
		int dist = INT_MAX;
		auto lit = st.lower_bound(x);
		if (lit != st.end()) {
			dist = min(dist, *lit - x);
		}
		if (lit != st.begin()) {
			lit--;
			dist = min(dist, *lit - x);
		}
		res += (dist);
	}
	cout << res << endl;
}