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
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
using namespace std;
class ppp{
public:
 ll val;

 ll tree[4 * N];
 void update(int node, int low, int hi, int i, ll value){

  if (low == hi){
   tree[node] = min(val, tree[node]+value); return;
  }
  int mid = (low + hi) / 2;
  int left = 2 * node;
  int right = left + 1;
  if (i <= mid)
   update(left, low, mid, i, value);
  else
   update(right, mid + 1, hi, i, value);
  tree[node] = tree[left] + tree[right];
 }
 ll query(int node, int low, int hi, int i, int j){
  if (i>hi || j<low) return 0;
  if (low >= i&&hi <= j)
   return tree[node];
  int mid = (low + hi) / 2;
  int left = 2 * node;
  int right = left + 1;
  int x = query(left, low, mid, i, j);
  int y = query(right, mid + 1, hi, i, j);
  return x + y;

 }
}s1, s2;
int main()
{
 int n, k, a, b, q;
 take4(n, k, a, b);
 take1(q);
 s1.val = b;
 s2.val = a;
 while (q--){
  int x;
  take1(x);
  if (x == 1){
   int p, q;
   take2(p, q);
   s1.update(1, 1, n, p, q);
   s2.update(1, 1, n, p, q);

  }
  else{
   int p;
   take1(p); ll ans;
   if (p == 1)
    ans = 0;
   else
    ans = s1.query(1, 1, n, 1, p - 1);
   ans += s2.query(1, 1, n, p + k, n);
   printf("%I64d\n", ans);
  }

 }
 return 0;
}