//
//  Created by TaoSama on 2015-08-03
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
deque<int> dq;

bool isAscending() {
    for(int i = 1; i < dq.size(); ++i)
        if(dq[i - 1] > dq[i]) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n) {
        dq.clear();
        for(int i = 1; i <= n; ++i) {
            int x; cin >> x;
            dq.push_back(x);
        }

        vector<int> ans;
        while(!isAscending()) {
            if(dq[0] != n && dq[0] > dq[1]) {
                swap(dq[0], dq[1]);
                ans.push_back(1);
            } else {
                dq.push_front(dq.back());
                dq.pop_back();
                ans.push_back(2);
            }
        }

        for(int i = ans.size() - 1; i >= 0; --i) cout << ans[i];
        cout << '\n';
    }
    return 0;
}
