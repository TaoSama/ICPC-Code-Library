
By CST14-TaoSama, contest: Codeforces Round #284 (Div. 2), problem: (C) Crazy Town, Accepted, #
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

double _x1,_y1,_x2,_y2;
int n,ans;
double a,b,c;
double solve(int x,int y) {
    return a*x+b*y+c;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    while(cin>>_x1>>_y1>>_x2>>_y2>>n) {
        ans=0;
        re(i,1,n) {
            cin>>a>>b>>c;
            if(solve(_x1,_y1)*solve(_x2,_y2)<=0) ++ans;
        }
        cout<<ans<<endl;
    }

    return 0;
}