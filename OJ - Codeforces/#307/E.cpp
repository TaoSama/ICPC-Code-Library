//
//  Created by TaoSama on 2015-06-16
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;
const int B = 1e3;

vector<long long> a[1000], b[1000];
long long add[1000];
int n, q;

void update(int l, int r, int x) {
    for(int i = l; i <= r;) {
        if(i % B == 0 && i + B - 1 <= r) {
            add[i / B] += x;
            i += B;
        } else {
            a[i / B][i % B] += x;
            i++;
        }
    }

    if(l % B) {
        b[l / B] = a[l / B];
        sort(b[l / B].begin(), b[l / B].end());
    }
    if((r + 1) % B) {
        b[r / B] = a[r / B];
        sort(b[r / B].begin(), b[r / B].end());
    }
}

long long query(int x) {
    int l = -1, r = -1;
    for(int i = 0; i <= n / B; ++i) {
//        cout << i << ' ' << x - add[i] << endl;
        auto t = lower_bound(b[i].begin(), b[i].end(), x - add[i]);
        if(t != b[i].end() && *t == x - add[i]) {
            for(int j = 0; j < a[i].size(); ++j) {
                if(a[i][j] == *t) {
                    l = B * i + j + 1;
                    break;
                }
            }
            break;
        }
    }

    for(int i = n / B; i >= 0; --i) {
        auto t = lower_bound(b[i].begin(), b[i].end(), x - add[i]);
        if(t != b[i].end() && *t == x - add[i]) {
            for(int j = a[i].size() - 1; j >= 0; --j) {
                if(a[i][j] == *t) {
                    r = B * i + j + 1;
                    break;
                }
            }
            break;
        }
    }
//    cout << l << ' ' << r << endl;
    return ~l && ~r ? r - l : -1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 0; i <= n / B; ++i) {
            a[i].clear(), b[i].clear();
            add[i] = 0;
        }

        for(int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            a[i / B].push_back(x);
            b[i / B].push_back(x);

        }
        for(int i = 0; i <= n / B; ++i) sort(b[i].begin(), b[i].end());

        while(q--) {
            int op, x, y, z;
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d%d%d", &x, &y, &z);
                update(x - 1, y - 1, z);
//                for(auto &x : a[0]) cout << x << ' '; cout << endl;
//                for(auto &x : b[0]) cout << x << ' '; cout << endl; cout << endl;
            } else {
                scanf("%d", &x);
                printf("%I64d\n", query(x));
            }
        }

    }
    return 0;
}
