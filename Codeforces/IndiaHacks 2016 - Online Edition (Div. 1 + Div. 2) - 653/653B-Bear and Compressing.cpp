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
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
inline int nxt(){
  int aaa;
  scanf("%d",&aaa);
  return aaa;
}
map<string,vector<string> > mp;
int main()
{
 int n = nxt();
 int k = nxt();
 string a, b;
 f(i, 0, k){
  cin >> a >> b;
  mp[b].pb(a);
 }
 vector<string> temp1, temp2;
 for (int i = 0; i<mp["a"].size(); i++){
  temp1.pb(mp["a"][i]);
 }
 n-=2;
 int flag = 0; string q;
 while (n--){

  for (int i = 0; i < temp1.size(); i++){
   char p = temp1[i][0];
   q.pb(p);
   if (!mp[q].empty()){
    for (int j = 0; j < mp[q].size(); j++){
     temp2.pb(mp[q][j]);

    }
   }
   q.clear();
  }

   if (temp2.size() == 0){
    flag = 1;
    break;
   }
   temp1.clear();
   temp1 = temp2;
   temp2.clear();

 }
 if (flag) puts("0");
 else cout << temp1.size() << endl;
 return 0;
}