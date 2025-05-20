#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

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

multiset<int> ms;
    ost st;

signed main() {
    fastio();
    int x, n; cin >> x >> n;

    st.insert(0);
    st.insert(x);
    ms.insert(x);

    while (n--) {
        int p; cin >> p;
        
        int a = st.order_of_key(p);
        int b = *st.find_by_order(a);
        int c = *st.find_by_order(a-1);
        
        int d = b-c;

        auto it = ms.find(d);
        if (it != ms.end()) ms.erase(it);
    
        ms.insert(p-c);
        ms.insert(b-p);
        st.insert(p);

        cout << *ms.rbegin() << " ";
    }

    cout << endl;  
    return 0;
}