#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ff first
#define ss second
#define pb push_back
#define pii pair<ll, ll>
#define vi vector<int>
#define vl vector<ll> 

const int mod = 1e9 + 7;
const int N = 1e5 + 123;

int dp[N][4], n;
int h[N][4];

int yo (int i, int k) {
  if (i > n) return 0;
  if (dp[i][k] != -1) return dp[i][k];
  int ret = 0;
  for (int j = 1; j <= 3; j++) {
    if (j != k) {
      ret = max(ret, h[i][j] + yo(i + 1, j));
    }
  }
  return dp[i][k] = ret;
}

inline void solve () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i][1] >> h[i][2] >> h[i][3];
  }
  memset(dp, -1, sizeof(dp));
  cout << yo(1, 0) << '\n';
} 

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1; //cin >> T;
  while (T--) solve();
  return 0;
}
