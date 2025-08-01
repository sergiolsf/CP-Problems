#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int block_size = 555;
int Q, n;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        if (l / block_size != other.l / block_size) return l / block_size < other.l / block_size;
        return r < other.r;
    }
};


const int MAX_N = 200'005;

int v[MAX_N];
pii a[MAX_N];
Query queries[MAX_N];
int answers[MAX_N];
int freq[MAX_N];
int f = 0;


void remove(int idx) {
    freq[v[idx]]--;
    if (!freq[v[idx]]) f--;
} 

void add(int idx) {
    if (!freq[v[idx]]) f++;
    freq[v[idx]]++;
}

int get_answer() {
    return f;
}

void mo_s_algorithm() {
    int cur_l = 1;
    int cur_r = 0;

    for (int i = 0; i < Q; i++) {
        Query q = queries[i];
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = f;
    }

    for (int i = 0; i < Q; i++) {
        cout << answers[i] << endl;
    }
}

signed main() {
    fastio();
    cin >> n >> Q;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a, a+n);

    int num = 0, ant = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].first != ant) num++;
        v[a[i].second] = num;
        ant = a[i].first;
    }

    for (int i = 0; i < Q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    sort(queries, queries+Q);

    mo_s_algorithm();

    return 0;
}