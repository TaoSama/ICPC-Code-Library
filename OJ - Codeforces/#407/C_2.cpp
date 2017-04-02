//
//  Created by TaoSama on 2017-03-29
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include <bitset>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        vector<bool> vis(1001, 0);
        for(int i = 1; i <= k; ++i) {
            int x; cin >> x;
            vis[x] = true;
        }
        vector<int> vs;
        for(int i = 0; i <= 1000; ++i) if(vis[i]) vs.push_back(i - n);

        vector<int> f(N * 2, -1), q;
        for(int x : vs) {
            int u = x + 1000;
            f[u] = 1;
            q.push_back(u);
        }
        for(int i = 0; i < q.size(); ++i) {
            int u = q[i];
            for(int x : vs) {
                int v = u + x;
                if(v >= 0 && v <= 2000) {
                    if(f[v] == -1) {
                        f[v] = f[u] + 1;
                        q.push_back(v);
                    }
                }
            }
        }
        cout << f[1000] << endl;
    }

    return 0;
}
