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

int n,tian[N],king[N];
int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n&&n)
    {
        int ans=0;
        for(int i=1; i<=n; ++i) cin>>tian[i];
        for(int i=1; i<=n; ++i) cin>>king[i];

        sort(tian+1,tian+1+n);
        sort(king+1,king+1+n);

        int t1=1,t2=n,k1=1,k2=n;

        while(t1<=t2)
        {
            if(tian[t1]<king[k1])
            {
                --ans;
                ++t1; --k2;
            }
            else if(tian[t1]==king[k1])
            {
                if(tian[t2]>king[k2])
                {
                    ++ans;
                    --t2; --k2;
                }
                else   //the best horse equal or less
                {
                    if(tian[t1]<king[k2]) --ans;
                    ++t1; --k2;
                }
            }
            else
            {
                ++ans;
                ++t1; ++k1;
            }
        }

        cout<<ans*200<<endl;
    }
    return 0;
}
