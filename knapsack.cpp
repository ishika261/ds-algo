#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ft first
#define sd second
 
#define v vector<ll>
#define vecv vector<v>
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
 
#define err() cout<<"=================="<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl;
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl;

#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl;

#define fr(i, a, b) for(i=a; i<b; i++)
#define rf(i, a, b) for(i=a; i>=b; i--)
const int N = 1e6 + 1;
ll i, j;

ll knap( v wt, v val, ll w, ll n)
{

    //err2(w,n);
    if(n==0 || w==0) return 0;

    if(wt[n]>w) 
        return knap (wt,val,w,n-1);

    else 
        return max(knap(wt,val,w,n-1), val[n]+ knap(wt,val,w-wt[n],n-1));
}

void solve()
{
    ll n,w; cin>>n>>w;
    v wt(n), val(n);

    fr(i,0,n)cin>>wt[i];
    fr(i,0,n)cin>>val[i];

    ll ans =knap(wt,val,w,n-1);

    cout<<ans;
    

    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
    #endif
    ll t=1; //cin>>t;
    while(t--) solve();
    return 0;
}