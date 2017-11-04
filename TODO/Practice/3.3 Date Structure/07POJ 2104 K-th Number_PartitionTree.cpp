//
//  Created by TaoSama on 2015-06-23
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, q, s[N];
int dat[20][N], toleft[20][N]; //i->i+1������ӵ����ĸ���

//������������[l,r] d:=�ݹ����
#define root 1, n, 1
#define lson l, m, d + 1
#define rson m + 1, r, d + 1

void push_down(int l, int r, int d) {
    int m = l + r >> 1, lsame = m - l + 1;
    for(int i = l; i <= r; ++i)
        if(dat[d][i] < s[m]) --lsame;

    int lpos = l, rpos = m + 1;
    for(int i = l; i <= r; ++i) {
        if(dat[d][i] < s[m])
            dat[d + 1][lpos++] = dat[d][i];
        else if(dat[d][i] == s[m] && lsame)
            dat[d + 1][lpos++] = dat[d][i], --lsame;
        else dat[d + 1][rpos++] = dat[d][i];

        toleft[d][i] = toleft[d][l - 1] + lpos - l;
        //lpos���+1�˾Ͳ���+1��
    }
}

void build(int l, int r, int d) {
    if(l == r) return;

    int m = l + r >> 1;
    push_down(l, r, d); //partition
    build(lson);
    build(rson);
}

//findkth��query�ںϵ�һ����
int findkth(int L, int R, int k, int l, int r, int d) {
    if(l == r) return dat[d][l];

    int m = l + r >> 1;
    int cnt = toleft[d][R] - toleft[d][L - 1];
    if(cnt >= k) {
        //l+��ѯ�������toleft�ĸ���
        int LL = l + toleft[d][L - 1] - toleft[d][l - 1];
        int RR = LL + cnt - 1;  //��˵�+��ѯ����toleft�ĸ���
        return findkth(LL, RR, k, lson);
    } else {
        //R+��ѯ�����ұ�toleft�ĸ���(�൱�ڽ� �²�ѯ���� ���Ҽ���, �������ڻ����������ȶ��Ե�����)
        int RR = R + toleft[d][r] - toleft[d][R];
        //RR-(R-L+1-cnt)+1 ��ȥԭ��ѯ����toleft�ĸ���
        int LL = RR - (R - L - cnt);
        return findkth(LL, RR, k - cnt, rson);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", s + i);
            dat[1][i] = s[i];
        }
        sort(s + 1, s + 1 + n);
        build(root);
        while(q--) {
            int l, r, k; scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", findkth(l, r, k, root));
        }
    }
    return 0;
}
