//
//  Created by TaoSama on 2015-07-31
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
#include <sstream>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[35];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string s;
    while(getline(cin, s)) {
        n = 0; int x;
        stringstream ss(s);
        while(ss >> x) {
            a[++n] = x;
        }
        for(int i = 1; i <= n; ++i)
            cout << a[i] << (i == n ? '\n' : ' ');
        for(int i = 1; i <= n; ++i) {
            int maxv = 1;
            for(int j = 1; j <= n - i + 1; ++j)
                if(a[j] > a[maxv]) maxv = j;
            if(maxv == n - i + 1) continue;
            if(maxv != 1) {
                cout << n - maxv + 1 << ' ';
                reverse(a + 1, a + maxv + 1);
            }
            cout << i << ' ';
            reverse(a + 1, a + n - i + 2);
//          cout << "      ";for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
        }
        cout << "0\n";
    }
    return 0;
}
