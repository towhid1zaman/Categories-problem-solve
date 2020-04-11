#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using pii = std::pair<int, int>;
const int NMAX = (int)1e9;
const int SNMAX = (int)sqrt(NMAX) + 1;
std::bitset<NMAX + 1> bits;
int main() {
	bits[0] = bits[1] = 1;
	std::vector<pii> smallPrimes;
	for (int i = 2; i <= SNMAX; ++i) {
		if (!bits[i]) {
			smallPrimes.push_back({i, i * i});
			for (int j = i * i; j <= SNMAX; j += i) {
				bits[j] = 1;
			}
		}
	}
	const int blockSize = 1 << 18;
	for (int from = 0; from <= NMAX; from += blockSize) {
		int to = std::min(from + blockSize - 1, NMAX);
		for (pii& p : smallPrimes) {
			for (; p.second <= to; p.second += p.first) bits[p.second] = 1;
		}
	}
	bits.flip();
	//iterate over primes
	int64_t sum(0);
	int cnt(0);
	for (int p = bits._Find_first(); p < bits.size(); p = bits._Find_next(p)) {
		sum += p;
		cnt++;
	}
    assert(bits.count() == cnt);
	std::cout << "sum = " << sum << std::endl;
	std::cout << "cnt = " << cnt << std::endl;
	return 0;
}
