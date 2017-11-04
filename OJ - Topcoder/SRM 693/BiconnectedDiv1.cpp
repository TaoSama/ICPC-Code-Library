#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class BiconnectedDiv1 {
public:
    int f[105][2]; //0 for v, 1 for e
    int minimize(vector<int> w1, vector<int> w2) {
        int sum = accumulate(w1.begin(), w1.end(), 0);
        sum += accumulate(w2.begin(), w2.end(), 0);

        int V = w1.size();
        if(V == 2) return sum;

        memset(f, 0, sizeof f);
        f[2][0] = w1[1];
        for(int i = 3; i < V; ++i) {
            int v = i - 1, e = i - 2;
            f[i][0] = max(f[i][0], max(f[i - 1][0], f[i - 1][1]) + w1[v]);
            f[i][1] = max(f[i][1], max(f[i - 2][0], f[i - 2][1]) + w2[e]);
        }
        sum = sum - max(f[V - 1][0], f[V - 1][1]);
        return sum;
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x) { return x < 0;}
template<class I, class O> vector<pair<I, O>> getTestCases() {
    return {
        { { {1, 2}, {3} }, {6} },
        { { {3, 0, 4}, {1, 2} }, {10} },
        { { {3, 3, 3, 3}, {3, 6, 3} }, {18} },
        { { {7243, 7525, 8467, 6351, 9453, 8456, 8175, 5874, 6869, 7400, 6438, 8926, 6876}, {2642, 1743, 3546, 4100, 2788, 3019, 2678, 1935, 1790, 2674, 3775, 1920} }, {46729} },
        // Your custom test goes here:
        //{ { {}, {}}, {} },
    };
}

//------------------------------------------------------------------------------
// Tester code:
#define DISABLE_COLORS

#include "tester.cpp"
struct input {
    vector<int> p0; vector<int> p1;

    int run(BiconnectedDiv1* x) {
        return x->minimize(p0, p1);
    }
    void print() {
        //Tester::printArgs(p0,p1);
    }
};

int main() {
    return Tester::runTests<BiconnectedDiv1>(
               getTestCases<input, Tester::output<int>>(), disabledTest,
               250, 1466870330, CASE_TIME_OUT, Tester::COMPACT_REPORT
           );
}
// CUT end
