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
    int N;
    cin >> N;
    vi P(N+1);
    vi Q(N+1);
    vi D(N+1);
    for (int i = 1; i <= N; i++) cin >> P[i];
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        Q[i] = x;
        D[x] = i;
    }

    for (int i = 1; i <= N; i++) {
        int a = D[i]; // pessoa que ta usando o i-esimo bib
        int b = P[a]; // pessoa que ela ta olhando
        cout << Q[b] << " ";
    }

    cout << endl;


  
    return 0;
}