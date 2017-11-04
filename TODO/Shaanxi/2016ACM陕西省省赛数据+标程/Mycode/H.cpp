
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-7;
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
  
const int maxn=2005;

struct node
{
    double px,py,val,mul,lb,cnt;
    void read()
    {
        scanf("%lf%lf%lf%lf",&px,&py,&val,&mul);
        cnt=1.0;
    }
    void cal(int ag)
    {
        if(ag==0 || ag==180){lb=py;return;}
        if(ag==90){lb=px;return;}
        double angle=(double)ag/180.0*pi;
        double dx=-px;
        double dy=dx*tan(angle);
        lb=py+dy;
    }
    bool operator < (const struct node p)const
    {return lb<p.lb;}
}a[maxn],b[maxn];

node operator + (struct node q,struct node p)
{
    struct node ans=q;
    ans.val+=p.val;
    ans.mul+=p.mul;
    ans.cnt+=p.cnt;
    return ans;
}

int ang,n,tot;
double dp[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);tot=0;
        for(int i=1;i<=n;i++)a[i].read();
        scanf("%d",&ang);
        for(int i=1;i<=n;i++)a[i].cal(ang);
        sort(a+1,a+n+1);
        int j=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i].lb-a[j].lb>eps)
            {
                b[++tot]={0,0,0,0,a[j].lb,0};
                for(int k=j;k<=i-1;k++)b[tot]=b[tot]+a[k];
                j=i;
            }
        }
        b[++tot]={0,0,0,0,a[j].lb,0};
        for(int k=j;k<=n;k++)b[tot]=b[tot]+a[k];
        dp[0]=0;
        dp[1]=b[1].val*b[1].mul/b[1].cnt;
        for(int i=2;i<=tot;i++)
        {
            dp[i]=dp[i-1]+b[i].val*b[i].mul/b[1].cnt;
            struct node temp=b[i];
            for(int j=i-1;j>=1;j--)
            {
                temp=temp+b[j];
                dp[i]=max(dp[i],dp[j-1]+temp.val*temp.mul/temp.cnt);
            }
        }
        prrn(t);
        printf("%.3lf\n",dp[tot]);
    }  
    return 0;
}
