// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================

#include <bits/stdc++.h>
#define        ll                    long long
#define        f(x,y,z)              for(int x=y;x<z;x++)
#define        take1(a);             int a;scanf("%d",&a);
#define        take2(a,b);           int a;int b;scanf("%d%d",&a,&b);
#define        take3(a,b,c);         int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);       int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     1000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
vector<ll> p;queue<ll>temp;map<ll,int> q;
void fun(ll num){
    p.push_back(num);
    temp.push(num);
    for (int i = 0; num<1e9 + 10; i++)
    {
        int v = temp.size();
        while (v--){
            ll first = temp.front(); temp.pop();
            num =first* 10+4;
            p.push_back(num);
            temp.push(num);
            num += 3;
            p.push_back(num);
            temp.push(num);

        }

    }
}
int main()
{
   fun(4);
   while(!temp.empty()) temp.pop();
    fun(7);
   sort(p.begin(),p.end());
   f(i,0,p.size())
       q[p[i]]=i+1;
   take1(n);
   cout<<q[n]<<endl;

return 0;
}