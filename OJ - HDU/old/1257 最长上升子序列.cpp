#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <vector>
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const int N = 2e5+10;

int n,a[N],dp[N];

int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n)
    {
        for(int i=1; i<=n; ++i)
        {
            cin>>a[i];
            dp[i]=1;
        }

        int ans=1;
        for(int i=2; i<=n; ++i)
        {
            for(int j=1; j<i; ++j)
            {
                if(a[i]>=a[j]&&dp[j]+1>dp[i])
                    dp[i]=dp[j]+1;
                if(ans<dp[i]) ans=dp[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}