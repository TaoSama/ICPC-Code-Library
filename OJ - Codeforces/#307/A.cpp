//
//  Created by TaoSama on 2015-06-13
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
const int N = 1e5 + 10;

int n;
struct P {
    int m, id, p;
    bool operator < (const P& rhs) const {
        return m > rhs.m;
    }
} a[2005];

bool cmp(P x, P y) {
    return x.id < y.id;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            cin >> a[i].m;
            a[i].id = i;
        }
        sort(a + 1, a + 1 + n);
        int last = 1;
        a[1].p = 1;
        for(int i = 2; i <= n; ++i) {
            if(a[i].m == a[i - 1].m) {
                a[i].p = last;
            } else {
                a[i].p = i;
                last = i;
            }
        }
        sort(a + 1, a + 1 + n, cmp);
        for(int i = 1; i <= n; ++i)
            cout << a[i].p << ' ';
        cout << endl;
    }
    return 0;
}
