//
//  Created by TaoSama on 2015-07-30
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1 << 15, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
//lexicographically order and every direction is same for each
int d[][6] = {
    { -1, -1, -1, -1, 1, 2}, { -1, 0, -1, 2, 3, 4}, {0, -1, 1, -1, 4, 5},
    { -1, 1, -1, 4, 6, 7}, {1, 2, 3, 5, 7, 8}, {2, -1, 4, -1, 8, 9},
    { -1, 3, -1, 7, 10, 11}, {3, 4, 6, 8, 11, 12}, {4, 5, 7, 9, 12, 13},
    {5, -1, 8, -1, 13, 14}, { -1, 6, -1, 11, -1, -1}, {6, 7, 10, 12, -1, -1},
    {7, 8, 11, 13, -1, -1}, {8, 9, 12, 14, -1, -1}, {9, -1, 13, -1, -1, -1}
};

int dp[N], x[N], y[N], pre[N]; //move x->y

//black->1 white->0
void bfs(int s) {
    memset(dp, -1, sizeof dp);
    queue<int> q; q.push(s);
    dp[s] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        if(u == 1 << n) break; //end state

        for(int i = 0; i < 15; ++i) { //i try to jump
            if(!(u & (1 << i))) continue; //without i
            for(int j = 0; j < 6; ++j) {
                int to = d[i][j];
                if(to == -1 || !(u & (1 << to))) continue; //to is white in "u"

                int v = u, isMoved = false;
                v -= 1 << i; //jump i to "to" and remove i
                while(to != -1 && (v & (1 << to))) { //new "to" isn't white
                    v -= 1 << to;  // remove new "to"
                    to = d[to][j]; // move one more towards "j" direction
                    isMoved = true;
                }
                v |= 1 << to; //jump here
                if(to != -1 && isMoved
                        && dp[v] == -1) { //still in the bound and "to" is a white
                    dp[v] = dp[u] + 1;
                    x[v] = i;   //save the path
                    y[v] = to;
                    pre[v] = u;
                    q.push(v);
                }
            }
        }
    }

    if(dp[1 << n] == -1) {cout << "IMPOSSIBLE\n"; return;}
    vector<int> ansx, ansy;
    cout << dp[1 << n] << '\n';
    int u = 1 << n;
    while(u != s) {
        ansx.push_back(x[u] + 1);
        ansy.push_back(y[u] + 1);
        u = pre[u];
    }
    for(int i = ansx.size() - 1; i >= 0; --i)
        cout << ansx[i] << ' ' << ansy[i] << (i == 0 ? '\n' : ' ');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        n--;
        bfs((1 << 15) - 1 - (1 << n));
    }
    return 0;
}
