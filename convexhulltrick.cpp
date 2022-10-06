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

void file(){
  freopen("baoloi.inp", "r", stdin);
  freopen("baoloi.out", "w", stdout);
}

int n, qr;
ii a[N];
vector<int> q;

bool bad(int l1, int l2, int l3){
  return ld(a[l3].Y - a[l1].Y) / (a[l1].X - a[l3].X) > ld(a[l2].Y - a[l1].Y) / (a[l1].X - a[l2].X);
}

void addLine(int i){
  if(q.size() < 2) q.pb(i);
  else{
    while(q.size() >= 2 && bad(q[(int)q.size() - 2], q.back(), i)) q.pop_back();
    q.pb(i);
  }
}

ll solve(int x){
  int l = 1, r = q.size() - 1, pos = 0;
  ll res = 1ll * a[q[pos]].X * x + a[q[pos]].Y;
  while(l <= r){
    int mid = (l + r) / 2;
    res = max(res, 1ll * a[q[mid]].X * x + a[q[mid]].Y);
    if(1ll * a[q[mid]].X * x + a[q[mid]].Y < 1ll * a[q[mid - 1]].X * x + a[q[mid - 1]].Y){
      r = mid - 1;
    }
    else{
      pos = mid;
      l = mid + 1;
    }
  }
  return res;
}

bool cmp(ii x, ii y){
  if(x.X == y.X) return x.Y > y.Y;
  return x.X > y.X;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  file();
  cin >> n >> qr;
  for(int i = 1; i <= n; ++i){
    cin >> a[i].X >> a[i].Y;
  }
  sort(a + 1, a + n + 1, cmp);
  for(int i = 1; i <= n; ++i){
    addLine(i);
  }
  for(int i = 1; i <= qr; ++i){
    int x; cin >> x;
    cout << solve(x) << '\n';
  }
  return 0;
}
