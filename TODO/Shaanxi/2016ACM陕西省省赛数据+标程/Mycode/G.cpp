
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
#define IN freopen("1.in", "r", stdin)
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

struct node
{
    int x,y;
    LL num;
    bool operator < (const struct node p)const
    {
        if(y*p.x<x*p.y)return true;
        if(y*p.x>x*p.y)return false;
        return x<=p.x;
    }
}a[1000005],qu[100005];
LL ans[100005];
int n,m;

struct szsz
{
    LL sum[1005];
    int l;

    void init(int x)
    {
        l=x;
        for(int i=0;i<=x;i++)sum[i]=0;
    }

    void add(int p,int num)
    {
        while(p<=l)
        {
            sum[p]+=num;
            p+=lowbit(p);
        }
    }

    LL cal(int p)
    {
        LL ret=0;
        while(p>0)
        {
            ret+=sum[p];
            p-=lowbit(p);
        }
        return ret;
    }
}sz;

int main()
{
    int T;
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        scanf("%d",&n);
        int k=0,x;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&x);
                a[++k]={j,n+1-i,x};
            }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            int p,q;
            scanf("%d%d",&p,&q);
            qu[i]={p,q,i};
        }
        sort(a+1,a+k+1);
        sort(qu+1,qu+m+1);
        int i=1,j=1;
        sz.init(n);
        while(j<=m)
        {
            while(i<=k && a[i]<qu[j])
            {
                sz.add(a[i].x,a[i].num);
                i++;
            }
            ans[qu[j].num]=sz.cal(qu[j].x);
            j++;
        }
        prrn(_);
        for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
    }
    return 0;
}
