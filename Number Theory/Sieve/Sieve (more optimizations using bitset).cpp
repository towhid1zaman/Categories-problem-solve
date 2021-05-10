/*
 *Optimization
 *1.Use Bitset
 *2.Consider only Odd number
 *3.Check Range Carefully
 */

#define M 100000000
std::vector<int>primes;
int marked[(M>>6) + 2];

#define on(x) (marked[x>>6] & ( 1<<((x>>1)&31 )))
#define mark(x) (marked[x>>6] |= ( 1<<( (x>>1)&31 )))

bool isPrime(int n){
  if(n%2==0 or n<2) return false;
  return !on(n);
}

void sieve(int n){
  for(int i = 3; i*i < n; i+=2){
    if(!on(i)){
      for(int j = i*i; j<=n; j += i+i){
        mark(j);
      }
    }
  }

  primes.push_back(2);
  for(int i = 3; i<=n; i+=2){
    if(isPrime(i)){
      primes.push_back(i);
    }
  }

}
