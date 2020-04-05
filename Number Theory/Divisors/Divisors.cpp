// Given a number , you have to find the divisors of the number .
// Also find the number of divisors and summation of those divisors of the number .

// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back
#define inf (1<<29)

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 1000100;

vll prime,divisor;
char status[maxn];

ll power(ll x, ll n){
    ll res = 1;
    while(n>0){
        if(n&1){
            res = (res*x);
        }
        n = n>>1;
        x = (x*x);
    }
    return res;
}

void sieve(){
    prime.push_back(2);
    for(ll i = 3; i<=maxn; i+=2){
        if(status[i]==NULL){
            prime.push_back(i);
            for(ll j = i*i; j<=maxn;j+=i*2){
                status[j] = '1';
            }
        }
    }
}

void finding_Divisors(ll number){
    for(ll i = 1; i*i<=number; i++){
        if(number%i==0)divisor.push_back(i);
        if(number%i==0 and (number/i)!=i)divisor.push_back(number/i);
    }
    sort(divisor.begin(),divisor.end());
}

void number_Of_Divisors(ll number,ll &total,ll &even,ll &odd)
{
    total = 1 ; odd = 1 ;
    for(ll i = 0 ;i<prime.size();i++)
    {
        if(prime[i]*prime[i]>number) break;
        if(number%prime[i]==0)
        {
            ll cnt = 0 ;
            while(number%prime[i]==0)
            {
                number/=prime[i];
                cnt++;
            }
            total*=(cnt+1);
            if(prime[i]!=2) odd*=(cnt+1);
        }
    }
    if(number!=1) total*=2 , odd*=2 ;
    even=total-odd;
}

ll summations_of_divisors(ll number){
    ll ans = 1;
    for(ll i = 0; i<prime.size(); i++){
        if(prime[i]*prime[i]>number)break;
        if(number%prime[i]==0){
            ll cnt = 0;
            while(number%prime[i]==0){
                number/=prime[i];
                cnt++;
            }
            ans*=(power(prime[i],cnt+1)-1)/(prime[i]-1);
        }
    }
    if(number!=1)ans*=(number+1); //Avoiding Overflow
    return ans;
}

int main(){
        _ios;

        sieve();

        ll number; cin >> number;

        finding_Divisors(number);

        cout<<"The Divisors of  "<<number<<" are = ";
        for(auto x: divisor){
            cout<<x<<' ';
        }cout<<endl;

        ll total , odd , even ;
        number_Of_Divisors(number,total,even,odd);

        cout<<"Total Number Of divisors = "<<total<<endl;
        cout<<"Total Even Number Of divisors = "<<even<<endl;
        cout<<"Total Odd Number Of divisors = "<<odd<<endl;

        cout<<"Summation of divisors = "<<summations_of_divisors(number)<<endl;

        return 0;


return 0;
}
/*
575
The divisors of 575 are = 1 5 23 25 115 575
Number of divisors = 6
Number of Even divisors = 0
Number of Odd divisors = 6
Summation of divisors = 744

12
The divisors of 12 are = 1 2 3 4 6 12
Number of divisors = 6
Number of Even divisors = 4
Number of Odd divisors = 2
Summation of divisors = 28
*/





