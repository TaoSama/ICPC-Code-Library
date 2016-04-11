#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const int N = 2e5+10;

int n,a[N],dp[N][2];

int main()
{
#ifndef LOCAL
    //freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n)
    {
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;++i)  cin>>a[i];

        dp[1][0]=a[1]<0?0:1;
        dp[1][1]=INF;
        for(int i=2;i<=n;++i)
        {
            dp[i][0]=dp[i-1][0]+(a[i]<0?0:1);
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+(a[i]>0?0:1);
        }
        cout<<dp[n][1]<<endl;
    }
    return 0;
}
