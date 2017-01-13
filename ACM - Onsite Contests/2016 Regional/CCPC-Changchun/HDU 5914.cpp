//
//  Created by TaoSama on 2016-10-04
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int ans[] = {0, 0, 0, 0, 1, 1, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9, 10, 11, 12, 13, 14};

void gao() {
    for(int i = 1; i <= 20; ++i) {
        ans[i] = INF;
        for(int s = 0; s < 1 << i; ++s) {
            vector<int> v;
            for(int j = 0; j < i; ++j) {
                if(s >> j & 1) continue;
                v.push_back(j + 1);
            }
            bool ok = false;
            for(int x = 0; x < v.size() && !ok; ++x) {
                for(int y = x + 1; y < v.size() && !ok; ++y) {
                    for(int z = y + 1; z < v.size() && !ok; ++z) {
                        int b[] = {v[x], v[y], v[z]};
                        sort(b, b + 3);
                        if(b[0] + b[1] > b[2] && b[2] - b[0] < b[1]) ok = true;
                    }
                }
            }
            if(!ok) ans[i] = min(ans[i], __builtin_popcount(s));
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//    gao();
//  for(int i = 1; i <= 20; ++i) printf("%d, ", ans[i]);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        static int kase = 0 ;
        printf("Case #%d: %d\n", ++kase, ans[n]);
    }

    return 0;
}
