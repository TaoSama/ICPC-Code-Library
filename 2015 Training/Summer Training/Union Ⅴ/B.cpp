//
//  Created by TaoSama on 2015-08-31
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

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<int> v;
        for(int i = 1; i <= n; ++i) {
            char op[5]; scanf("%s", op);
            if(op[0] == 'a') {
                int x; scanf("%d", &x);
                auto iter = lower_bound(v.begin(), v.end(), x);
                v.insert(iter, x);
            } else if(op[0] == 'd') {
                int x; scanf("%d", &x);
                auto iter = lower_bound(v.begin(), v.end(), x);
                v.erase(iter);
            } else {
                long long sum = 0;
                for(int i = 2; i < v.size(); i += 5)
                    sum += v[i];
                printf("%I64d\n", sum);
            }
        }
    }
    return 0;
}
