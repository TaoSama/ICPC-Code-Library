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
        vector<int> v;
        for(int i = 0; i <= 1000; ++i) if(vis[i]) v.push_back(i - n);

        bool ok = false;
        bitset<N * 2> cur, nxt;
        cur[1000] = 1;
        for(int i = 1; i <= 1000 && !ok; ++i) {
            nxt.reset();
            for(int x : v) {
                if(x > 0) nxt |= cur << x;
                else nxt |= cur >> -x;
            }
            swap(cur, nxt);
            if(cur[1000]) {ok = true; cout << i << endl;}
        }
        if(!ok) cout << -1 << endl;
    }

    return 0;
}
