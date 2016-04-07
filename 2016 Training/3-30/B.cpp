//
//  Created by TaoSama on 2016-03-30
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

#define y1 asdasdasd

int x1[2], y1[2], x2[2], y2[2];

bool intersect(int i, int j) {
    int minx = max(x1[i], x1[j]);
    int maxx = min(x2[i], x2[j]);
    int miny = max(y1[i], y1[j]);
    int maxy = min(y2[i], y2[j]);
    if(minx > maxx || miny > maxy) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 2; ++i) {
            scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
            if(x1[i] > x2[i]) {
                swap(x1[i], x2[i]);
                swap(y1[i], y2[i]);
            }
            if(y1[i] > y2[i]) {
                swap(y1[i], y2[i]);
            }
        }
        puts(intersect(0, 1) ? "Hit" : "Miss");
    }
    return 0;
}
