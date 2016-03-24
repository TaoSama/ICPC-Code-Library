//
//
//
//  Created by TaoSama on 2015-04-17
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
const double EPS = 1e-9;

int n, m, A, B;
int ux[1005], uy[1005], tx[105], ty[105];

long long calc(long long &x, long long &y) {
    long long ret = 0;
    for(int i = 1; i <= A; ++i)
        ret += 0LL + (x - ux[i]) * (x - ux[i])
               + (y - uy[i]) * (y - uy[i]);

    long long Min = INF;
    for(int i = 1; i <= B; ++i)
        Min = min(Min, abs(x - tx[i]) + abs(y - ty[i]));
    ret += Min;
    return ret;
}

long long checkY(long long &x) {
    long long ly = 0, ry = m, ret = 1e15;
    while(ly < ry) {
        long long lly = ly + ry >> 1;
        long long rry = lly + ry >> 1;
        long long ans1 = calc(x, lly), ans2 = calc(x, rry);
        if(ans1 > ans2) ly = lly;
        else ry = rry;
        ret = min(ret, min(ans1, ans2));
    }
    //y = ly;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d%d%d", &n, &m, &A, &B);
        for(int i = 1; i <= A; ++i) scanf("%d%d", ux + i, uy + i);
        for(int i = 1; i <= B; ++i) scanf("%d%d", tx + i, ty + i);

		long long ans = 1e15;
        long long lx = 0, rx = n;
        while(lx < rx) {
            long long llx = lx + rx >> 1;
            long long rrx = llx + rx >> 1;
            long long ans1 = checkY(llx), ans2 = checkY(rrx);
            if(ans1 > ans2) lx = llx;
            else rx = rrx;
            ans = min(ans, min(ans1, ans2));
        }

        //long long ans = checkY(lx);
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
