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

void solve()
{
    ll n,e; cin>>n>>e;

    v in(n+1,0), out(n+1,0);

    v a[n];

    fr(i,0,e)
    {
        ll x,y;
        cin>>x>>y;
        in[y]+=1;
        out[x]+=1;
    }    

    fr(i,1,n+1)
    {
        if(in[i]==n-1 && out[i]==0){ cout<<i; return;}
    }
    cout<<"-1";
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

