/* ***********************************************
MYID    : Chen Fan
LANG    : G++
PROG    : MarsCity
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
const int M = N*N;
struct node
{
    int a,b,c;
};

node edge[M];
int predge[N],id[N],visit[N],in[N];

int dmst(int root,int n,int m)//n表示点数，m表示边数，root表示根
{
    int u,v;
    int ret=0;
    while(true)
    {
        for(int i=1;i<=n;i++) in[i]=INT_MAX;
        for(int i=1;i<=m;i++)
        {
            if(edge[i].c<in[edge[i].b]&&edge[i].a!=edge[i].b)
            {
                predge[edge[i].b]=edge[i].a;//找出每个点的最小入弧
                in[edge[i].b]=edge[i].c;
            }
        }
		in[root]=0;
        for(int i=1;i<=n;i++)
        if (in[i]==INT_MAX) return -1;
        
        int cnt=1;
        memset(id,-1,sizeof(id));
        memset(visit,-1,sizeof(visit));
        for(int i=1;i<=n;i++)
        {
            ret+=in[i];//进行缩圈
            v=i;
            while(visit[v]!=i&&id[v]==-1&&v!=root)
            {
                visit[v]=i;
                v=predge[v];
            }
            if(v!=root&&id[v]==-1)
            {
                for (u=predge[v];u!=v;u=predge[u]) id[u]=cnt;
                id[v]=cnt++;
            }
        }
        if (cnt==1) break;
        
        for (int i=1;i<=n;i++)
        if (id[i]==-1) id[i]=cnt++;
        
		for (int i=1;i<=m;i++)
        {
            v=edge[i].b;//进行缩点，重新标记。
            edge[i].a=id[edge[i].a];
            edge[i].b=id[edge[i].b];
            if (edge[i].a!=edge[i].b) edge[i].c-=in[v];
        }
        n=cnt-1;
        root=id[root];
    }
    return ret;
}

struct hnode
{
    int x,y,z;
};
hnode house[N];

bool op(hnode a, hnode b)
{
    if (a.z==b.z) return a.x<b.x;
    else return a.z>b.z;
}

int dis(int x,int y)
{
    return abs(house[x].x-house[y].x)+abs(house[x].y-house[y].y)+abs(house[x].z-house[y].z);
}

int main()
{
    //freopen("MarsCity.in","r",stdin);
    //freopen("MarsCity.out","w",stdout);

    int t;
    scanf("%d",&t);
    for (int tt=1;tt<=t;tt++)
    {
        printf("Case #%d:\n",tt);

        int n,p;
        scanf("%d%d",&n,&p);
        for (int i=1;i<=n;i++)
        scanf("%d%d%d",&house[i].x,&house[i].y,&house[i].z);

        sort(&house[1],&house[n+1],op);
        int root=-1;
        if (house[1].z>house[2].z) root=1;
        
        int tot=0;
        for (int i=1;i<n;i++)
        {
            for (int j=i+1;j<=n;j++)
            if (house[i].z>=house[j].z)
            {
				tot++;
                edge[tot].a=i;
                edge[tot].b=j;
                edge[tot].c=dis(i,j)*p;
                if (house[i].z==house[j].z)
                {
                	tot++;
                    edge[tot].a=j;
                    edge[tot].b=i;
                    edge[tot].c=edge[tot-1].c;
                }
            }
        }
        if (root==-1)
        {
            root=n+1;
            for (int i=1;i<=n;i++)
            {
				tot++;
                edge[tot].a=root;
                edge[tot].b=i;
                edge[tot].c=5000000;       
                if (house[i].z>house[i+1].z) break;
            }
            n++;
    	}
        
        int ans=dmst(root,n,tot);
        if (root>1) ans-=5000000;
        printf("%d\n",ans);
    }

    return 0;
}
