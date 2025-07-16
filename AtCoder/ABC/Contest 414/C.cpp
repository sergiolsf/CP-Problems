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

vi num;

void backtrackingaa(int pos, int qnt, int meio, vi v) {
    if (qnt == 0) return;
    if (pos >= meio) {
        if (pos == qnt) {
            backtrackingaa(pos-1, qnt-1, (qnt+2)/2, v);
        }
        for (int i = 0; i <= 9; i++) {
            if (i == 0 && pos == qnt) continue;
            vi vv = v;
            vv.push_back(i);
            backtrackingaa(pos-1, qnt, meio, vv);
        }
    } else {
        vi vv = v;
        for (int e = qnt-pos; e >= 0; e--) vv.push_back(v[e]);

        int n = 0;
        for (auto e: vv) {
            n *= 10;
            n += e;
        }

        cout << n;
        num.push_back(n);
        return;
    }
}

signed main() {
    fastio();
    int k; cin >> k;
    vi v;
    backtrackingaa(13, 13, 7, v);
    for (int i = 0; i < 30; i++) cout << num[i] << endl;
  
    return 0;
}