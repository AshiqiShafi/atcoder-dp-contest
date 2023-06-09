#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;

string lcs(string s, string t) {
  int n = s.size(), m = t.size();
  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 or j == 0) {
        dp[i][j] = 0;
      }
      else if (s[i - 1] == t[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  string ans;
  int i = n, j = m;
  while (i > 0 and j > 0) {
    if (s[i - 1] == t[j - 1]) {
      ans.pb(s[i - 1]);
      i--, j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    }
    else {
      j--;
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

inline void solve () {
  string s, t;
  cin >> s >> t;
  cout << lcs(s, t) << '\n';
} 

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1; //cin >> T;
  while (T--) solve();
  return 0;
}
