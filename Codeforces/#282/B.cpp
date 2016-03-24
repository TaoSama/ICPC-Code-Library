#include<bits/stdc++.h>
#define sz(a) (int)((a).size())
#define clr(a) memset(a, 0, sizeof(a))
#define re(i,a,b) for(int i=a;i<(b+1);++i)
#define de(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+10;

int a,b;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>a>>b) {
        int l=a-b,ans=0;
        for(int i=1; i*i<=l; ++i) {
            if(l%i==0) {
                if(i>b) ++ans;
                if(i!=l/i&&l/i>b) ++ans;
            }
        }
        if(l==0) cout<<"infinity"<<endl;
        else     cout<<ans<<endl;
    }
    return 0;
}