//
//  Created by TaoSama on 2015-07-10
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
long long ans;
int s[20][N], b[20][N], t[N], p[N];

#define root 1, n, 1
#define lson l, m, d + 1
#define rson m + 1, r, d + 1

void add(int *b, int i, int e, int v) {
    for(; i <= e; i += i & -i) b[i] += v;
}

int sum(int *b, int i, int s) {
    int ret = 0;
    for(; i >= s; i -= i & -i) ret += b[i];
    return ret;
}

int binSearch(int v, int l, int r, int d) {
//  for(int i = l; i <= r; ++i) pr(s[d][i]); cout <<endl;
    while(l < r) {
        int m = l + r >> 1;
        if(s[d][m] >= v) r = m;
        else l = m + 1;
    }
    if(s[d][l] > v) --l;
//     prln(l);
    return l;
}

void build(int l, int r, int d) {
    if(l == r) {
        scanf("%d", &s[d][l]);
        p[s[d][l]] = l;
        ans += l - 1 - sum(t, s[d][l], 1);
        add(t, s[d][l], n, 1);
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    merge(&s[d + 1][l], &s[d + 1][m] + 1, &s[d + 1][m + 1],
          &s[d + 1][r] + 1, &s[d][l]);
}

//ͳ��[l,r]��ɾ�����ĸ���
void update(int o, int v, int l, int r, int d) {
    int k = lower_bound(s[d] + l, s[d] + r + 1, v) - s[d];
    //int k = binSearch(v, l, r, d);
    add(b[d], k, r, 1); //���°���ɾ������BIT����

    if(l == r) return;
    int m = l + r >> 1;
    if(o <= m) update(o, v, lson);
    else update(o, v, rson);
}

void query(int L, int R, int v, bool isLess, int l, int r, int d) {
    if(L <= l && r <= R) {
        //�ҵ����������С�ڵ�����������������λ�� int k = binSearch(v, l, r, d);
        int k = upper_bound(s[d] + l, s[d] + r + 1, v) - s[d] - 1;
        //k(v)λ�û�û��ɾ�� ���԰�������������ν
        int del = sum(b[d], k, l);  //С��v������ɾ���ĸ���
//      pr(k), prln(del);
        if(isLess) {
            k = r - k;  //����v�����ĸ���
            del = sum(b[d], r, l) - del; //����v������ɾ���ĸ���
        } else k = k - l + 1; //С��v�����ĸ���
//      cout << (isLess ? "Less" : "Big") << ": ";
//      pr(k); prln(del);
        ans -= k - del;

        return;
    }
    int m = l + r >> 1;
    if(L <= m) query(L, R, v, isLess, lson);
    if(R > m) query(L, R, v, isLess, rson);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        ans = 0;
        memset(t, 0, sizeof t);
        memset(b, 0, sizeof b);
        build(root);
        while(q--) {
            int x; scanf("%d", &x);
            printf("%lld\n", ans);
            if(ans && q) {
                if(p[x] != 1) query(1, p[x] - 1, x, true, root);
                if(p[x] != n) query(p[x] + 1, n, x, false, root);
                update(p[x], x, root);
            }
//            cout << endl;
        }
    }
    return 0;
}
