//
//  Created by TaoSama on 2015-05-11
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, x[1005], y[1005], z[1005];

bool judge(int gcd, int a, int b) {
    if(a % gcd == 0 || b % gcd == 0) return true; //边界满足
    if(a < 0 && b > 0) return true;
    //本身区间相交 必然不能takeoff
    if(b / gcd - a / gcd > 0) return true; //跨过一个gcd的倍数
    return false;
}

bool solve() {
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            int gcd = __gcd(x[i], x[j]);
            if(judge(gcd, y[j] - z[i], z[j] - y[i]))
                return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            scanf("%d%d%d", x + i, y + i, z + i);

        puts(solve() ? "Can Take off" : "Cannot Take off");
    }
    return 0;
}

/*
首先枚举出两组x，y，z。

然后判断这两组是否能找到一个d，使得满足题目条件。

现在假设a、b，有a*x1+y1≤d≤a*x1+z1和b*x2+y2≤d≤b*x2+z2；

若两段区间有交集，必有a*x1+y1≤b*x2+z2且b*x2+y2≤a*x1+z1；

化简得a*x1-b*x2≤z2-y1 且a*x1-b*x2≥y2-z1;

若a，b有整数解，根据拓展欧几里得定理ax1+bx2=u有整数解的情况为u%gcd(x1,x2)==0;

所以若存在y2-z1≤u≤z2-y1，使得u%gcd(x1,x2)==0即可。
