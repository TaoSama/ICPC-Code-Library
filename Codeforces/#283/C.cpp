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

int n,m;
char a[105][105];
int ok[105];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n>>m) {
        int ans=0;
        memset(ok,0,sizeof ok);
        for(int i=1; i<=n; ++i) cin>>(a[i]+1);
        for(int i=1; i<=m; ++i) {
            bool flag=0;
            for(int j=1; j<n; ++j) {
                if(a[j][i]>a[j+1][i]&&!ok[j]) {
                    flag=1;
                    break;
                }
            }
            if(flag) ++ans;
            else {
                for(int j=1; j<n; ++j) {
                    if(a[j][i]<a[j+1][i])
                        ok[j]=1;
                }
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}