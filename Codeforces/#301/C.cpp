//
//  Created by TaoSama on 2015-05-10
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m, sx, sy, ex, ey;
int d[][2] = {-1,0,0,-1,1,0,0,1};
//bool vis[505][505];
char a[505][505];
typedef pair<int,int> P;

bool bfs(){
	queue<P> q; q.push(P(sx, sy));
	//memset(vis, false, sizeof vis);
	//vis[sx][sy] = true;
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + d[i][0], ny = y + d[i][1];
			if(nx == ex && ny == ey && a[nx][ny] == 'X') return true;
			if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'X') continue;
			a[nx][ny] = 'X';
			q.push(P(nx, ny));
		}
	}
	return false;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m){
		for(int i = 1; i <= n; ++i) cin >> a[i] + 1;
		cin >> sx >> sy >> ex >> ey;
		if(bfs()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
