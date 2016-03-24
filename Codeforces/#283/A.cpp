#include<bits/stdc++.h>
#define sz(a) (int)((a).size())
#define clr(a) memset(a, 0, sizeof(a))
#define re(i,a,b) for(int i=a;i<(b+1);++i)
#define de(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int N=1e5+10;

int n,a[110],b[110];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n) {
        int ans=1000;
        re(i,1,n) {
            cin>>a[i];
            if(i>1) b[i]=a[i]-a[i-1];
        }
        re(i,2,n-1) {
            int Max=0;
            re(j,2,n) {
                if(j==i) continue;
                else if(j==i+1) Max=max(a[j]-a[j-2],Max);
                else Max=max(Max,b[j]);
            }
            ans=min(ans,Max);
        }
        cout<<ans<<endl;

    }


    return 0;
}