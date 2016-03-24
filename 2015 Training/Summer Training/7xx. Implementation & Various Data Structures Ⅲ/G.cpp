//
//  Created by TaoSama on 2015-07-25
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

int n, bfs[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            int x; cin >> x;
            bfs[x] = i; //record each node's distance towards root;
        }

        int root; cin >> root;
        stack<int> s; s.push(root);

        vector<int> ans[n + 1];
        for(int i = 2; i <= n; ++i) {
            int x; cin >> x;
            while(true) {
                //if not current top node's brother, then its son
                //due to brothers appear together except root
                int u = s.top();
                if(bfs[x] > bfs[u] + 1 || u == root) {
                    ans[u].push_back(x);
                    s.push(x);
                    break;
                } else s.pop(); //the root is always in the stack
            }
        }
        for(int i = 1; i <= n; ++i) {
            cout << i << ":";
            for(auto &j : ans[i]) cout << ' ' << j;
            cout << '\n';
        }
    }
    return 0;
}
