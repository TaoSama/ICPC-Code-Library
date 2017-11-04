/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

int s[3][3];
int a,b;
int c1[100005],c2[100005];
int n;

int main()
{
    while(scanf("%d%d%d",&n,&a,&b)==3)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                s[i][j]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&c1[i]);
            c2[i]=c1[i];
        }
        sort(c2+1,c2+n+1);
        for(int i=1;i<=n;i++)
            s[c1[i]][c2[i]]++;
        int ans=0,t;
        t=min(s[0][1],s[1][0]);
        ans+=t;s[0][1]-=t;s[1][0]-=t;
        t=min(s[0][2],s[2][0]);
        ans+=t;s[0][2]-=t;s[2][0]-=t;
        t=min(s[1][2],s[2][1]);
        ans+=t;s[1][2]-=t;s[2][1]-=t;
        t=0;
        t=s[1][2]+s[2][1]+s[1][0]+s[0][1]+s[2][0]+s[0][2];
        t/=3;t*=2;
        ans+=t;
        printf("%d\n",ans*b);
    }
    return 0;
}
