//
//  Created by TaoSama on 2016-11-13
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

typedef long long LL;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    vector<LL> v{1, 199981, 199982, 199983, 199984, 199985, 199986,
                 199987, 199988, 199989, 199990, 200000, 200001, 1599981, 1599982,
                 1599983, 1599984, 1599985, 1599986, 1599987, 1599988, 1599989,
                 1599990, 2600000, 2600001, 13199998, 35000000, 35000001, 35199981,
                 35199982, 35199983, 35199984, 35199985, 35199986, 35199987,
                 35199988, 35199989, 35199990, 35200000, 35200001, 117463825,
                 500000000, 500000001, 500199981, 500199982, 500199983, 500199984,
                 500199985, 500199986, 500199987, 500199988, 500199989, 500199990,
                 500200000, 500200001, 501599981, 501599982, 501599983, 501599984,
                 501599985, 501599986, 501599987, 501599988, 501599989, 501599990,
                 502600000, 502600001, 513199998, 535000000, 535000001, 535199981,
                 535199982, 535199983, 535199984, 535199985, 535199986, 535199987,
                 535199988, 535199989, 535199990, 535200000, 535200001, 1111111110LL};
//    LL sum = 0;
//    for(LL i = 1; i < 1e9; ++i) {
//        LL x = i;
//        while(x) {
//            sum += x % 10 == 1;
//            x /= 10;
//        }
//        if(sum == i) {
//            cout << i << endl;
//            v.push_back(i);
//        }
//    }
//    cout << v.size() << endl;
//    for(auto x : v) cout << x << ",";
    string s;
    while(cin >> s) {
        if(s.size() > 12) cout << v.size() << ' ' << v.back() << '\n';
        else {
            LL x = stoll(s);
            auto iter = upper_bound(v.begin(), v.end(), x);
            prln(*iter);
            cout << iter - v.begin() + 1 << ' ' << *--iter << '\n';
        }
    }

    return 0;
}
