// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); int a;scanf("%d",&a);
#define take2(a,b); int a;int b;scanf("%d%d",&a,&b);
#define take3(a,b,c); int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define pii pair<int,int>
using namespace std;
priority_queue<pii> res;map<int,int> mp; map<int,vector<int> >ans;
int main()
   {
   take1(n);
   while(n--)
   {
       take1(a);
       mp[a]++;
    }
    for(map<int,int>:: reverse_iterator it=mp.rbegin();it!=mp.rend();it++)
            res.push(pii(it->second,it->first));

    int si,index,p=0; pii top[4];
    while(res.size()>=3)
    {
         f(i,0,3)
           {
              top[i]= res.top();res.pop();
               ans[p].push_back(top[i].second);
               top[i].first--;
          }
          f(i,0,3)
            if(top[i].first>0)
                  res.push(pii(top[i]));
                  p++;

    }
    cout<<p<<endl;
    f(i,0,p)
    {
        sort(ans[i].begin(),ans[i].end());
         cout<<ans[i][2]<<" "<<ans[i][1]<<" "<<ans[i][0]<<endl;
    }


}