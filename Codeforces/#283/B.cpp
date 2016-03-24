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

int n;
char a[15][1005];
char ans[1005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n>>a[1]) {
        re(i,1,9) {
            for(int j=0; j<n; ++j) {
                if(a[i][j]=='9') a[i+1][j]='0';
                else a[i+1][j]=a[i][j]+1;
                //cout<<a[i+1][j];
            }
            //cout<<endl;
        }
        //cout<<endl;
        strcpy(ans,a[1]);
        re(i,1,10) {
            if(strcmp(a[i],ans)<0) strcpy(ans,a[i]);
            re(j,1,n) {
                char t=a[i][n-1];
                de(k,n-1,1) a[i][k]=a[i][k-1];
                a[i][0]=t;
                //cout<<a[i]<<' ';
                if(strcmp(a[i],ans)<0) strcpy(ans,a[i]);
                //cout<<"ans:"<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}