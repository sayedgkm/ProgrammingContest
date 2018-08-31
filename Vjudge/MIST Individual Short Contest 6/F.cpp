 /// Bismillahir-Rahmanir-Rahim
#include <iostream>
#include <stdio.h>
#include <vector>

inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
using namespace std;
///******************************************START******************************************
int ar[10005];
vector<int> ans;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n= nxt();
    for(int i = 0;i<n;i++)ar[i] = nxt();
    int c = 1;
    ar[n]=1000000;
    for(int i = 1;i<=n;i++) {
        if(ar[i]!=ar[i-1]) {
            ans.push_back(c);
            ans.push_back(ar[i-1]);
            c= 1;
        } else c++;
    }
    for(int i =0;i<ans.size();i++) {
        if(i)printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");

    return 0;
}
