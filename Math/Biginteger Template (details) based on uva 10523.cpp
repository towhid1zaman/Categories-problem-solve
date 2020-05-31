
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair< int, int > pii;
typedef pair< pii, int > ppi;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) (v).erase(unique(all(v)),(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;
const int maxn = 2000100;


class BigInt {
    private:
        vector<int> digit; /*for storing digit*/
        int sign; /*1:-1?positive:negative*/

    public:
        /*constructors to build Big Integer*/
        BigInt() { /*default*/
            digit.push_back(0); /*initial with 0*/
            sign=1; /*positive number*/
        }

        BigInt(char *n) { /*for string*/
            sign=1; /*initially positive number*/

            if(*n=='-') { /*if first character of string is '-' sign*/
                sign=-1; /*just found negative number...so change the sign*/
                n++; /*go to next character*/
            }

            while(*n=='0') n++; /*go to next character until the character is not zero(0)*/

            if(strlen(n)==0) { /*are you kidding...(input like as 00000000000/-00000000000000000)*/
                digit.push_back(0);
                sign=1;
            } else {
                while(*n) {
                    digit.push_back((*n)-48); /*push every digit*/
                    n++;
                }
            }
        }

        BigInt(int n) { /*for number*/
            sign=1;
            if(n<0) {
                sign=-1;
                n*=-1;
            }

            while(n!=0) {
                digit.push_back(n%10);
                n/=10;
            }

            reverse(digit.begin(),digit.end());
        }

        BigInt(const vector<int> &d,const int s) {
            digit=d;
            sign=s;
        }

        /*methods for caring and sharing of BigInt*/

        /*some methods for helping*/
        BigInt inverSign() {
            sign*=-1;
            return (*this);
        }

        void vectorNormalize(vector<int> &v) {
            int i;
            for(i=0;v[i]==0 && i<v.size();i++);
            v.erase(v.begin(),v.begin()+i);

            if(v.size()==0) v.push_back(0);
        }

        /*comparing operator overloading methods*/
        bool operator < (const BigInt &b) const {
            if(sign!=b.sign) return sign<b.sign; /*ex. -12 and 123*/
            int len1=digit.size(),len2=b.digit.size();

            if(len1==len2) {
                int i;
                if(sign==1) { /*ex. 123 and 124*/
                    for(i=0;i<len1;i++) {
                        if(digit[i]<b.digit[i]) return true;
                    }
                    return false;
                } else { /*ex. -123 and -124*/
                    for(i=0;i<len1;i++) {
                        if(digit[i]<b.digit[i]) return false;
                    }
                    return true;
                }
            }

            return sign==1?(len1<len2):(len1>len2); /*ex. 12 and 123 : -12 and -123*/
        }

        bool operator > (const BigInt &b) const {
            bool flag=(*this)<b;

            return !flag; /*oposite of < operator*/
        }

        bool operator == (const BigInt &b) const {
            if(sign!=b.sign) return false; /*ex. 123 and -123*/
            int len1=digit.size(),len2=b.digit.size();

            if(len1!=len2) return false; /*ex. 123 and 12*/
            int i;

            for(i=0;i<len1;i++) {
                if(digit[i]!=b.digit[i]) return false; /*ex. 123 and 124*/
            }

            return true;
        }

        bool operator >= (const BigInt &b) const {
            return (*this)>b?true:(*this)==b; /*ex. 123>=12*/
        }

        bool operator <= (const BigInt &b) const {
            return (*this)<b?true:(*this)==b;/*ex. -123<=12*/
        }

        /*mathematical operator overloading methods*/
        BigInt operator + (BigInt b) { /*calculating a+b*/
            if(sign!=b.sign) return (*this) - b.inverSign();
            vector<int>temp;
            int len1=digit.size(),len2=b.digit.size();
            int i,j,sum=0;

            for(i=len1-1,j=len2-1;i>=0 || j>=0;i--,j--) { /*ex 123+87=210*/
                sum+=(((i>=0)?digit[i]:0)+((j>=0)?b.digit[j]:0));
                temp.push_back(sum%10);
                sum/=10;
            }
            if(sum) {
                temp.push_back(sum);
            }

            reverse(temp.begin(),temp.end()); /*ex. initially 012...and after reverse 210*/

            return BigInt(temp,sign);
        }

        BigInt operator - (BigInt b) {
            if(sign!=b.sign) return (*this) + b.inverSign(); /*ex. -123-12 or 12-(-123)*/
            bool flag1=true,flag2=true;
            if((*this)<b) flag1=false; /*ex. 123-129 or -123-(-12)*/

            vector<int>temp;
            int len1=digit.size(),len2=b.digit.size();
            int i,j,sub,borrow=0;

            if(flag1==false && sign==1) { /*ex. 123-129*/
                flag2=false;
            } else if(flag1 && sign==-1) flag2=false; /*ex. -12-(-123)*/

            for(i=len1-1,j=len2-1;i>=0 || j>=0;i--,j--) {
                if(flag2) { /*first number is maximum(without sign)*/
                    sub=((i>=0)?digit[i]:0)-((j>=0)?b.digit[j]:0)-borrow;
                } else {
                    sub=((j>=0)?b.digit[j]:0)-((i>=0)?digit[i]:0)-borrow;
                }

                if(sub<0) {
                    sub+=10;
                    borrow=1;
                } else borrow=0;

                temp.push_back(sub);
            }

            reverse(temp.begin(),temp.end());

            vectorNormalize(temp);

            return BigInt(temp,flag1?1:-1);
        }

        BigInt operator * (BigInt b) {
            int len1=digit.size()-1,len2=b.digit.size()-1,len;
            int i,j,k,sum;

            if(len1<len2) return b * (*this);

            vector<int>temp;

            for(i=len2;i>=0;i--) {
                k=len2-i;
                sum=0;
                len=temp.size();
                for(j=len1;j>=0;j--) {
                    sum+=(digit[j]*b.digit[i]);
                    sum+=(k!=0 && k!=len?temp[k]:0);
                    if(k!=0 && k!=len) {
                        temp[k]=sum%10;
                        k++;
                    } else temp.push_back(sum%10);
                    sum/=10;
                }
                if(sum) temp.push_back(sum);
            }

            reverse(temp.begin(),temp.end());
            vectorNormalize(temp);

            return BigInt(temp,temp.size()==1 && temp[0]==0?1:sign*b.sign);
        }

        void viewNumber() const {
            if(sign==-1) printf("-");
            int i,len=digit.size();

            for(i=0;i<len;i++) printf("%d",digit[i]);
        }
};


int main(){
        _
        BigInt p,q;
        int n,a;
        while(cin >> n >> a){
            if(a==0){
                printf("0\n");
            }
            else{
                p = 0, q = a;
                BigInt temp = a;
                for(int i = 1; i<=n; i++){
                    if(i==1)p =p+q;
                    else{
                        q=q*temp;
                        p  = p+(q*BigInt(i));
                    }
                }
                p.viewNumber();
                printf("\n");
            }
        }


return 0;
}

