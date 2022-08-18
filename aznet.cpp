/* VOI focus mode */

#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define all(x)  x.begin(), x.end()

#define pb  push_back

const int   inf = 1e9;
const int   mod = 1e9 + 7;
const int   N   = 1e5 + 5;

int n, m;
int a[N], b[N], chs[N];
struct ii{
  int X, Y, id;
  ii(){};
  ii(int _X, int _Y, int _id){X = _X, Y = _Y, id = _id;}
};
vector<ii> edges[3];

struct DSU{
  int p[N];

  void init(){
    for(int i = 1; i <= n; ++i) p[i] = i;
  }

  int par(int a){
    if(a == p[a]) return a;
    return p[a] = par(p[a]);
  }

  void join(int a, int b){
    a = par(a), b = par(b);
    p[b] = a;
  }
} itk30;

void file(){
  freopen(".inp", "r", stdin);
  freopen(".out", "w", stdout);
}

void solve(){
  edges[0].clear(); edges[1].clear();
  cin >> n >> m;
  for(int i = 1; i < n; ++i) cin >> a[i];
  for(int i = 1; i < n; ++i) cin >> b[i];
  for(int i = 1; i <= m; ++i){
    int u, v, c;
    cin >> u >> v >> c;
    --c;
    edges[c].pb(ii(u, v, i));
  }
  int res = 2e9 + 2;
  int cntA = 0, cntB = 0, x;
  itk30.init();
  for(ii x : edges[0]){
    int u = x.X, v = x.Y;
    if(itk30.par(u) != itk30.par(v)){
      itk30.join(u, v);
      cntA++;
    }
  }
  itk30.init();
  for(int i = 0; i < edges[1].size(); ++i){
    ii x = edges[1][i];
    int u = x.X, v = x.Y;
    if(itk30.par(u) != itk30.par(v)){
      itk30.join(u, v);
      cntB++;
    }
  }
  for(int i = n - 1 - cntB; i <= min(n - 1, cntA); ++i){
    if(res > a[i] + b[n - i - 1]){
      res = a[i] + b[n - i - 1];
      x = i;
    }
  }
  itk30.init();
   for(ii x : edges[0]){
    int u = x.X, v = x.Y;
    if(itk30.par(u) != itk30.par(v)){
      itk30.join(u, v);
    }
  }
  for(int i = 0; i < edges[1].size(); ++i){
    int u = edges[1][i].X, v = edges[1][i].Y, id = edges[1][i].id;
    if(itk30.par(u) != itk30.par(v)){
      itk30.join(u, v);
      chs[id] = 1;
    }
  }
  itk30.init();
  cntB = 0;
  for(int i = 0; i < edges[1].size(); ++i){
    int u = edges[1][i].X, v = edges[1][i].Y, id = edges[1][i].id;
    if(chs[id]){
      itk30.join(u, v);
      cntB++;
    }
  }
  for(int i = 0; i < edges[1].size(); ++i){
    if(chs[edges[1][i].id]) continue;
    if(cntB == n - x - 1) break;
    if(itk30.par(edges[1][i].X) == itk30.par(edges[1][i].Y)) continue;
    itk30.join(edges[1][i].X, edges[1][i].Y);
    chs[edges[1][i].id] = 1;
    ++cntB;
  }
  for(int i = 0; i < edges[0].size(); ++i){
    int u = edges[0][i].X, v = edges[0][i].Y, id = edges[0][i].id;
    if(itk30.par(u) != itk30.par(v)){
      itk30.join(u, v);
      chs[id] = 1;
    }
  }
  for(int i = 1; i <= m; ++i){
    if(chs[i]) cout << i << " ", chs[i] = 0;
  }
  cout << '\n';
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int tc; cin >> tc;
  while(tc--) solve();
}
