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
    ll n; cin>>n;
    v a(n);
    ll sum=0;
    fr(i,0,n)
    { 
        cin>>a[i];
        sum+=a[i];
    }

    err1(sum);

    if(sum%2==0)
    {
        bool check[sum+1];
        memset(check,0,sizeof(check) );

        check[0]=1;
        


        fr(j,0,n)
        {
            v temp;
            err1(j);
            fr(i,0,sum+1)
                if(check[i]==1) temp.push_back(i+a[j]);


            for(auto k:temp)
            {
                check[k]=1;
                err1(k);
            }
        
        }

        if(check[sum/2] ==1) cout<<"YES";
        else cout<<"NO";
    }

    else cout<<"NO";

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