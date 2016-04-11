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

long long n,m,k,a[N],s[N],dp[5005][5005];
int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n>>m>>k)
    {
        for(int i=1; i<=n; ++i) cin>>a[i];
        memset(s,0,sizeof s); memset(dp,0,sizeof dp);

        for(int i=m; i<=n; ++i) for(int j=0; j<m; ++j)
                s[i]+=a[i-j];

        for(int i=1; i<=n; ++i)
            for(int j=1; j<=k&&j*m<=i; ++j)
                dp[i][j]=max(dp[i-m][j-1]+s[i],dp[i-1][j]);

        cout<<dp[n][k]<<endl;

    }
    return 0;
}
