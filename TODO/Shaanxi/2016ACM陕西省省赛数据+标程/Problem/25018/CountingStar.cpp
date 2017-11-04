/* ***********************************************
MYID    : Chen Fan
LANG    : G++
PROG    : HDU5032
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long c[1010];
int outp[100010];
long long ou[100010];
int n;

typedef struct poin
{
    int x,y;
    long long v;
    double ang;
} point;

point poi[1000010];

typedef struct nod
{
    int x,y,src;
    double ang;
} node;

node lis[100010];

bool op1(point a,point b)
{
    if (a.ang==b.ang) return a.x<b.x;
    else return a.ang<b.ang;
}

bool op2(node a,node b)
{
    if (a.ang==b.ang) return a.x<b.x;
    else return a.ang<b.ang;
}

int lowbit(int s)
{
    return s&-s;
} 

void update(int s,long long x) 
{
    while (s<=n)
    {
        c[s]+=x;
        s+=lowbit(s);
    }
}

long long sum(int s)
{
    long long t=0;
    while (s>0)
    {
        t+=c[s];
        s-=lowbit(s);
    }
    return t;
}

int main()
{
    //freopen("CountingStar.in0","r",stdin);
    //freopen("result","w",stdout);
    
    int t;
    scanf("%d",&t);
    for (int tt=1;tt<=t;tt++)
    {
        printf("Case #%d:\n",tt);
        
        scanf("%d",&n);
        int totp=0;
        for (int i=n;i>=1;i--)
        for (int j=1;j<=n;j++)
        {
            totp++;
            scanf("%d",&poi[totp].v);
            poi[totp].x=j;
            poi[totp].y=i;
            poi[totp].ang=(double)i/j;
        }
        sort(&poi[1],&poi[1+totp],op1);
        
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&lis[i].x,&lis[i].y);
            lis[i].ang=(double)lis[i].y/lis[i].x;
            lis[i].src=i;
        }
        sort(&lis[1],&lis[1+m],op2);
        for (int i=1;i<=m;i++) outp[lis[i].src]=i;
        
        memset(c,0,sizeof(c));
        for (int i=1,j=1;i<=m;i++)
        {
            while (j<=totp&&lis[i].ang-poi[j].ang>=0)
            {
                update(poi[j].x,poi[j].v);
                j++;
            }
            ou[i]=sum(lis[i].x);
        }
        
        for (int i=1;i<=m;i++) printf("%lld\n",ou[outp[i]]);
    }
    
    return 0;
}