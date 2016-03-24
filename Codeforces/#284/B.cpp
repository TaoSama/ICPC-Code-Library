
By CST14-TaoSama, contest: Codeforces Round #284 (Div. 2), problem: (B) Lecture, Accepted, #
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
string a,b,c[3005];
map<string,string> ma;
int main() {
#ifndef ONLINE_JUDGE
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    while(cin>>n>>m) {
        re(i,1,m) {cin>>a>>b; ma[a]=b;}
        re(i,1,n) cin>>c[i];
        re(i,1,n) {
            if(i!=n) {
                if(ma[c[i]].size()<c[i].size())
                    cout<<ma[c[i]]<<' ';
                else
                    cout<<c[i]<<' ';
            } else {
                if(ma[c[i]].size()<c[i].size())
                    cout<<ma[c[i]]<<endl;
                else
                    cout<<c[i]<<endl;
            }
        }
    }

    return 0;
}