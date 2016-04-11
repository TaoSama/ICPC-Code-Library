//
//  POJ 3126 Prime Path
//
//  Created by TaoSama on 2015-03-23
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, s, g, dp[10005];
bool prime[10005], in[10005];
void seive() {
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for(int i = 2; i < 10000; ++i) {
        if(prime[i]) {
            for(int j = i + i; j < 10000; j += i)
                prime[j] = false;
        }
    }
}
int bfs() {
    memset(dp, 0x3f, sizeof dp);
    memset(in, false, sizeof in);
    queue<int> q;
    dp[s] = 0; in[s] = true; q.push(s);
    while(!q.empty()) {
        int cur = q.front(), nxt; q.pop();
//		cout << "cur: " << cur << endl;
        for(int i = 0; i < 4 ; ++i) {
            char s[5]; sprintf(s, "%d", cur);
            if(i == 0) s[i] = '1' - 1;
            else if(i == 3) s[i] = '1' - 2;
            else     s[i] = '0' - 1;
//			cout << ' ' << "s: " << s << endl;
            while(s[i] < '9') {
                if(i == 3) s[i] += 2;
                else     ++s[i];
                nxt = atoi(s);
                if(prime[nxt] && !in[nxt]) {
                    if(dp[nxt] > dp[cur] + 1) {
                        dp[nxt] = dp[cur] + 1;
                        q.push(nxt); in[nxt] = true;
//						cout << "nxt: " << nxt << ' ' << dp[nxt] << endl;
                    }
                }
            }
        }
    }
    return dp[g];
}
int main() {
#ifdef LOCAL
    freopen("ACM_in.txt", "r", stdin);
//	freopen("ACM_out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    seive();
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            cin >> s >> g;
            int ans = bfs();
            if(ans == INF) cout << "Impossible" << endl;
            else           cout << ans << endl;
        }
    }
    return 0;
}
