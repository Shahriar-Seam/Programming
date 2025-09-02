#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
typedef long long ll;

ll check_gcd(ll a, ll b){
    if(b == 0)return a;
    return check_gcd(b,a%b);
}
 
void solve(){
    ll n;
    cin>>n;

    vector<ll>v(n);

    for(int i=0;i<n;i++)cin>>v[i];

    sort(v.begin(),v.end());

    vector<ll>v1;

    for(int i=1;i<n;i++)if(v[i] % v[0] == 0)v1.push_back(v[i]);

    for(int i=0;i<v1.size();i++){
        for(int j=i;j<v1.size();j++){
            if(check_gcd(v1[i],v1[j]) == v[0]){
                cout<<"Yes"<<endl;
                return;
            }
        }
    }

    cout<<"No"<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    int t;
    cin>>t;

    while(t--){
        solve();
    }
 
    return 0;
}