//
//  Created by TaoSama on 2015-07-23
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
#include <stack>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
typedef pair<int, int> P;
P a[30];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        char c; int x, y;
        cin >> c >> x >> y;
        a[c - 'A'] = {x, y};
    }
    cin.get();

    string line;
    while(getline(cin, line)) {
        stack<P> s;
        long long ans = 0;
        bool error = false;
        for(auto &i : line) {
            if(isalpha(i)) s.push(a[i - 'A']);
            else if(i == ')') {
                P b = s.top(); s.pop();
                P a = s.top(); s.pop();
                if(a.second != b.first) {
                    error = true;
                    break;
                }
                ans += 1LL * a.first * a.second * b.second;
                s.push({a.first, b.second});
            }
        }
        if(error) cout << "error\n";
        else cout << ans << '\n';
    }
    return 0;
}
