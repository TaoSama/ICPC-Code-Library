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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 500 + 10;
int use[N];
int deg[N];
vector<int> vp[N];
int solve(int n)
{
	MEM(deg, 0);
	for (int i = 1; i <= n; i++)
	{
		for (auto &j : vp[i])
		{
			deg[i]++;
			deg[j]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		use[i] = false;
		deg[i] /= 2;
	}
	int ans = 0;
	while (true) {
		int mx = -1, u;
		for (int i = 1; i <= n; ++i) {
			if (use[i])
				continue;
			if (deg[i] >= mx) {
				mx = deg[i];
				u = i;
			}
		}
		if (mx <= 0)
			break;
		++ans;
		use[u] = true;
		for (auto &v : vp[u])
			--deg[v];
	}
	return ans;
}
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        vp[u].push_back(v);
        vp[v].push_back(u);
    }
    cout << solve(n) << endl;
	return 0;
}
