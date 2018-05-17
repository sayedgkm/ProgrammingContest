#include<bits/stdc++.h>
using namespace std;
int ar[100100];
int main(){
    srand(time(0));
    freopen("in.txt","w",stdout);
    int test = 1;
    cout<<test<<endl;
    while(test--){
        int n= 100000;
        cout<<n<<endl;
        for(int i= n;i>=1;i--) {
            ar[i] = rand();
        }
            swap(ar[n],ar[n-1]);
        for(int  i = 1;i<=n;i++) cout<<ar[i]<<" ";
        cout<<endl;
    }

    return 0;
}
