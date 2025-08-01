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

const int MAX_N = 100'005;

int r[MAX_N];
int p[MAX_N];
int sum[MAX_N];

int get (int a) {
    return p[a] = (p[a] == a ? a : get(p[a]));
}

int uniao (int a, int b) {
    a = get(a); b = get(b);
    if (r[a] == r[b]) r[a]++;
    if (r[a] > r[b]) {
        p[b] = a;
        sum[a] += sum[b];
        return sum[a];
    } else {
        p[a] = b;
        sum[b] += sum[a];
        return sum[b];
    }
}

void init() {
    for (int i = 0; i < MAX_N; i++) {
        p[i] = i;
        r[i] = 0;
        sum[i] = 1;
    }
}

signed main() {
    fastio();
    init();
    int n, m; cin >> n >> m;
    int componentes = n, maior = 1;
    while (m--) {
        int a, b; cin >> a >> b;

        if (get(a) != get(b)) {
            componentes--;
            maior = max(maior, uniao(a, b));
        }
        cout << componentes << " " << maior << endl;
    }

  
    return 0;
}