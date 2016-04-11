//
//  Created by TaoSama on 2015-11-15
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[5], b[5];

bool judge(int i, int j, int k) {
    //有一边集体相等 a[i]
    if((a[i] == a[j] || a[i] == b[j]) && (a[i] == a[k] || a[i] == b[k]))
        return true;
    //b[i]
    if((b[i] == a[j] || b[i] == b[j]) && (b[i] == a[k] || b[i] == b[k]))
        return true;

    //两个相等堆起来 i j
    if(a[i] == a[j] && (b[i] + b[j] == a[k] || b[i] + b[j] == b[k])) return true;
    if(a[i] == b[j] && (b[i] + a[j] == a[k] || b[i] + a[j] == b[k])) return true;
    if(b[i] == a[j] && (a[i] + b[j] == a[k] || a[i] + b[j] == b[k])) return true;
    if(b[i] == b[j] && (a[i] + a[j] == a[k] || a[i] + a[j] == b[k])) return true;

    //i k
    if(a[i] == a[k] && (b[i] + b[k] == a[j] || b[i] + b[k] == b[j])) return true;
    if(a[i] == b[k] && (b[i] + a[k] == a[j] || b[i] + a[k] == b[j])) return true;
    if(b[i] == a[k] && (a[i] + b[k] == a[j] || a[i] + b[k] == b[j])) return true;
    if(b[i] == b[k] && (a[i] + a[k] == a[j] || a[i] + a[k] == b[j])) return true;

    //j k
    if(a[k] == a[j] && (b[k] + b[j] == a[i] || b[k] + b[j] == b[i])) return true;
    if(a[k] == b[j] && (b[k] + a[j] == a[i] || b[k] + a[j] == b[i])) return true;
    if(b[k] == a[j] && (a[k] + b[j] == a[i] || a[k] + b[j] == b[i])) return true;
    if(b[k] == b[j] && (a[k] + a[j] == a[i] || a[k] + a[j] == b[i])) return true;

    return false;
}

bool gao() {
    for(int i = 1; i <= 4; ++i)
        for(int j = i + 1; j <= 4; ++j)
            for(int k = j + 1; k <= 4; ++k)
                if(judge(i, j, k)) return true;
    return false;
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 1; i <= 4; ++i)
            scanf("%d%d", a + i, b + i);
        puts(gao() ? "Yes" : "No");
    }
    return 0;
}
