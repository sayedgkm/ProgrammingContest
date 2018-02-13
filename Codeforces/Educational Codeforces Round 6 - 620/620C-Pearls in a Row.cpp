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
#define        ff                    first
#define        ss                    second
#define        pb                    push_back
using namespace std;
ll ar[N];
map<ll,int> mp;
map<ll,int>:: iterator it;
int main()
{
    take1(n);
    f(i,0,n){
       cin>>ar[i];
    }
    int p=0;
    int x=1,y=0;
    vector<pii> v;
    p=0;
    f(i,0,n){
        mp[ar[i]]++;
        if(mp[ar[i]]==2){
            y=i+1;
            v.pb(pii(x,y));
              mp.clear();
             x=i+2;
        }

    }
    if(!v.size()){
    puts("-1");return 0;
    }
    cout<<v.size()<<endl;
    f(i,0,v.size()){
        if(i==v.size()-1)
         cout<<v[i].ff<<" "<<n<<endl;
        else
        cout<<v[i].ff<<" "<<v[i].ss<<endl;
    }
   return 0;
}