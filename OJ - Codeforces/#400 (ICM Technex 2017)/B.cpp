//
//  Created by TaoSama on 2017-02-23
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

int n;
int col[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {

        int maxc = 0;
        for(int i = 2; i <= n + 1; ++i) {
            int t = i;
            int vis[10] = {}, cur = 0, prime = 1;
            for(int d = 2; d * d <= t; ++d) {
                if(t % d) continue;
                vis[col[d]] = 1;
                prime = 0;
                while(t % d == 0) t /= d;
                if(t == 1) break;
            }
            if(t > 1 && !prime) vis[col[t]] = 1;
            for(int d = 1; d < 10; ++d) if(!vis[d]) { cur = d; break;}
            col[i] = cur;
            maxc = max(maxc, cur);
        }
        cout << maxc << endl;
        for(int i = 2; i <= n + 1; ++i) cout << col[i] << " \n"[i == n + 1];
    }

    return 0;
}
