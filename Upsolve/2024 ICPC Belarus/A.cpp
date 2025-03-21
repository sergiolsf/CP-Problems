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

vi Sol;
int quantAns = 1'000'000;

signed main() {
    fastio();
    int n, k; cin >> n >> k;
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= k+1; i++) {
        int id1 = 2*i-1;
        int id2 = 2*i;
        int r = a[id2]-a[id1];
        int atual = a[id2]+r;
        int quant = 0; vi ans;

        for (int j = id2+1; j <= n; j++) {
            if (atual != a[j]) {
                quant++;
                ans.push_back(j);
                if (quant > k) break;
            } else {
                atual += r;
            }
        }

        if (quant > k) continue;

        atual = a[id1]-r;
        for (int j = id1-1; j > 0; j--) {
            if (atual != a[j]) {
                quant++;
                ans.push_back(j);
                if (quant > k) break;
            } else {
                atual -= r;
            }
        }
        if (quant > k) continue;

        if (quantAns > quant) {
            quantAns = quant;
            Sol = ans;
        }
    }

    if (quantAns <= k) {
        cout << quantAns << endl;
        for (int j = 0; j < quantAns; j++) {
            cout << Sol[j] << ((j == (quantAns-1)) ? "\n":" ");
        }
    } else {
        cout << -1 << endl; 
    }

    return 0;
}