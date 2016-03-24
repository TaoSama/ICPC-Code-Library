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

int n,a[N];

int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    while(cin>>n&&n)
    {
        int ans=-INF,sum=0,left,right,st=1;
        for(int i=1; i<=n; ++i)
        {
            cin>>a[i];
            sum+=a[i];
            if(ans<sum)
            {
                left=st;
                right=i;
                ans=sum;
            }
            if(sum<0)
            {
                sum=0;
                st=i+1;
            }
        }
        if(ans<0) cout<<0<<' '<<a[1]<<' '<<a[n]<<endl;
        else     cout<<ans<<' '<<a[left]<<' '<<a[right]<<endl;

    }
    return 0;
}
