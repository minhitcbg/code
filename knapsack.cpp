#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define all(x)  x.begin(), x.end()
#define ii      pair<int, int>

#define pb  push_back
#define X   first
#define Y   second

const int   inf = 1e9;
const int   mod = 1e9 + 7;
const int   N   = 1e2 + 5;
const int   M   = 2e3 + 5;

int n, m, v[N], c[N];
int dp[N][M];
vector<int> adj[N];

void file(){
  freopen(".inp", "r", stdin);
  freopen(".out", "w", stdout);
}

void dfs(int u, int p){
  for(int i = 0; i <= m; ++i) dp[u][i] = dp[p][i];
  for(int v : adj[u]){
    if(v == p) continue;
    dfs(v, u);
  }
  for(int i = 0; i + c[u] <= m; ++i){
    if(dp[u][i] != -1){
      dp[p][i + c[u]] = max(dp[p][i + c[u]], dp[u][i] + v[u]);
    }
  }
}

void solve(){
  dfs(1, 0);
  cout << *max_element(dp[1] + 0, dp[1] + m + 1);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 2; i <= n; ++i) cin >> v[i];
  for(int i = 2; i <= n; ++i) cin >> c[i];
  for(int i = 1; i < n; ++i){
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  solve();
}
