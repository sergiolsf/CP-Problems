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

int B, S, C;
int nb, ns, nc;
int pb, ps, pc;
int r;

bool good (int x) {
    int sum = 0;
    if (B > 0 && B*x > nb) sum += (B*x - nb)*pb;
    if (S > 0 && S*x > ns) sum += (S*x - ns)*ps;
    if (C > 0 && C*x > nc) sum += (C*x - nc)*pc;

    return sum <= r;
}

signed main() {
    fastio();
    string s;
    cin >> s;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'B') B++;
        if (s[i] == 'S') S++;
        if (s[i] == 'C') C++;
    }

    int l = 0; // consigo formar l sanduiches
    int r = 1; // nao consigo formar r sanduiches

    while(good(r)) r *= 2;

    while (r-l != 1) {
        int m = (r+l)/2;
        if (good(m)) l = m;
        else r = m;
    }

    cout << l << endl;

    return 0;
}