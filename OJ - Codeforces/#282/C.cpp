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

string s;
int t,mint,x;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>s) {
        t=x=0;
        bool ok=1;
        re(i,0,sz(s)-1) {
            if(s[i]=='(') ++t;
            if(s[i]==')') --t;
            if(s[i]=='#') {++x;--t;mint=t;}
            mint=min(t,mint);
            if(t<0) {ok=0;break;}
        }
        if(!ok||mint<t) cout<<-1<<endl;
        else {
            re(i,1,x) {
                if(i!=x) cout<<1<<endl;
                else     cout<<t+1<<endl;
            }
        }
    }
    return 0;
}
