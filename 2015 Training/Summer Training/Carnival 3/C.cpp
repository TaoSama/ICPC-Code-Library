//
//  Created by TaoSama on 2015-08-09
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
pair<int, int> a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a + 1, a + 1 + n);
        int maxv = a[n].first;

        vector<int> l, r;
        long long sum1 = 0, sum2 = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i += 2) {
            if(i == n) {
                if(sum1 > sum2) r.push_back(a[i].second);
                else l.push_back(a[i].second);
            } else {
                if(++cnt & 1) {
                    l.push_back(a[i].second);
                    r.push_back(a[i + 1].second);
                    sum1 += a[i].first; sum2 += a[i + 1].first;
                } else {
                    l.push_back(a[i + 1].second);
                    r.push_back(a[i].second);
                    sum1 += a[i + 1].first; sum2 += a[i].first;
                }
            }
        }

        cout << l.size() << '\n';
        for(auto &x : l) cout << x << ' '; cout << '\n';
        cout << r.size() << '\n';
        for(auto &x : r) cout << x << ' '; cout << '\n';
    }
    return 0;
}
