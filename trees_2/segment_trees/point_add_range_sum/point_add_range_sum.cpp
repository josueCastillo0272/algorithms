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
big N, Q, seq[500005];

struct RMS{
    RMS* left;
    RMS* right;
    big sum;
    int l,r,lb,rb, mid;

    RMS(int l, int r) {
        mid = (l + (r-l)/2);
        lb = l;
        rb = r;
        if (lb == rb) {
            sum = seq[lb]; 
        } else {
            left = new RMS(l,mid);
            right = new RMS(mid+1,r);
            sum = left->sum + right->sum; // add left and right subchild
        }
    }

    big get(int l, int r) {
        if ((l <= lb) && (r >= rb)) {
            return sum;
        } else if (rb < l || r < lb) {
            return 0;
        }
        return left->get(l,r) + right->get(l,r);
    }
    void update(int p) {
        if (lb == rb) {
            sum = seq[p];
            return;
        } else if (p <= mid){
            left->update(p);
        } else {
            right->update(p);
        }
        sum = left->sum + right->sum;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);
    eat >> N >> Q;

    for (int i = 0; i < N; i++) {
        big seqi;
        eat >> seqi;
        seq[i] = seqi;
    }

    struct RMS rms(0,N-1);

    for (int i = 0; i < Q; i++) {
        int q_type;
        eat >> q_type;
        if (q_type == 1) {
            big l, r;
            eat >> l >> r;
            cout << rms.get(l,r-1) << endl;
        } else {
            big p,x;
            eat >> p >> x;
            seq[p] += x;
            rms.update(p);
        }
    }

    
}