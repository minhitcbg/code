#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b)  for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)

#define ll            long long
#define ld            double

#define all(x)        x.begin(), x.end()
#define ii            pair<int, int>

#define pb            push_back
#define X             first
#define Y             second

const int   INF  = 1e9;
const int   mod  = 1e9 + 7;

void file(){
  freopen(".inp", "r", stdin);
  freopen(".out", "w", stdout);
}

string A, B;

struct BIGNUM{
  int StringToNum(char x){return (x - '0');}
  char NumtoString(int x){return char(x + '0');}
  void standard(string &a, string &b){
    while((int)a.size() < (int)b.size()) a = "0" + a;
    while((int)b.size() < (int)a.size()) b = "0" + b;
  }
  bool cmp(string a, string b){
    FOR(i, 0, (int)a.size() - 1){
      if(a[i] > b[i]) return 1;
      if(a[i] < b[i]) return 0;
    }
    return 1;
  }

  string sum(string a, string b){
    standard(a, b);
    int temp = 0, l = (int)a.size();
    string res = "";
    FORD(i, l - 1, 0){
      temp = StringToNum(a[i]) + StringToNum(b[i]) + temp;
      res += NumtoString(temp % 10);
      temp /= 10;
    }
    if(temp > 0) res += NumtoString(temp % 10);
    reverse(all(res));
    return res;
  }

  string sub(string a, string b){
    standard(a, b);
    bool ok = cmp(a, b);
    if(!ok) swap(a, b);
    int temp = 0, l = (int)a.size();
    string res = "";
    FORD(i, l - 1, 0){
      temp = StringToNum(a[i]) - StringToNum(b[i]) - temp;
      if(temp < 0){
        temp += 10;
        res += NumtoString(temp);
        temp = 1;
      }
      else{
        res += NumtoString(temp);
        temp = 0;
      }
    }
    while((int)res.size() > 1 && res.back() == '0') res.pop_back();
    if(!ok) res += "-";
    reverse(all(res));
    return res;
  }

  string small_multiple(char x, string b){
    string res = "";
    int temp = 0, l = (int)b.size();
    FORD(i, l - 1, 0){
      temp = StringToNum(x) * StringToNum(b[i]) + temp;
      res += NumtoString(temp % 10);
      temp /= 10;
    }
    if(temp > 0) res += NumtoString(temp % 10);
    reverse(all(res));
    return res;
  }

  string multiple(string a, string b){
    int l = (int)a.size();
    string res = "";
    FORD(i, l - 1, 0){
      string tmp = small_multiple(a[i], b);
      FOR(j, 1, l - i - 1) tmp += "0";
      standard(res, tmp);
      res = sum(res, tmp);
    }
    return res;
  }

} big;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> A >> B;
  cout << big.sum(A, B) << '\n' << big.sub(A, B) << '\n' << big.multiple(A, B) << '\n';
}
