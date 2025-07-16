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
            backtrackingaa(pos-1, qnt-1, (qnt-1)/2, v);
        }
        for (int i = 0; i <= 9; i++) {
            if (i == 0 && pos == qnt) continue;
            v.push_back(i);
            backtrackingaa(pos-1, qnt, meio, v);
            v.pop_back();
        }
    } else {
        vi vv = v;
        int q = qnt-meio;
        if (qnt%2 == 0) for (int e = q; e >= 0; e--) vv.push_back(v[e]);
        else for (int e = q-1; e >= 0; e--) vv.push_back(v[e]);

        int n = 0;
        for (auto e: vv) {
            n *= 10;
            n += e;
        }
        num.push_back(n);
        return;
    }
}

bool pal(int n, int b) {
    vi v;
    while (n) {
        v.push_back(n%b);
        n /= b;
    }
    int i = 0, j = v.size()-1;
    while (v[i] == 0) i++;
    while (i < j) {
        if (v[i] != v[j]) return false;
        i++; j--;
    }
    return true;
}

signed main() {
    fastio();
    int A, N; cin >> A >> N;
    vi v = {};
    backtrackingaa(10, 10, 5, v);
    
    int ans = 0;
    for (auto e: num) {
        if (e > N) continue;
        if (pal(e, A)) ans += e;
    }
    cout << ans << endl;
  
    return 0;
}