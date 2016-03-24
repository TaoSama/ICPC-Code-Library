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
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n) {
        for(int i=1; i<=n; ++i) cin>>a[i];

        for(int i=1; i<=n; ++i) {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-a[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
        }
        int ans=max(dp[n][0],dp[n][1]);
        cout<<ans<<endl;
    }
    return 0;
}