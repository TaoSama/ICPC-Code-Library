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

int t,n,dp[N],v[505],w[505];

int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopene("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin>>t;
    while(t--)
    {
        int e,f,G;
        cin>>e>>f>>n; G=f-e;
        for(int i=1; i<=n;++i) cin>>v[i]>>w[i];

        for(int i=1;i<=N;++i) dp[i]=INF;
        dp[0]=0;
        for(int i=1; i<=n; ++i)
            for(int j=w[i]; j<=G; ++j)
                dp[j]=min(dp[j],dp[j-w[i]]+v[i]);

        if(dp[G]!=INF)
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[G]<<"."<<endl;
        else
            cout<<"This is impossible."<<endl;

    }
    return 0;
}