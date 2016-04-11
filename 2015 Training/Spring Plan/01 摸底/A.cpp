//
//  ACdream 1680 娜娜梦游仙境系列——诡异的钢琴
//
//  Created by TaoSama on 2015-04-11
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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

double a[5];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if(a[0] / 4 == a[1] / 5 && a[1] / 5 == a[2] / 6)
            cout << "major" << endl;
        else if(a[0] / 10 == a[1] / 12 && a[1] / 12 == a[2] / 15)
            cout << "minor" << endl;
        else cout << "noise" << endl;
    }
    return 0;
}
