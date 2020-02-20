#include <vector>
#include <cstdio>
#include <iostream>

typedef long long ll;

using namespace std;

struct Segment_Tree
{
    vector <ll> Tree;
    ll n;
    void Make_Empty (ll _n = 0){
        n = _n*4+1;
        for (ll i = 0; i < n;++i) Tree.push_back(0); 
   }
   void Update (ll id, ll l, ll r, ll u, ll v, ll k){
       if (r < u || v < l) return;
       if (l == r){
           Tree[id] += k;
           return;
       }
       ll mid = (l + r) / 2;
       Update (id * 2, l, mid, u, v, k);
       Update (id * 2 + 1, mid + 1, r, u, v, k);
       Tree [id] = max (Tree [id*2], Tree[id*2+1]);
   }

   ll Get (ll id, ll l, ll r, ll u, ll v){
       if (r < u || v < l) return 0;
       if (l <= u && v <= r){
           return Tree[id];
       }
       ll mid = (l + r) / 2;
       return max (Get(id * 2, l, mid, u, v), Get (id * 2 + 1, mid + 1, r, u, v));
   }
};

Segment_Tree ST;
ll n, m;

int main () {
    cin >> n >> m;
    ST.Make_Empty(n);
    for (ll i = 0; i < m; ++i){
        ll l, r, k;
        cin >> l >> r >> k;
        ST.Update(1,1,n,l,r,k);
    }
    ll ans = ST.Get (1,1,n,1,n);
    cout << ans;
    return 0;
}