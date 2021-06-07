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

bool fun(int i , int j)
{
    if(abs(i)==abs(j) && i>j) return 0;
    if(abs(i)== abs(j)&& i<j) return 1; 
    if(abs(i)==abs(j) && i==j) return 1;
    if(abs(i)<abs(j)) return 1;
    else return 0;
}

bool hotel(vector<int> &arr, vector<int> &dep, int K) {
    
    int n=arr.size(); 
    // vector <int> r;
    
    // for(i=0;i<n;i++)
    // {
    //     r.push_back(arr[i]);
    //     r.push_back(-dep[i]);
    // }

    vector <pair<int,int> > p;

    for(i=0;i<n;i++)
    {
        p.push_back({arr[i],1});
        p.push_back({ dep[i],0});
    }

    sort(all(p));

    int c=0;
    for(auto [x,y]:p)
    {
        if(y==1)c++;
        else c--;

        if(c<0||c>K)return 0;
    }
    
    // sort(r.begin(),r.end(),fun);
    
    // fr(i,0,r.size()) cout<<r[i]<<" ";

    // cout<<endl;
    // int c=0;
    
    // for(i=0;i<r.size();i++)
    // {
    //     if(r[i]>=0)c++;
    //     else c--;
        
    //     err2(c,r[i]);
    //     if(c<0 || c>K) return 0;
    // }
    
    return 1;
}
void solve()
{b
    //cout<<__cplusplus;
    int n,k; cin>>n>>k;
    
    //err();
    //cout<<"hello";
    vector<int> arr(n), dep(n);

    fr(i,0,n) cin>>arr[i];
    fr(i,0,n) cin>>dep[i];

    bool ans = hotel(arr,dep,k);

    err1(ans);
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