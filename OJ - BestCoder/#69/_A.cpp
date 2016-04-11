//
//  Created by TaoSama on 2016-01-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int a, b, c;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &a, &b, &c);
        int x = -1, y = -1, sum = INF;
        for(int i = 0; i <= c / a; ++i) {
            if((c - i * a) % b == 0) {
                if(i % 2 == 0 && (c - i * a) / b % 2 == 0) {
                    int curx = i;
                    int cury = (c - i * a) / b;
                    if(curx + cury < sum) {
                        sum = curx + cury;
                        x = curx, y = cury;
                    }
                }
            }
        }
        if(~x) printf("%d %d\n", x, y);
        else puts("Impossible");
    }
    return 0;
}
