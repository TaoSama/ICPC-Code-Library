//
//	Minimum Inversion Number
//
//  Created by TaoSama on 2015-04-19
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
const int N = 5050;

struct Node {
    int l, r;
    int sum;
} segTree[N * 3];
int n, a[N];

void Build(int i, int l, int r) {
    segTree[i].l = l;
    segTree[i].r = r;
    if(l == r) {
        segTree[i].sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    Build(i << 1, l, mid);
    Build((i << 1) | 1, mid + 1, r);
    segTree[i].sum = 0;
}
void add(int i, int t, int val) {
    segTree[i].sum += val;
    if(segTree[i].l == segTree[i].r) {
        return;
    }
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if(t <= mid) add(i << 1, t, val);
    else add((i << 1) | 1, t, val);
}
int sum(int i, int l, int r) {
    if(segTree[i].l == l && segTree[i].r == r)
        return segTree[i].sum;
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if(r <= mid) return sum(i << 1, l, r);
    else if(l > mid)  return sum((i << 1) | 1, l, r);
    else return sum(i << 1, l, mid) + sum((i << 1) | 1, mid + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) != EOF) {
        Build(1, 0, n - 1);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += sum(1, a[i], n - 1);
            add(1, a[i], 1);
        }
        int Min = ans;
        for(int i = 0; i < n; i++) {
            ans -= a[i]; //减少的逆序数
            ans += n - a[i] - 1;
            if(ans < Min) Min = ans;
        }
        printf("%d\n", Min);
    }
    return 0;
}
