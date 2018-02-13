// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <class T> inline T bigmod(T p,T e,T m){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    } return (T)ret;
}
inline int nxt(){
  int aaa;
  scanf("%d",&aaa);
  return aaa;
}
int ar[N];
vector<int>v; int n;
bool check1(int i){
 if (i<1) return true;
 if (i>n) return true;
 if (i != n){
  if (i % 2){
   if (ar[i] >= ar[i + 1]) return false;
  }
  else{
   if (ar[i] <= ar[i + 1]) return false;
  }
 }
 return true;
}
bool check(int i, int j){
 if (!check1(i)) return false;
 if (!check1(i - 1)) return false;
 if (!check1(j)) return false;
 if (!check1(j - 1)) return false;
 for (int i = 0; i<v.size(); i++){
  if (!check1(v[i])) return false;
  if (!check1(v[i] - 1)) return false;
 }
 return true;
}
int main()
{
      n = nxt();
 int ans = 0;
 f(i, 1, n + 1) ar[i] = nxt();
 f(i, 1, n){
  if (i % 2){
   if (ar[i] >= ar[i + 1]) v.pb(i);
  }
  else {
   if (ar[i] <= ar[i + 1]) v.pb(i);

  }
 }
  if (v.size()>4) {
   puts("0"); return 0;
  }

  for (int j = 1; j <= n; j++){
   swap(ar[v[0]], ar[j]);
   if (check(v[0], j)) ans++;
   swap(ar[v[0]], ar[j]);
  }
  for (int i = 1; i <= n; i++){
   if (i == v[0]) continue;
   swap(ar[v[0] + 1], ar[i]);
   if (check(v[0] + 1, i)) ans++;
   swap(ar[v[0] + 1], ar[i]);
  }

 cout << ans << endl;
 return 0;
}