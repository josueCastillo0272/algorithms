#include <iostream>
#include <stack>
#include <vector>
#include <tuple>
#include <algorithm>


using namespace std;
int n;
int sz[200000];
long long dist[200000];
long long ans[200000];
vector<int> adj[200000];

void dfs_initial(int root) {
    stack<tuple<int,int,int>> st;
    st.push(make_tuple(root,-1,0));
    while (!st.empty()) {
        tuple<int,int,int> head = st.top();
        st.pop();
        auto [node, par, status] = head;
        if (status == 0) { // not yet traversed
            st.push(make_tuple(node, par, 1));
            for (int c: adj[node]) {
                if (c == par) continue;
                st.push(make_tuple(c, node, 0));
            }
        } else { // finished traversing
            for (int c: adj[node]) {
                if (c == par) continue;
                sz[node] += sz[c];
                dist[node] += sz[c] + dist[c];
            }
        }
    }
}

void reroot(int orig, int node) {
    if ((orig == -1) || (node == -1)) {
        return;
    }

    sz[orig] -= sz[node];
    dist[orig] -= sz[node] + dist[node];

    sz[node] += sz[orig];
    dist[node] += sz[orig] + dist[orig];
}

void dfs_reroot(int root) {
    stack<tuple<int,int,int>> st;
    st.push(make_tuple(root,-1,0));
    while (!st.empty()) {
        tuple<int,int,int> head = st.top();
        st.pop();
        auto [node, par, status] = head;
        if (status == 0) { // not yet traversed
            reroot(par, node);
            ans[node] = dist[node];

            st.push(make_tuple(node, par, 1));
            for (int c: adj[node]) {
                if (c == par) continue;
                st.push(make_tuple(c, node, 0));
            }
        } else { // finished traversing
            reroot(node, par);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int edge = 0; edge < n-1; edge++) {
        int u;
        int v;
        cin >> u >> v; // edge (u,v)
        u--;
        v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    fill(sz, sz + n, 1);
    fill(dist, dist + n, 0);

    dfs_initial(0);             // fill sizes 

    // for (int i = 0; i < n; i++) {
    //     cout << dist[i] << " ";
    // }

    dfs_reroot(0);              // reroot

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}