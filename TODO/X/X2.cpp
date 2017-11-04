#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct MCMF {
    static const int V = 1e3 + 10, E = 1e5 + 10;
    struct Edge {
        int v, nxt;   // 静态邻接表存储网络流的边
        double cost;  // 边权
        int cap;      // 残余流量
    } edge[E];
    int head[V], cnt;  // 静态邻接表头，边数

    int src, des;       //超级源点、超级汇点
    void init(int n) { // 初始化点数
        cnt = 0; memset(head, -1, sizeof head); // 清空静态邻接表
        src = 0, des = n + 1;  // 设置超级源点、超级汇点
    }

    void addEdge(int u, int v, double c, int w1, int w2 = 0) {
        edge[cnt] = {v, head[u], c, w1};
        head[u] = cnt++;
        edge[cnt] = {u, head[v], -c, w2};
        head[v] = cnt++;
    }

    static constexpr double EPS = 1e-8;
    int sgn(double x) { return x < -EPS ? -1 : x > EPS;}

    double d[V];
    int in[V], delta[V], pre[V];
    bool spfa() {
        deque<int> q; q.push_back(src);
        for(int i = src; i <= des; ++i) d[i] = INF, in[i] = false;
        delta[src] = INF; d[src] = 0; in[src] = true;
        while(q.size()) {
            int u = q.front(); q.pop_front();
            in[u] = false;
            for(int i = head[u]; ~i; i = edge[i].nxt) {
                int v = edge[i].v, cap = edge[i].cap; double cost = edge[i].cost;
                if(cap > 0 && sgn(d[v] - (d[u] + cost)) > 0) {
                    delta[v] = min(delta[u], cap);
                    d[v] = d[u] + cost;
                    pre[v] = i;
                    if(!in[v]) {
                        in[v] = true;
                        if(q.size() && sgn(d[v] - d[q.front()]) <= 0) q.push_front(v);
                        else q.push_back(v);
                    }
                }
            }
        }
        return sgn(d[des] - INF) != 0;
    }

    void minCostMaxFlow(int& flow, double& cost) {
        while(spfa()) {
            flow += delta[des];
            cost += d[des] * delta[des];
            for(int i, u = des; u != src; u = edge[i ^ 1].v) {
                i = pre[u];
                edge[i].cap -= delta[des];
                edge[i ^ 1].cap += delta[des];
            }
        }
    }
} mcmf;

int n, m;
const int D = 10000;    // 大于sum{newP_i*cnt_i}

int main() {
    int n, m; scanf("%d%d", &n, &m);  //读入点数 边数

    mcmf.init(n);
    for(int i = 1; i <= m; ++i) {
        int u, v, c; double p, plimit;  // u->v 花费 概率 概率上限
        scanf("%d%d%d%lf%lf", &u, &v, &c, &p, &plimit);

        // 对应文中求的那个x, 即容量，+0.5为了防止舍入误差
        int cap = log(1 - plimit) / log(1 - p) + 0.5;
        // 新的边权计算
        double cost = c * D + (-log(1 - p));
        mcmf.addEdge(u, v, cost, cap);  //加边
    }

    int flow = 0; double cost = 0;  // 最终流量， 最终花费

    int sCnt; scanf("%d", &sCnt);
    for(int i = 1; i <= sCnt; ++i) {
        int s, have; scanf("%d%d", &s, &have); // 仓库s 容量have
        mcmf.addEdge(mcmf.src, s, 0,  have);  // 超级源点向所有仓库连边
    }

    int tCnt; scanf("%d", &tCnt);
    for(int i = 1; i <= tCnt; ++i) {
        int t, need; scanf("%d%d", &t, &need); // 需求城市t 需求need
        // 提前减去只是为了保证最终如果是0的话，那么所有要求都被满足了
        flow -= need;
        mcmf.addEdge(t, mcmf.des, 0, need);  // 需求城市向超级汇点连边
    }

    mcmf.minCostMaxFlow(flow, cost);  // 跑最小费用最大流
    assert(flow == 0);  // 保证需求一定被满足了 没满足会RE 如果题目更改的话 if判断一下就好

    // cost对D的商就是总花费
    int totCost = cost / D;
    // cost对D的余数，负数负回来，再用e的幂搞回去，1减的再减回去就是原来的答案了
    double prob = 1 - exp(-fmod(cost, D));
    printf("%d %.10f\n", totCost, prob);

    return 0;
}

/*
Sample Input:
2 1

1 2 5 0.3 0.9

1
1 2

1
2 2

Sample Output:
10 0.51
*/
