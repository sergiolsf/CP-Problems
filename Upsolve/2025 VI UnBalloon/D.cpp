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

signed main() {
    fastio();
    int rl, hl, rc, hc; cin >> rl >> hl >> rc >> hc;

    int A = 3*rl*rl*hl;
    int B = rc*rc*(hc+2*rc);
    if (A > B) cout << "Injusto\n";
    else cout << "Justo\n";
  
    return 0;
}