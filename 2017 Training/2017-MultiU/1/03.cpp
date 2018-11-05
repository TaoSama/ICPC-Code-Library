#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
const int M = 2e5;
int n,cas;
vector<int> v[N], u[N];
int col[N];
int in[N], out[N];
LL ans[N];
int pre[N];
list<int> l[N];
int dfn = 1;
template<typename T> inline void readint(T &x) {
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    x *= f;
}
void dfs(int x, int fa = -1)
{
    int cx = col[x];
    if (l[cx].empty()) u[M + cx].push_back(x);
    else u[l[cx].back()].push_back(x);
    pre[x] = fa;
    l[cx].push_back(x);
    in[x] = dfn++;
    for (int j = 0; j < v[x].size(); j++)
    {
        int &y = v[x][j];
        if (y == fa) continue;
        dfs(y, x);
    }
    l[cx].pop_back();
    out[x] = dfn;
}
inline bool isson(int x, int y)
{
    return in[y] <= in[x] && in[x] < out[y];
}
inline int treesize(int x)
{
    return out[x] - in[x];
}
void getans(int x, int o = 0)
{
    int p = 0;
    if (x <= M)
    {
        ans[in[x]] += n - o;
        ans[in[x] + 1] -= n - o;
    }
    for (int i = 0; i < v[x].size(); i++)
    {
        int &y = v[x][i];
        if (y == pre[x]) continue;
        int nx = p;
        int sz = treesize(y);
        while (nx < u[x].size() && isson(u[x][nx], y))
        {
            sz -= treesize(u[x][nx]);
            nx++;
        }
        ans[in[y]] += n - sz - o;
        ans[out[y]] -= n - sz - o;
        for (int i = p; i < nx; i++)
        {
            getans(u[x][i], n - sz);
        }
        p = nx;
    }
}
int main()
{
	while(scanf("%d",&n)==1){
	    for (int i = 1; i <= n; i++) readint(col[i]);
	    MEM(ans, 0);
	    for(int i=0;i<N;i++)v[i].clear(),u[i].clear(),l[i].clear();
	    dfn=1;
	    for (int i = 1; i < n; i++)
	    {
	        int x, y;
	        readint(x);
	        readint(y);
	        v[x].push_back(y);
	        v[y].push_back(x);
	    }
	    dfs(1);
	    for (int i = 1; i <= M; i++)
	    {
	        v[i + M].push_back(1);
	        getans(i + M);
	    }
	    for (int i = 1; i <= n; i++) ans[i] += ans[i - 1];
	    ll Ans=0;
	    for(int i=1;i<=n;i++)Ans+=ans[in[i]];
	    printf("Case #%d: %lld\n",++cas,(Ans-n)/2);
	}
    return 0;
}
