//
//  Created by TaoSama on 2015-09-01
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

int n;
char s[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        scanf("%s", s);
        int dif1 = 0, dif2 = 0;
        int t1 = 0, t2 = 1;
        for(int i = 0; s[i]; ++i) {
            if(s[i] - '0' != t1) ++dif1;
            if(s[i] - '0' != t2) ++dif2;
            t1 ^= 1; t2 ^= 1;
        }
        cout << min(dif1, dif2) << '\n';
    }
    return 0;
}
