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
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const int N=2e5+10;

int n,k,a[N];
int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n>>k) {
        int ans=1,min=0;
        for(int i=1; i<=n; ++i) {
            cin>>a[i];
            if(i<=k) min+=a[i];
        }
        int sum=min;
        for(int i=k+1,j=1; i<=n; ++i,++j) {
            sum=sum+a[i]-a[j];
            if(sum<min) {min=sum;ans=j+1;}
        }
        cout<<ans<<endl;  //515
    }
    return 0;
}
