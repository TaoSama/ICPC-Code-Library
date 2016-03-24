#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;

int n, m, ans;
char a[305][305];
bool vis[305][305];
int bx, by, gx, gy;
int d[4][2] = {{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};
struct point {
	int x, y, step;
	point(int _x = 0, int _y = 0) {x = _x; y = _y;}
	bool operator<(const point& a)const {return a.step <step;}
} pre[305][305];
int bfs() {
	memset(vis, 0, sizeof vis); priority_queue <point> q;
	vis[bx][by] = 1; q.push(point(bx, by));
	while(!q.empty()) {
		point cur = q.top(); q.pop();
		if(cur.x == gx && cur.y == gy) return cur.step;
		for(int i = 0; i < 4; ++i) {
			point nxt(cur.x + d[i][0], cur.y + d[i][1]);
			if(nxt.x >= 1 && nxt.x <= n && nxt.y >= 1 && nxt.y <= m
			        && a[nxt.x][nxt.y] != '#' && !vis[nxt.x][nxt.y]) {
				if(a[nxt.x][nxt.y] == 'x') nxt.step=cur.step+2;
				else  nxt.step=cur.step+1;
				vis[nxt.x][nxt.y] = 1;
				q.push(nxt);
			}
		}

	}
	return 0;
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
				cin >> a[i][j];
				if(a[i][j] == 'r') bx = i, by = j;
				if(a[i][j] == 'a') gx = i, gy = j;
			}
		ans=bfs();
		if(!ans)
			cout << "Poor ANGEL has to stay in the prison all his life." << endl;
		else cout << ans << endl;

	}

	return 0;
}