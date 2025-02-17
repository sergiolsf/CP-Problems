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

void solve() {
    int n;
    cin >> n;
    vi a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi b;

    bool positivo = false;
    if (a[0] > 0) positivo = true;
    int sum = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > 0 && positivo) sum += a[i];
        else if (a[i] < 0 && positivo) {
            b.pb(sum);
            sum = a[i];
            positivo = false;
        }
        else if (a[i] < 0 && !positivo) sum += a[i];
        else if (a[i] > 0 && !positivo) {
            b.pb(sum);
            sum = a[i];
            positivo = true;
        }
    }
    b.pb(sum);

    int maior = 0;
    int j = 0;
    int k = b.size()-1;
    if (b[j] > 0) {
        maior = b[j];
        j++;
    }

    if (b[k] < 0) {
        maior += -b[k];
        k--;
    }

    int sumNeg = 0;
    bool N = true;
    int sumPos = 0;
    int maiorSum = 0;

    for (int i = j; i <= k; i++) {
        if (N) sumNeg += b[i];
        N = !N;
    }

    maiorSum = -sumNeg;
    N = true;

    for (int i = j; i <= k; i++) {
        if (N) sumNeg -= b[i];
        else {
            sumPos += b[i];
        }
        maiorSum = max(maiorSum, sumPos-sumNeg);
        N = !N;
    }

    cout << maior+maiorSum << endl;

}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}