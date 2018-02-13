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
using namespace std;
int main()
   {
       deque<int> p,q;
     take1(a);
     take1(b);
     while(b--)
     {
         take1(c);p.push_back(c);
     }
     take1(d);
     while(d--)
     {
         take1(c);q.push_back(c);

    }
    ll counter=0;
    while(1)
    {
        int x=p.front();
        int y=q.front();
        //cout<< x<< " "<<y<<endl;
        p.pop_front();
        q.pop_front();
        if(x>y)
        {
           p.push_back(y);
           p.push_back(x);

        }
        else
        {
            q.push_back(x);
           q.push_back(y);

        }
        counter++;
        if(counter>(1<<15)){
            puts("-1"); return 0;
        }
        if(p.empty()||q.empty()) break;
    }
    if(p.empty())
        cout<<counter<<" 2"<<endl;
    else
        cout<<counter<<" 1"<<endl;


}