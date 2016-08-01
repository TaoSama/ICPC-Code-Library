//
//  Created by TaoSama on 2016-07-24
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

int n, k;
int a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();


    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        vector<int> ans;
        for(int i = n, j; i; --i) {
            if(!a[i]) ans.push_back(i);
            else {
                int cnt = 0;
                for(j = ans.size() - 1; ~j; --j) {
                    if(ans[j] >= i + k) {
                        if(++cnt == a[i]) break;
                    }
                }
                ans.insert(ans.begin() + j, i);
            }
//          for(int x : ans) printf("%d ", x); puts("");
        }
        reverse(ans.begin(), ans.end());
        for(int x : ans) printf("%d ", x); puts("");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
