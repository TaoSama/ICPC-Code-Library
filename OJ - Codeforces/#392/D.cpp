//
//  Created by TaoSama on 2017-01-19
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
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int b;
char s[N];
int f[N], pre[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> b >> (s + 1)) {
        int n = strlen(s + 1);

        memset(f, 0x3f, sizeof f);
        f[n + 1] = 0;
        for(int i = n; i; --i) {
            if(s[i] == '0') {
                f[i] = f[i + 1] + 1;
                pre[i] = i + 1;
                continue;
            }
            long long cur = s[i] - '0';
            for(int j = i + 1; j <= n + 1 && cur < b; ++j) {
                if(f[i] > f[j] + 1) {
                    f[i] = f[j] + 1;
                    pre[i] = j;
                }
                cur = cur * 10 + s[j] - '0';
            }
        }

        int p = 1;
        vector<int> path(1, 1);
        while(p != n + 1) {
            path.push_back(pre[p]);
            p = pre[p];
        }

        long long ans = 0;
        for(int i = 0; i + 1 < path.size(); ++i) {
            int cur = 0;
            for(int j = path[i]; j < path[i + 1]; ++j)
                cur = cur * 10 + s[j] - '0';
            ans = ans * b + cur;
        }
        cout << ans << endl;

//        prln(f[1]);
    }

    return 0;
}
