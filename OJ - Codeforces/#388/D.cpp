//
//  Created by TaoSama on 2016-12-20
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

int n, q;
vector<int> bids[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    vector<int> maxBid(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        bids[a].push_back(b);
        maxBid[a] = b;
    }
    vector<pair<int, int> > bidPair;
    for(int i = 1; i <= n; ++i)
        if(maxBid[i]) bidPair.push_back({maxBid[i], i});

    sort(bidPair.begin(), bidPair.end());

    scanf("%d", &q);
    int timStp = 0;
    vector<int> del(n + 1, 0);
    while(q--) {
        int k; scanf("%d", &k);
        ++timStp;
        while(k--) {
            int x; scanf("%d", &x);
            del[x] = timStp;
        }
        int first = 0, second = 0;
        for(int i = bidPair.size() - 1; ~i; --i) {
            int id = bidPair[i].second;
            if(del[id] == timStp) continue;
            if(!first) first = id;
            else if(!second) second = id;
            else break;
        }

        if(!first && !second) puts("0 0");
        else if(second) {
            auto& cur = bids[first];
            printf("%d %d\n", first,
                   *lower_bound(cur.begin(), cur.end(), maxBid[second]));
        } else printf("%d %d\n", first, *bids[first].begin());
    }

    return 0;
}
