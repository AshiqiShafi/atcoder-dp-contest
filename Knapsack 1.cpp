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

ll dp[123][N];
int a[N],v[N], n, w;

ll yo (int i, int cur) {
  if (i > n) return 0;
  if (dp[i][cur] != -1) return dp[i][cur];
  ll ret = yo(i + 1, cur);
  if (a[i] + cur <= w) {
    ret = max(ret, v[i] + yo(i + 1, a[i] + cur));
  }
  return dp[i][cur] = ret;
}

inline void solve () {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> v[i];
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
