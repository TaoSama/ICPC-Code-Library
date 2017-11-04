
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

const int maxn=1005;
int sum[maxn],cnt[maxn][maxn],a[maxn];
vector<int> g[maxn];
int ans[maxn],sz[maxn];
int n,ma;

void cal_sz(int x,int fa)
{
    sz[x]=1;
    for(auto p : g[x])
    {
        if(p==fa)continue;
        cal_sz(p,x);
        sz[x]+=sz[p];
    }
}

int calc(int u,int v)
{
    int ret=0,ss;
    sum[0]=0;
    for(int i=1;i<=ma;i++)sum[i]=sum[i-1]+cnt[u][i];
    for(int i=1;i<=ma;i++)
    {
        if(cnt[v][i]==0)continue;
        ss=0;
        for(int k=1;k<=ma;k++)
        {
            if(sum[k]-sum[k-1]<=0)continue;
            int l=abs(i-k)+1,r=min(i+k-1,ma);
            if(l<=r)ss+=cnt[u][k]*(sum[r]-sum[l-1]);
            if(k>=l && k<=r && sum[k]-sum[k-1]==1)ss--;
            if(k>=l && k<=r && sum[k]-sum[k-1]>1)ss-=(sum[k]-sum[k-1]);
        }
        ss>>=1;
        ret+=cnt[v][i]*ss;
    }
    return ret;
}

void DFS(int x,int fa)
{
    int big=-1,ss;
    for(auto p : g[x])
    {
        if(p==fa)continue;
        DFS(p,x);
        ans[x]+=ans[p];
        if(big<0 || sz[p]>sz[big])big=p;
    }
    if(big<0){cnt[x][a[x]]=1;return;}
    for(int i=1;i<=ma;i++)cnt[x][i]=cnt[big][i];
    for(auto p : g[x])
    {
        if(p==fa || p==big)continue;
        ans[x]+=calc(x,p);
        ans[x]+=calc(p,x);
        for(int j=1;j<=ma;j++)cnt[x][j]+=cnt[p][j];
    }
    ss=0;
    for(int i=1;i<=ma;i++)sum[i]=sum[i-1]+cnt[x][i];
    for(int i=1;i<=ma;i++)
    {
        if(sum[i]-sum[i-1]<=0)continue;
        int l=abs(a[x]-i)+1,r=min(ma,a[x]+i-1);
        if(l<=r)ss+=cnt[x][i]*(sum[r]-sum[l-1]);
        if(i>=l && i<=r && sum[i]-sum[i-1]==1)ss--;
        if(i>=l && i<=r && sum[i]-sum[i-1]>1)ss-=(sum[i]-sum[i-1]);
    }
    ans[x]+=ss>>1;
    cnt[x][a[x]]++;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        scanf("%d",&n);
        ma=0;
        for(int i=0;i<=n;i++)g[i].clear(),ans[i]=sz[i]=0;
        for(int i=2;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            g[x].pb(i);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ma=max(ma,a[i]);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=ma;j++)cnt[i][j]=0;
        cal_sz(1,-1);
        DFS(1,-1);
        prrn(_);
        for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    }
    return 0;
}
