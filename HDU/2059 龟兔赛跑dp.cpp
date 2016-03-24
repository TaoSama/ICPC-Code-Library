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

int l,n,c,t,vr,vt1,vt2,a[105];
double dp[105];

double T(double x)
{
    if(c>x) return x/vt1;
    else return (double)c/vt1+(x-c)/vt2;
}
int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    while(cin>>l)
    {
        cin>>n>>c>>t>>vr>>vt1>>vt2;
        for(int i=1; i<=n; ++i) cin>>a[i];
        a[n+1]=l;
        for(int i=1; i<=n+1; ++i) dp[i]=INF;
        dp[0]=0;
        for(int i=1; i<=n+1; ++i)
        {
            for(int j=0; j<=i; ++j)
                dp[i]=min(dp[i],dp[j]+T(a[i]-a[j])+((j==0||j==i)?0:t));
            //cout<<dp[i]<<' ';
        }
        //cout<<endl;

        //cout<<dp[n+1]<<endl;

        if((double)l/vr<dp[n+1])
            cout<<"Good job,rabbit!"<<endl;
        else
            cout<<"What a pity rabbit!"<<endl;

    }
    return 0;
}
