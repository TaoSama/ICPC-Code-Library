//
//  Created by TaoSama on 2016-07-10
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



int main() {
#ifdef LOCAL
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        vector<string> v(n);
        getchar();
        for(int i = 0; i < n; ++i) {
            char buf[50]; gets(buf);
            v[i] = buf;
        }
        sort(v.begin(), v.end(), [](string x, string y) {
            set<int> a, b;
            for(auto c : x) if(c != ' ') a.insert(c);
            for(auto c : y) if(c != ' ') b.insert(c);
            if(a.size() != b.size()) return a.size() > b.size();
            else return x < y;
        });

        static int kase = 0;
        printf("Case #%d: %s\n", ++kase, v[0].c_str());
    }

#ifdef LOCAL
//    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
