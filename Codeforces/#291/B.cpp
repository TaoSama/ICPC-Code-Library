//
//  B. Han Solo and Lazer Gun
//
//  Created by TaoSama on 2015-02-15
//  Copyright (c) 2014 TaoSama. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int x0, y0, n, x[1005], y[1005];
bool vis[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> x0 >> y0) {
		memset(vis, 0, sizeof vis);
		for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			if(!vis[i]) {
				++ans; vis[i] = true;
				for(int j = 1; j <= n; ++j) {
					if(!vis[j]) {
						if((x[j] - x0) * (y[i] - y0) == (x[i] - x0) * (y[j] - y0))
							vis[j] = true;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
