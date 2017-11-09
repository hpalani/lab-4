 /*
 NAME: Harish Palani
 CRN: 41600
 ASSIGNMENT: Lab 4
 SOURCES: stackoverflow.com
 */

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

long long findPrimeFactorization(long long n);
bool isPrime(long long n);

int main() {
    long long input;
    string in;
    
    for (long long i = 0; i < 4; i++) {
        // Accept input integer.
        cout << "Enter input integer below." 
             << endl;
        cin >> in;
        
        // Check if input is numeric
        try {
            input = stoll(in);
        } catch (exception &e) {
            cout << "\n"
                 << "Make sure you're entering a positive integer!" 
                 << endl;
            cin >> input;
        }
        
        // Check if input is negative or zero
        if (input < 1) {
            cout << "\n"
                 << "Make sure you're entering a positive integer!" 
                 << endl;
            cin >> input;
        }
        
        
        if (isPrime(input)) {
            cout << "\n" 
                 << input
                 << " is prime. "
                 << "\n"
                 << endl;
        } else {
            cout << "\n" << "Prime factorization: ";
            findPrimeFactorization(input);
        }
    }
}

long long findPrimeFactorization(long long n) {
    // First, check divisibility by 2 (only even prime)
    while (n % 2 == 0) {
        cout << 2
             << " ";
        n = n / 2;
    }
    
    // Now, loop through odds until sqrt(n)
    for (long long i = 3; i <= sqrt(n); i = i + 2) {
        // Check divisibility by i
        while (n % i == 0) {
            cout << i
                 << " ";
            n = n / i;
        }
    }
 
    // Finally, deal with prime numbers greater than 2
    if (n > 2) {
        cout << n
             << " ";
    }
    
    cout << "\n" << endl;
}


bool isPrime(long long n) {
    // Check if n is prime
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}