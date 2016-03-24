//
//  Created by TaoSama on 2015-07-18
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

int x;
pair<int, int> a[7];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a[1].first >> a[1].second) {
        if(a[1].first > a[1].second)
            swap(a[1].first, a[1].second);
        for(int i = 2; i <= 6; ++i) {
            cin >> a[i].first >> a[i].second;
            if(a[i].first > a[i].second)
                swap(a[i].first, a[i].second);
        }

        sort(a + 1, a + 7);

//      for(int i = 1; i <= 6; ++i)
//            cout << a[i].first << ' ' << a[i].second << endl;

        bool ok = true;
        for(int i = 1; i <= 6; i += 2) {
            if(a[i].first != a[i + 1].first || a[i].second != a[i + 1].second) {
                ok = false;
                break;
            }
        }

        if(ok) {
            ok = false;
            if(a[3].first == a[5].first) {
                if(a[3].second == a[1].first && a[5].second == a[1].second ||
                        a[3].second == a[1].second && a[5].second == a[1].first)
                    ok = true;
            }
            if(a[3].second == a[5].second) {
                if(a[3].first == a[1].first && a[5].first == a[1].second ||
                        a[3].first == a[1].second && a[5].first == a[1].first)
                    ok = true;
            }
        }

        if(ok) cout << "POSSIBLE\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}
