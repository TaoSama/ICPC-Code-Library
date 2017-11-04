#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class TriangleFree {
    public:
    long long count(int n, vector<int> x, vector<int> y) {
        return 0;
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 1.5;

bool disabledTest(int x ){ return x < 0;}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 4, {0,1,2,3}, {1,2,0,2} }, {14LL} },
    { { 5, {0,0,0,0,1,1,1,2,2,3}, {1,2,3,4,2,3,4,3,4,4} }, {16LL} },
    { { 6, {0,0,1,1,1,3,1,2,2,4}, {1,2,2,3,4,4,5,4,5,5} }, {40LL} },
    { { 60, {10,20,30}, {20,30,10} }, {1008806316530991104LL} },
    { { 60, {0,0,1,0,0,3,0,0,5,0,0,7,0,0,9,0,0,11,0,0,13,0,0,15,0,0,17,0,0,19,0,0,21,0,0,23,0,0,25,0,0,27,0,0,29,5,2,23,5,20,27,26,22,19,18,13,15,12,7,9}, {1,2,2,3,4,4,5,6,6,7,8,8,9,10,10,11,12,12,13,14,14,15,16,16,17,18,18,19,20,20,21,22,22,23,24,24,25,26,26,27,28,28,29,30,30,1,12,27,22,1,14,5,27,27,15,15,29,7,6,3} }, {578333426763956224LL} },
    // Your custom test goes here:
    //{ { , {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    #define DISABLE_COLORS
    
    #include "tester.cpp"
    struct input {
        int p0;vector<int> p1;vector<int> p2;

        long long run(TriangleFree* x) {
            return x->count(p0,p1,p2);
        }
        void print() {
            //Tester::printArgs(p0,p1,p2);
        }
    };

    int main() {
        return Tester::runTests<TriangleFree>(
            getTestCases<input, Tester::output<long long>>(), disabledTest,
            1000, 1466874692, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
