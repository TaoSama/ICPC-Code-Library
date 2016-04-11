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

int n,t,x,a[N];
string ans;
void dfs(int x) {
    if(a[x]==t) {
        ans="YES";
        return;
    } else if(a[x]>=n) return;
    else dfs(a[x]);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n>>t) {
        ans="NO";
        for(int i=1; i<=n; ++i) {
            cin>>x;
            a[i]=x+i;
        }
        dfs(1);
        cout<<ans<<endl;
    }

    return 0;
}