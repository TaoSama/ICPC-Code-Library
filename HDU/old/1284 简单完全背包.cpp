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

long long n,dp[N];

int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    dp[0]=1;
    for(int i=1;i<=3;++i)
        for(int j=i;j<=32768;++j)
            dp[j]+=dp[j-i];

    while(cin>>n&&n)
    {
        cout<<dp[n]<<endl;
    }
    return 0;
}