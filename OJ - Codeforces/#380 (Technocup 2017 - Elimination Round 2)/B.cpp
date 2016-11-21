//
//  Created by TaoSama on 2016-11-20
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a, b, k;
char s[N];

struct Node {
    int l, r, num;
    bool operator<(const Node& rhs) const {
        return num < rhs.num;
    }
};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &a, &b, &k) == 4) {
        scanf("%s", s + 1);

        vector<int> ones; ones.push_back(0);
        for(int i = 1; i <= n; ++i)
            if(s[i] == '1') ones.push_back(i);
        ones.push_back(n + 1);

        priority_queue<Node> q;

        int sum = 0;
        vector<int> ans;
        for(int i = 1; i < ones.size(); ++i) {
            int l = ones[i - 1] + 1, r = ones[i] - 1;
            int num = (r - l + 1) / b;
            for(int j = l + b - 1; j <= r; j += b)
				ans.push_back(j);
        }
		ans.resize(ans.size() - a + 1);

        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
    }

    return 0;
}
