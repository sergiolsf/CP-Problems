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

vi apllyPerm(vi seq, vi perm) {
    vi newSeq(seq.size());
    for (int i = 0; i < seq.size(); i++) {
        newSeq[i] = seq[perm[i]];
    }
    return newSeq;
}

vi permute(vi seq, vi perm, int k) {
    while (k) {
        if (k&1) seq = apllyPerm(seq, perm);
        perm = apllyPerm(perm, perm);
        k >>= 1;
    }
    return seq;
}

signed main () {
    fastio();
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vi perm, seq, ans;
    for (int i = 0; i < n; i++) {
        seq.push_back((int) (s[i]-'a'));
    }
    for (int i = 0; i < 2*n; i+=2) {
        perm.push_back(i%n);
    }

    ans = permute(seq, perm, k);


    for (auto e: ans) {
        cout << (char) ('a'+e);
    }
    cout << endl;
    
    return 0;
}