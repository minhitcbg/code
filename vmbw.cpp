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
const int   N   = 1e5 + 5;

int n, m, q, state[N], tmp[2][2], res[2][2], d[N][2], ans[2][2], deg[N], LM;
vector<int> adj[N], dsk[N], rev[N];
vector<ii>  edges;

void file(){
  freopen(".inp", "r", stdin);
  freopen(".out", "w", stdout);
}

void solve(){
  for(ii x : edges){
    int u = x.X, v = x.Y;
    if(deg[u] > deg[v]) swap(u, v);
    if(deg[u] < LM && deg[v] < LM){
      res[min(state[u], state[v])][max(state[u], state[v])]++;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    else if(deg[u] < LM){
      d[v][state[u]]++;
      tmp[min(state[u], state[v])][max(state[u], state[v])]++;
      rev[u].pb(v);
    }
    else{
      dsk[u].pb(v);
      dsk[v].pb(u);
      ans[min(state[u], state[v])][max(state[u], state[v])]++;
    }
  }
  cin >> q;
  for(int i = 1; i <= q; ++i){
    string type; cin >> type;
    if(type == "print"){
      int u, v; cin >> u >> v;
      if(u > v) swap(u, v);
      cout << tmp[u][v] + res[u][v] + ans[u][v] << '\n';
    }
    else{
      int u; cin >> u;
      if(deg[u] < LM){
        for(int v : adj[u]){
          res[min(state[u], state[v])][max(state[u], state[v])]--;
          res[min(1 ^ state[u], state[v])][max(1 ^ state[u], state[v])]++;
        }
        for(int v : rev[u]){
          d[v][state[u]]--;
          tmp[min(state[u], state[v])][max(state[u], state[v])]--;
          d[v][1 ^ state[u]]++;
          tmp[min(1 ^ state[u], state[v])][max(1 ^ state[u], state[v])]++;
        }
        state[u] ^= 1;
      }
      else{
        for(int v : dsk[u]){
          ans[min(state[u], state[v])][max(state[u], state[v])]--;
          ans[min(1 ^ state[u], state[v])][max(1 ^ state[u], state[v])]++;
        }
        if(state[u] == 0){
          tmp[0][0] -= d[u][0];
          tmp[0][1] += d[u][0];
          tmp[0][1] -= d[u][1];
          tmp[1][1] += d[u][1];
        }
        else{
          tmp[0][1] -= d[u][0];
          tmp[0][0] += d[u][0];
          tmp[1][1] -= d[u][1];
          tmp[0][1] += d[u][1];
        }
        state[u] ^= 1;
      }
    }
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= m; ++i){
    int u, v; cin >> u >> v;
    edges.pb(ii(u, v));
    deg[u]++;
    deg[v]++;
  }
  for(int i = 1; i <= n; ++i) cin >> state[i];
  LM = sqrt(2 * m);
  solve();
}
