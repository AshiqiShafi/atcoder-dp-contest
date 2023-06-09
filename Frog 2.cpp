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

int dp[N], n, k;
int h[N];

int yo (int i) {
  if (i == n) return 0;
  if (dp[i] != -1) return dp[i];
  int ret = 1e9;
  for (int j = 1; j <= k; j++) {
    if (i + j <= n) {
      ret = min(ret, abs(h[i] - h[i + j]) + yo(i + j));
    }
  }
  return dp[i] = ret;
}

inline void solve () {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << yo(1) << '\n';
} 

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1; //cin >> T;
  while (T--) solve();
  return 0;
}
