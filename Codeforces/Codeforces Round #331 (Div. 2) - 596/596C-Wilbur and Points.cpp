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
#define pii pair<ll,ll>
using namespace std;
;map<ll,vector<pii> > m;  pii res[100000+5];
int main()
   {
     take1(n);int a,b,w;
     f(i,0,n)
        {
            cin>>a>>b;
            m[b-a].push_back(pii(a,b));
        }
        f(i,0,n) sort(m[i].begin(),m[i].end());
      f(i,0,n) {
            cin>>w;
            if(m[w].empty()) {
                puts("NO");
                return 0;
            }
         res[i].first=m[w][0].first;
          res[i].second=m[w][0].second;
          m[w].erase(m[w].begin());

        }
            f(i,1,n)
            {
                if(res[i].first<=res[i-1].first&&res[i].second<=res[i-1].second)
                {
                    puts("NO");
                    return 0;
                }

            }
            puts("YES");
            f(i,0,n)
              cout<<res[i].first<<" "<<res[i].second<<endl;

}