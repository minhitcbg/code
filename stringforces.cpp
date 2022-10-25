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
const int   N   = 2e5 + 5;

int n, k, nextpos[N][30], dp[N];
string s;

void file(){
  freopen(".inp", "r", stdin);
  freopen(".out", "w", stdout);
}

bool check(int len){
  int mask = (1 << k) - 1;
  for(int i = 0; i <= mask; ++i) dp[i] = inf;
  dp[0] = 0;

  for(int i = 1; i <= n + 1; ++i){
    for(int j = 0; j < k; ++j) nextpos[i][j] = n + 1;
  }
  for(int ch = 0; ch < k; ++ch){
    int p = n + 1;
    for(int i = n; i >= 1; --i){
      if(s[i] != char('a' + ch) && s[i] != '?'){
        p = i;
        nextpos[i][ch] = nextpos[i + 1][ch];
      }
      else{
        if(p - i >= len){
          nextpos[i][ch] = i + len - 1;
        }
        else{
          nextpos[i][ch] = nextpos[i + 1][ch];
        }
      }
    }
  }

//  for(int ch = 0; ch < k; ++ch){
//    for(int i = 1; i <= n; ++i) cout << nextpos[i][ch] << " ";
//    cout << '\n';
//  }

  for(int i = 0; i <= mask; ++i){
    if(dp[i] == inf) continue;
    for(int j = 0; j < k; ++j){
      if(!(i >> j & 1)){
        int newi = i | (1 << j);
        dp[newi] = min(dp[newi], nextpos[min(dp[i] + 1, n + 1)][j]);
      }
    }
  }

//  cout << nextpos[2][1] << '\n';

//  cout << dp[1] << '\n';

//  for(int i = 0; i <= mask; ++i) cout << dp[i] << " "; cout << '\n';

//  cout << dp[mask] << '\n';

  return dp[mask] <= n;
}

void solve(){
  int l = 1, r = n, ans = 0;

  while(l <= r){
    int mid = (l + r) / 2;

    if(check(mid)){
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }

//  cout << check(2) << '\n';

  cout << ans;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k >> s;
  s = " " + s;
  solve();
}
