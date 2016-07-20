//
//  Created by TaoSama on 2016-06-15
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

int n;
vector<string> cmd = {"insert", "getMin", "removeMin"};

int getIdx(string s) {
    return find(cmd.begin(), cmd.end(), s) - cmd.begin();
}

priority_queue<int, vector<int>, greater<int> > q;
vector<pair<int, int> > ans;

void push(int x) {
    q.push(x);
    ans.push_back({0, x});
}
void pop() {
    q.pop();
    ans.push_back({2, -INF});
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        while(q.size()) q.pop();
        ans.clear();
        for(int i = 1; i <= n; ++i) {
            char op[50]; scanf("%s", op);
            int idx = getIdx(op), y = -INF;
            if(idx == 0) {
                scanf("%d", &y);
                push(y);
            } else if(idx == 1) {
                scanf("%d", &y);
                if(q.empty() || q.top() > y) {
                    push(y);
                } else if(q.top() < y) {
                    while(q.size() && q.top() < y) {
                        pop();
                    }
                    if(q.empty() || q.size() && q.top() != y) {
                        push(y);
                    }
                }
                ans.push_back({idx, y});
            } else {
                if(q.empty()) push(0);
                pop();
            }
        }
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i) {
            int x, y; tie(x, y) = ans[i];
            printf("%s", cmd[x].c_str());
            if(y != -INF) printf(" %d\n", y);
            else puts("");
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
