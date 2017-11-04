#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class SettingShield {
public:
    int protection[N], left[N], right[N];
    long long getOptimalCost(int n, int h, int t,
                             vector<int> val0, vector<int> a, vector<int> b, vector<int> m) {
        protection[0] = val0[0];
        for(int i = 1; i < n; ++i)
            protection[i] = (1LL * a[0] * protection[i - 1] + b[0]) % m[0];

        left[0] = val0[1];
        right[0] = val0[2];
        for(int i = 1; i < h; ++i) {
            left[i] = min(n - 1LL, (1LL * a[1] * left[i - 1] + b[1]) % m[1]);
            int dist = right[i - 1] - left[i - 1];
            right[i] = min(n - 1LL, left[i] + (1LL * a[2] * dist + b[2]) % m[2]);
        }


        return 0;
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x) { return x < 0;}
template<class I, class O> vector<pair<I, O>> getTestCases() {
    return {
        { { 3, 3, 10, {4, 0, 1}, {1, 1, 1}, {3, 1, 1}, {6, 10, 10} }, {8LL} },
        { { 3, 1, 10, {4, 0, 1}, {1, 1, 1}, {3, 1, 1}, {6, 10, 10} }, {40LL} },
        { { 6, 3, 2, {4, 1, 3}, {2, 4, 3}, {3, 2, 2}, {20, 9, 4} }, {22LL} },
        { { 12, 6, 4, {4, 3, 7}, {2, 4, 5}, {3, 8, 7}, {40, 23, 13} }, {108LL} },
        { { 50, 77, 4, {4, 11, 30}, {9, 40, 7}, {33, 8, 12}, {20000, 200, 13} }, {79111LL} },
        { { 555, 120, 4, {10000000, 301, 520}, {9999999, 9999998, 9999997}, {9995999, 0, 9919999}, {1999999, 9993999, 9299999} }, {40000000LL} },
        { { 501, 2, 2, {10000000, 500, 500}, {10000000, 10000000, 10000000}, {0, 0, 500}, {1000003, 10000000, 10000000} }, {10000000LL} },
        // Your custom test goes here:
        //{ { , , , {}, {}, {}, {}}, {} },
    };
}

//------------------------------------------------------------------------------
// Tester code:
#define DISABLE_COLORS

#include "tester.cpp"
struct input {
    int p0; int p1; int p2; vector<int> p3; vector<int> p4; vector<int> p5;
    vector<int> p6;

    long long run(SettingShield* x) {
        return x->getOptimalCost(p0, p1, p2, p3, p4, p5, p6);
    }
    void print() {
        //Tester::printArgs(p0,p1,p2,p3,p4,p5,p6);
    }
};

int main() {
    return Tester::runTests<SettingShield>(
               getTestCases<input, Tester::output<long long>>(), disabledTest,
               1000, 1460475148, CASE_TIME_OUT, Tester::COMPACT_REPORT
           );
}
// CUT end
