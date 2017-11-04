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
#define IN freopen("data.in", "r", stdin)
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

LL c[20][20];

void calc()
{
    c[0][0]=1;
    for(int i=1;i<=18;i++)
    {
        c[0][i]=1;
        c[i][0]=c[i][i]=1;
        for(int j=1;j<=i-1;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
}

int n,k,p;
LL x;
vector<int> ans;

LL cal(int tot,int last)
{
    LL temp=c[tot][last];
    for(int i=1;i<=tot-last;i++)
        temp*=1ll*(k-1);
    return temp;
}

bool find(int tot,int last,LL rk)
{
    if(cal(tot,last)<rk)return false;
    LL sum=0,ll=0;
    int j;
    for(int i=1;i<=k;i++)
    {
        ll=sum;
        if(i==1 && last<=0)continue;
        if(i==1)sum+=cal(tot-1,last-1);
        else sum+=cal(tot-1,last);
        if(sum>=rk)
        {
            j=i;break;
        }
    }
    ans.pb(j);
    if(j==1)last--;
    if(tot==1)return true;else return find(tot-1,last,rk-ll);
}

void pri()
{
    for(auto x : ans)
        printf("%d",x);
    printf("\n");
}

int main()
{
    //IN;OUT;
    calc();
    while(scanf("%d%d%d%lld",&k,&n,&p,&x)==4)
    {
        ans.clear();
        if(!find(n,p,x))printf("poor god wan\n");else pri();
    }
    return 0;
}
