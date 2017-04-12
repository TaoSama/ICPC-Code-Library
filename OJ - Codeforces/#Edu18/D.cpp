//
//  Created by TaoSama on 2017-03-28
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

long long n, q;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> q) {
        while(q--) {
            long long x; string s; cin >> x >> s;
            for(char c : s) {
                long long lb = x & -x;
                if(c == 'U') {
                    if(x == (n + 1) / 2) continue;
                    long long sb = x + lb;
                    if(sb - ((sb & -sb) >> 1) == x) x += lb;
                    else x -= lb;
                } else {
                    if(lb <= 1) continue;
                    if(c == 'L') x -= lb >> 1;
                    else x += lb >> 1;
                }
            }
            cout << x << '\n';
        }
    }

    return 0;
}
