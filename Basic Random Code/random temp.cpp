int longestIncreasingSubsequenceLenghtDP(int a[],int n){
    int dp[n],ans=0;
    for(int k = 0;k<n;k++){
        dp[k] = 1;
        for(int i = 0;i<k;i++){
            if(a[i] <= a[k]){
                dp[k] = max(dp[k],dp[i] + 1);
                ans = max(dp[k],ans);
            }
        }
    }
    return ans;
 }
int result[1000] = {0};
int factDP(int n) 
{
   if (n >= 0) {
      result[0] = 1;
      for (int i = 1; i <= n; ++i) {
         result[i] = i * result[i - 1];
      }
      return result[n];
   }
}
bool isPrime(ll n)
{
    if(n<2) return false;
    for(ll x = 2;x*x <=n;x++)
    {
        if(n%x == 0)return false;
    }
    return true;
}
vector<int> primeFactors(int n){
    vector<int> f;
    for(int x = 2;x*x<=n;x++){
        while(n%x==0){
            f.push_back(x);
            n/=x;
        }
    }
    if(n>1)f.push_back(n);
    return f;
}
int binary_Search_Classic(int n, int arr[],int target){
	int l,r,mid;
	l=0;
	r=n-1;
	while(l<=r){
		mid= l+(r-l)/2;
		if(arr[mid] == target){
			return mid;
		}
		if(arr[mid] < target){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return -1;
	
}
vector<int> Two_PointerSumOfTwo(vector<int> arr, int target)
{
	int l = 0, r = arr.size()-1;
	vector<int> ans;
	while(l<r){
		if(arr[l] + arr[r] == target)
		{
			ans.push_back(l);
			ans.push_back(r);
			break;
		}else if(arr[l] + arr[r] > target){
			r--;
		}else{
			l++;;
		}
	}
	return ans;
}
bool isPerfectSquare(long double x) 
{   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
} 
int countDistinctCharsString(string s) {
    unordered_map<char, int> m; 
    for (int i = 0; i <(int)s.length(); i++) { 
        m[s[i]]++; 
    }
    return m.size(); 
}
