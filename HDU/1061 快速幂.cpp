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
const int N=1e5+10;

int t;
long long n;

long long ksm(long long x,long long n)
{
    long long ret=1;
    while(n) {
        if(n&1) ret=ret*x%10;
        x=x*x%10;
        n>>=1;
    }
    return ret;
}
int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>t) {
        for(int i=0; i<t; ++i) {
            cin>>n;
            long long ret=ksm(n%10,n);
            cout<<ret%10<<endl;
        }
    }
    return 0;
}
