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

int n;
int cal(int x)
{
    if(x==0) return 2; //
    if(x==1) return 7; //
    if(x==2) return 2;  //
    if(x==3) return 3;  //
    if(x==4) return 3; //
    if(x==5) return 4; //
    if(x==6) return 2;
    if(x==7) return 5;  //
    if(x==8) return 1; //
    if(x==9) return 2;  //
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n){
        cout<<cal(n/10)*cal(n%10)<<endl;
    }
    return 0;
}