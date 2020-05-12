
// </> : towhid1zaman

#include "bits/stdc++.h"
//for pbds
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
//template <typename T>using ordered_set =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define fill(a,b) memset(a, b, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
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
const int maxn = 2000100;
int main(){
        _

        ordered_set os;

        /// insert element
        os.insert(5);
        os.insert(6);
        os.insert(7);
        os.insert(8);
        os.insert(9);
        os.insert(10);
        os.insert(11);
        os.insert(12);
        os.insert(13);
        os.insert(14);

        /// delete a given number from the list
        //os.erase(5);

        ///check if the list empty or not
        cout<<((os.empty()) ? "YES" : "NO")<<endl;
        /// or
        cout<<((os.size()==0) ? "YES" : "NO")<<endl;

        /// clear or delete all elements
        //os.clear();

        /// How many Distinct number in the list
        cout<<os.size()<<endl;

        ///smallest number in the list
        cout<<*os.begin()<<endl; ///less<int>
        //cout<<*os.rbegin()<<endl; ///greater<int>

        ///greatest number in the list
        cout<<*os.begin()<<endl; ///greater<int>
        //or
            auto pos = os.end(); pos--; cout<<*pos<<endl;
        //cout<<*os.rbegin()<<endl; ///less<int>

        /// find a given number or say it is not found
        if(os.find(5)==os.end())cout<<"NO Found"<<endl;
        else{
            cout<<"its here "<<endl;
            auto pos = os.find(5);
            cout<<*pos<<endl;
        }

        cout<<"------------------------------"<<endl;
        ///How many number are smaller than a given number
        cout<<os.order_of_key(7)<<endl; // 2

        ///How many numbers are smaller than or equal to a given number
        int cnt = os.order_of_key(7);
        if(os.find(7)!=os.end())cnt++;
        cout<<cnt<<endl;

        /*
            or if given number is 7 we can increase it by 1, 7+1 = 8
            and we cant find
            int cnt = os.order_of_key(8) /// return <=7;
        */

        cout<<"----------------------------------"<<endl;

        ///How many Numbers are greater than a given number

        //from total number subtract less than or equal number
         cnt = os.order_of_key(7);
        if(os.find(7)!=os.end())cnt++;
        cout<<os.size() - cnt<<endl; /// return total greater value

        /// How many numbers are greater than or equal to given number

        cout<<os.size() - os.order_of_key(7)<<endl;

        cout<<"-----------------------------------------"<<endl;

        /// if the list is sorted in a ascending order what is the k'th number in the list
        /*
            let given numbers 3,5,7,8,3,6,1
            this will be,
            1,3,5,6,7,8

            if the given position is 2
            then , simply os.find_by_order(2); // return 5;

        */
        cout<<*os.find_by_order(1)<<endl;

        ///if the given number are sorted in descending order , what is th kth numbe

        //if we use greater<int>
        cout<<*os.find_by_order(1)<<endl;

        //else
        //cout<<*os.find_by_order(os.size()-1-k)<<endl;

        /// delete the kth smallest number
        os.erase(*os.find_by_order(1));

        /// delete the kth greatest number
      // os.erase(*os.find_by_order(os.size()-1-k));

        ///delete the smallest number afrom the list
        os.erase(os.begin());
        /// delete the greaset number from the list
        os.erase(os.rbegin());

        /// print all number in ascending order

        for(auto it = os.begin(); it!=os.end(); it++){
            cout<<*it<<' ';
        }cout<<endl;

        /// print all number in descending order

        for(auto it = os.rbegin(); it!=os.rend(); it++){
            cout<<*it<<' ';
        }cout<<endl;

        /// smallest number , which is greater or equal to given number
        // if the numbers are 2,3,4,5,6,7,8 return 5, if 5 not present it will return 6
        cout<<*os.lower_bound(10)<<endl;

        ///smallest number , which is greater than to given number (exact >)
        cout<<*os.upper_bound(11)<<endl;
return 0;
}

/*
    why we use orderset instead of set

    because of order_by_key() and find_by_order(), they are not included in set

    each operation O(logn)



*/
