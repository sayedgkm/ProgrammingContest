#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define f(x,y,z) for(int x=y;x<z;x++)
#define N 100010
using namespace std;
pair<int, int> ar[N];
int main()
{
    int a, b;
    cin >> a >> b;
    f(i, 0, a) cin >> ar[i].first >> ar[i].second;
    ar[a].first = b;
    sort(ar, ar + a);
    long long sum = 0;
    for(int i = a - 1; i >= 0; i--){
        sum += ar[i + 1].first - ar[i].first;
        if (ar[i].second > sum)
            sum += ar[i].second - sum;
}
    sum += ar[0].first - 0;

    cout << sum << endl;
    return 0;
}