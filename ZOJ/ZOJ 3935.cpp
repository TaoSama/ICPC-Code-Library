//
//  Created by TaoSama on 2016-04-10
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

int tri[N], hexo[N];

bool isLeap(int x) {
    return x % 4 == 0 && x % 100 || x % 400 == 0;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; ; ++i) { //1414
        tri[i] = i * (i + 1) / 2;
        if(tri[i] > 1e6) {
            break;
        }
    }
    for(int i = 1; ; ++i) { //708
        hexo[i] = i * (2 * i - 1);
        if(hexo[i] > 1e6) {
            break;
        }
    }

    for(int i = 2016; i <= 990528; ++i) {
        if(!isLeap(i)) continue;
        if(!binary_search(hexo + 1, hexo + 708, i)) continue;
        if(!binary_search(tri + 1, tri + 1414, i)) continue;
        printf("%d\n", i);
    }
    return 0;
}
