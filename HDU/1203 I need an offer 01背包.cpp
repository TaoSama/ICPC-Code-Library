#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
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

int n,m,w[10005];
double dp[N],v[10005];

int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopene("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n>>m&&(n+m))
    {
        for(int i=1; i<=m; ++i) cin>>w[i]>>v[i];

        for(int i=0; i<=n; ++i) dp[i]=1;

        for(int i=1; i<=m; ++i)
            for(int j=n; j>=w[i]; --j)
                dp[j]=min(dp[j],dp[j-w[i]]*(1-v[i]));

        double ans=(1-dp[n])*100;

        cout<<fixed<<setprecision(1)<<ans<<"%"<<endl;

    }
    return 0;
}