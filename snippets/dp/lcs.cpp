#include <bits/stdc++.h>
using namespace std;

// subsequence 
int lcs(string &s, string &t, int n, int m) {
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
			} else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[n][m];
}

// printing subsequence
string print_lcs(string &s, string &t, int n, int m) {
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

    string res = "";
    int i = n;
    int j = m;

    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1]){
            res += s[i - 1];
            --i;
            --j;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            --i;
        }
        else{
            --j;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

// substring
int lcs(string &s, string &t, int n, int m) {
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
				res = max(res, dp[i][j]);
			} else{
				dp[i][j] = 0;
            }
		}
	}
	return res;
}