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

const int MAX_N = 300'010;

vi p(MAX_N), r(MAX_N, 0);

int get(int a) {
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void uniao(int a, int b) {
    a = get(a); b = get(b);
    r[a]++;
    p[b] = a;
}

signed main() {
    fastio();
    iota(all(p), 0);
    int n, q; cin >> n >> q;
    vi cap(n+1), atual(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> cap[i];
    }

    vi NG(n+1, -1);
    stack<pii> dq;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.top().first < cap[i]) {
            NG[dq.top().second] = i;
            dq.pop();
        }
        dq.push({cap[i], i});
    }

    while (q--) {
        char t; cin >> t;
        int l; cin >> l;
        if (t == '+') {
            int x; cin >> x;

            int a = get(l);
            atual[a] += x;
            int d = atual[a] - cap[a];
            while (d > 0) {
                atual[a] = cap[a];
                if (NG[a] == -1) break;
                uniao(NG[a], a);
                a = get(NG[a]);
                atual[a] += d;
                d = atual[a] - cap[a];
            }

        } else {
            cout << atual[l] << endl;
        }
    }
  
    return 0;
}