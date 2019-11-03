#include <bits/stdc++.h>

#define TAM int(1e6)

using namespace std;

/*
This problem was asked by Alibaba.

Given an even number (greater than 2), return two prime numbers whose sum will be equal to the given number.

A solution will always exist. See Goldbach’s conjecture.

Example:

Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.
*/

/*

EASY

After we generate primes with the Sieve of Eratosthenes, the problem become easy:
Just traverse the array of primes and check if n-primes[i] is prime. That can be checked in constant time.

Complexity: O(N*log(log(N))), where N is the number that we want the number that we want to find the two primes added up to N.
*/

vector<int> primes;

vector<bool> mark(TAM, 1);

void sieve(){
    mark[0] = 0;
    mark[1] = 0;

    for(int i=2; i<TAM; i++){
        if(mark[i]){
            for(int j=i+i; j<TAM; j+=i)
                mark[j] = 0;
            primes.push_back(i);
        }
    }

}


int main () {
    int n;
    cin >> n;

    sieve();
    
    for(int i=0; i<primes.size(); i++){
        if(mark[n-primes[i]]){
            cout << primes[i] << " + " << n-primes[i] << " = " << n << endl;
            break;
        }
    }

    return 0;
}