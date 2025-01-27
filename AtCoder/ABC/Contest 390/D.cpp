#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int N;
vi a;
set<int> st;
int tot = 0;
vi cont(1e7);
int l = 0;

void ans (int k, int t) {
    //cout << k << endl;
    if (cont[k] >= 1) return;
    cont[k]++;
    
    if (k == ((1<<N)-1)) return;
    for (int i = 0; i < (1 << (N+1)); i++) {
        int p = k;
        int sum = 0;
        int prov = t;
        for (int j = 0; j < N; j++) {
            if ((i & (1 << j)) && !((1 << j) & k)) {
                prov ^= a[j+1];
                sum += a[j+1];
                p |= (1 << (j));
            }
        }
        prov ^= sum;
        st.insert(prov);
        ans (p, prov);
    }
}

signed main() {
    fastio();

    cin >> N;
    a.resize(N+1);

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        tot ^= a[i];
    }

    st.insert(tot);

    ans(0, tot);

    cout << st.size() << endl;    
    
    return 0;
}