//
//  Created by TaoSama on 2015-05-08
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

int n, k;
bool vis[105][105];
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        memset(vis, false, sizeof vis);
        if((n & 1) && k > (n / 2 + 1) * (n / 2 + 1)
                + (n / 2) * (n / 2)) {
            cout << "NO\n";
            continue;
        }
        if(n % 2 == 0 && k > (n / 2) * n) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int cnt = 0;
        bool ok = false;
        for(int i = 1; i <= n; ++i) {
            for(int j = (i & 1) ? 1 : 2; j <= n; j += 2) {
				if(cnt + 1 <= k) vis[i][j] = true;
                if(++cnt >= k) {
					ok = true;
					break;
                }
            }
            if(ok) break;
        }
        for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(vis[i][j]) cout<<'L';
				else cout<<'S';
			}
			cout<<'\n';
        }
    }
    return 0;
}
