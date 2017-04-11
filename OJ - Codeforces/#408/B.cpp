//
//  Created by TaoSama on 2017-04-11
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

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m >> k) {
        vector<int> h(n + 1, 0);
        h[1] = 1;
        vector<bool> no(n + 1, 0);
        for(int i = 1; i <= m; ++i) {
            int x; cin >> x;
            no[x] = 1;
        }
        for(int i = 1; i <= k; ++i) {
            int x, y; cin >> x >> y;
            if(h[x] && no[x] || h[y] && no[y]) continue;
            swap(h[x], h[y]);
        }
        cout << find(h.begin(), h.end(), 1) - h.begin() << endl;
    }

    return 0;
}
