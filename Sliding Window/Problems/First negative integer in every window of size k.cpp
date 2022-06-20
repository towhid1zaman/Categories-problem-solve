//First negative integer in every window of size k 
vector<long long> printFirstNegativeInteger(
    long long int A[], long long int N, long long int K) {
                                                 
       vector<long long> ans;
       queue<int>Q;
       int windowStart = 0;
       for(int windowEnd = 0; windowEnd < N; windowEnd++){
            if(A[windowEnd] < 0){
                   Q.push(A[windowEnd]);
            }
            if(windowEnd - windowStart + 1 == K){
               if(!Q.empty()){
                   ans.push_back(Q.front());
                   if(Q.front() == A[windowStart]){
                       Q.pop();
                   }
               }
               else{
                   ans.push_back(0);
               }
               windowStart++;
            }
       }
       return ans;
 }
