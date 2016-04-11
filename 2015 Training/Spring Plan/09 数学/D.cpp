//
//  Created by TaoSama on 2015-09-24
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

char s[1005];
int n, have[10];

bool judge() {
    bool can = false;
    for(int i = 0; i < 1000; ++i) {
        if(i % 8) continue;
        int d = 0, t = i, cur[10] = {};
        while(t) {
            cur[t % 10]++;
            t /= 10;
            d++;
        }
        if(d == 0) { //000
            if(have[0] >= 3) can = true;
        } else {
            if(d == 1) cur[0] += 2;
            if(d == 2) cur[0] += 1;
            bool ok = true;
            for(int j = 0; j < 10; ++j)
                if(have[j] < cur[j]) ok = false;
            can = ok;
        }
        if(can) break;
    }
    return can;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s) == 1) {
        memset(have, 0, sizeof have);
        for(int i = 0; s[i]; ++i)
            have[s[i] - '0']++;

        n = strlen(s);
        if(n <= 3) {
            sort(s, s + n);
            bool ok = false;
            do {
                int x = atoi(s);
                if(x % 8 == 0) {
                    ok = true;
                    break;
                }
            } while(next_permutation(s, s + n));
            puts(ok ? "YES" : "NO");
            continue;
        }

        puts(judge() ? "YES" : "NO");
    }
    return 0;
}
