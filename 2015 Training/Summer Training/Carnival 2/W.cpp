//
//  Created by TaoSama on 2015-08-02
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

int a, b, n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a >> b >> n) {
        int gcd = __gcd(a, b);
        vector<int> div;
        for(int i = 1; i * i <= gcd; ++i) {
            if(gcd % i == 0) {
                div.push_back(i);
                if(i != gcd / i)
                    div.push_back(gcd / i);
            }
        }
        sort(div.begin(), div.end());
//      for(int &i: div) cout << i << endl;
        for(int i = 1; i <= n; ++i) {
            int l, r; cin >> l >> r;
            auto iter = upper_bound(div.begin(), div.end(), r); --iter;
            if(*iter >= l) cout << *iter << '\n';
            else cout << "-1\n";
        }
    }
    return 0;
}
