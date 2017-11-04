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

const int mod=20161119;
const int maxn=100005;
struct seg_tree
{
    struct node
    {
        int ll,rr,ls,rs,ma,mi;
    }tr[2*maxn];
    int cnt;

    void mt(int x,int y)
    {
        int t=cnt,mid=(x+y)>>1;
        tr[t].ll=x;tr[t].rr=y;
        tr[t].ls=tr[t].rs=0;
        tr[t].ma=tr[t].mi=0;
        if(x==y)return;
        cnt++;tr[t].ls=cnt;mt(x,mid);
        cnt++;tr[t].rs=cnt;mt(mid+1,y);
    }

    void pushup(int now)
    {
        tr[now].ma=max(tr[tr[now].ls].ma,tr[tr[now].rs].ma);
        tr[now].mi=min(tr[tr[now].ls].mi,tr[tr[now].rs].mi);
    }

    void insert(int p,int now,int v)
    {
        if(tr[now].ll==tr[now].rr)
        {
            tr[now].ma=tr[now].mi=v;
            return;
        }
        int mid=(tr[now].ll+tr[now].rr)>>1;
        if(p<=mid)insert(p,tr[now].ls,v);
        if(p>mid)insert(p,tr[now].rs,v);
        pushup(now);
    }

    int find(int now,int l,int r,int fl)
    {
        if(tr[now].ll==l && tr[now].rr==r)
        {
            if(fl>0)return tr[now].ma;else return tr[now].mi;
        }
        int mid=(tr[now].ll+tr[now].rr)>>1;
        if(r<=mid)return find(tr[now].ls,l,r,fl);
        if(l>mid)return find(tr[now].rs,l,r,fl);
        if(fl>0)
            return max(find(tr[now].ls,l,mid,fl),find(tr[now].rs,mid+1,r,fl));
        else
            return min(find(tr[now].ls,l,mid,fl),find(tr[now].rs,mid+1,r,fl));
    }

    void init(int n,int v)
    {
        for(int i=0;i<=n;i++)insert(i,1,v);
    }

    void build(int n)
    {
        cnt=1;mt(1,n);
    }
}se;

struct num
{
    int q,s,pos;
    bool operator < (const struct num p)const
    {return q<p.q;}
}qu[maxn],a[maxn];
int dfn[maxn],ans[maxn],v[maxn],sz[maxn];
vector<int> g[maxn];
int n,m,k;

void DFS(int u,int f)
{
    LL now;
    if(u==1)now=1;else now=1ll*u*v[f]%mod;
    v[u]=now;
    dfn[u]=++k;sz[u]=1;a[k]={v[u],u,k};
    for(unsigned int i=0;i<g[u].size();i++)
    {
        int vv=g[u][i];
        if(vv==f)continue;
        DFS(vv,u);sz[u]+=sz[vv];
    }
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<=n;i++)dfn[i]=0,g[i].clear(),v[i]=0,sz[i]=0;
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            g[x].pb(y);g[y].pb(x);
        }
        k=0;DFS(1,-1);
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            qu[i]={y,x,i};
            ans[i]=mod+1;
        }
        sort(a+1,a+n+1);
        sort(qu+1,qu+1+m);
        se.build(n);
        se.init(n,-1);
        int j=1;
        for(int i=1;i<=m;i++)
        {
            while(j<=n && a[j].q<=qu[i].q)
            {
                se.insert(a[j].pos,1,a[j].q);
                j++;
            }
            int v=qu[i].s,id=qu[i].pos;
            int t=se.find(1,dfn[v],dfn[v]+sz[v]-1,1);
            if(t>=0)ans[id]=min(ans[id],abs(qu[i].q-t));
        }
        se.init(n,mod+1);j=n;
        for(int i=m;i>=1;i--)
        {
            while(j>=1 && a[j].q>=qu[i].q)
            {
                se.insert(a[j].pos,1,a[j].q);
                j--;
            }
            int v=qu[i].s,id=qu[i].pos;
            int t=se.find(1,dfn[v],dfn[v]+sz[v]-1,-1);
            if(t<mod)ans[id]=min(ans[id],abs(qu[i].q-t));
        }
        for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    }
    return 0;
}
