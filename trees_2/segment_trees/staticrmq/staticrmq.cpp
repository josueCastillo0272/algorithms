#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define eat cin
#define big long long
#define endl "\n"


int N;
int Q;
int seq[500005];
struct RMQ {
    RMQ *left;
    RMQ *right;
    int lb;
    int rb;
    int mid;
    int val;
    RMQ(int l, int r) {
        this->mid = (l + (r-l)/2);
        this->lb = l;
        this->rb = r;

        if (lb == rb) {
            this->val = seq[lb]; // a_{lb}
        } else {
            left = new RMQ(l,mid);
            right = new RMQ(mid+1, r);
            this->val = min(left->val, right->val);
        }
    }
    int get(int l,int r) {
        if ((l <= lb) && (r >= rb)) {
            return this->val;
        } else if (l > rb  || lb > r) {
            return 1e9;
        }
        int left_min = left->get(l,r);
        int right_min = right->get(l,r);
        return min(left_min, right_min);

    }
};


int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);
    eat >> N;
    eat >> Q;

    for (int i = 0; i < N; i++) {
        int ai;
        eat >> ai;
        seq[i] = ai;
    }
    struct RMQ rmq(0,N-1);
    for (int i = 0; i < Q; i++) {
        int l, r;
        eat >> l >> r;
        cout << rmq.get(l,r-1) << endl;
    }


}