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

int n, k;
vi stall;

bool good (int x) {
    int cows = 1;
    int ult = stall[1];

    for (int i = 2; i <= n; i++) {
        if (stall[i] - ult >= x) {
            ult = stall[i];
            cows++;
        }
    }

    return cows >= k;
}

signed main() {
    fastio();
    cin >> n >> k;

    stall.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> stall[i];

    int l = 0; // consigo colocar as vacas com distancia >= l
    int r = 1; // nao consigo colocar todas as vagas com distancia r
    
    while (good(r)) r *= 2;

    while (r-l != 1) {
        int m = (l+r)/2;
        if (good(m)) l = m;
        else r = m;
    }

    cout << l << endl;

    return 0;
}