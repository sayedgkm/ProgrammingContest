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
vector<pii>v;
int main()
{
 ll a, b, c;
 cin >> a >> b >> c;
 if (b == 1 && c == 1 && a>2){
  puts("-1");
  return 0;
 }
 if (b>c * 2){
  puts("-1");
  return 0;
 }
 if (b<c){
  puts("-1");
  return 0;
 }
 int node = 1; int i = 1;
 for (i = 1; i <= c; i++){
  v.pb(pii(i, i + 1)); node++;
 }
 int temp = b - c+i;
 int check = 0; i++;
 for (; i <= temp; i++){
  if (!check){
   v.pb(pii(1, i));
   check = 1;
  }
  else v.pb(pii(i-1, i));
  node++;

 }
 if (node>a) {
  puts("-1");
  return 0;
 }
 while (node != a){
            if(c!=b)
  v.pb(pii(1, i++));
    else v.pb(pii(2,i++));
  node++;
 }
 for (int i = 0; i<v.size(); i++)
  cout << v[i].ff << " " << v[i].ss << endl;
 return 0;
}