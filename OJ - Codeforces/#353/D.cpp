//
//  Created by TaoSama on 2016-05-17
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

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        map<int, int> ls, rs;
        set<int> st;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if(!st.size()) {}
            else {
                auto it = st.lower_bound(x);
                if(it == st.end()) rs[*--it] = x;
                else {
                    if(!ls.count(*it)) ls[*it] = x;
                    else rs[*--it] = x;
                }
                printf("%d ", *it);
            }
            st.insert(x);
        }
        puts("");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
