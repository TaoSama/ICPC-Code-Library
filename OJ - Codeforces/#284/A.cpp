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

int n,x,l1,r1,l2,r2,ans;
int main() {
#ifndef ONLINE_JUDGE
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    while(cin>>n>>x) {
        ans=0;
        cin>>l1>>r1;
        ans=ans+(l1-1)%x+(r1-l1+1);
        re(i,2,n) {
            cin>>l2>>r2;
            ans=ans+(l2-r1-1)%x+(r2-l2+1);
            l1=l2; r1=r2;
        }
        cout<<ans<<endl;
    }

    return 0;
}