#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define eat cin
#define moo cout
#define big long long

int n;
int m;

vector<int> s_list; 
vector<pair<int,int>> edges;
vector<int> adj[200005];

int par[200005];
big sz[200005];
bool active_in_graph[200005]; 

big total_pairs = 0;

int root(int x) {
    if (par[x] == x) return x;
    par[x] = root(par[x]);
    return par[x];
}

void join(int x, int y) {
    int r_x = root(x);
    int r_y = root(y);

    if (r_x == r_y) return;
    
    if (sz[r_x] < sz[r_y]) {
        swap(r_x, r_y);
    }
    
    total_pairs += sz[r_x] * sz[r_y];

    sz[r_x] += sz[r_y];
    par[r_y] = r_x;
}

void create_initial_DSU() {
    for (auto edge: edges) {
        int u = edge.first;
        int v = edge.second;
        
        if (s_list[u-1] == 1 && s_list[v-1] == 1) { // if s_u and s_v = 1 -> both reach each others neighbors
            join(u, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);

    eat >> n >> m;

    string str;
    eat >> str;
    for (int i = 0; i < n; i++) {
        int val = str[i] - '0'; // strat 1: -'0' to convert to int
        s_list.push_back(val);
        if (val == 1) active_in_graph[i+1] = true; // mark all "active" initially as s_t = 1
        else active_in_graph[i+1] = false;
    }
    
    for (int i = 0; i <= n; i++) {
        par[i] = i;
        sz[i] = 0; 
    }

    for (int i = 0; i < m; i++) {
        int u, v; 
        eat >> u >> v;
        edges.push_back({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // create initial forest of trees
    create_initial_DSU();

    vector<big> results; 

    for (int t = n; t > 0; t--) {
        if (s_list[t-1] == 0) { // inactive
            active_in_graph[t] = true;
            for (auto v: adj[t]) { // for each neighbor, if active, then can reach it
                if (active_in_graph[v]) join(t, v);
            }
        } 
        
        int r = root(t);
        total_pairs += sz[r]; //combinatorally, just did (n-1)(n-2)/2, now have to add n
        sz[r]++;

        results.push_back(total_pairs);
    }
    reverse(results.begin(), results.end());
    for(big val : results) {
        moo << val << "\n";
    }

    return 0;
}