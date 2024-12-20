#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to format the array as per the requirements
vector<int> formatArray(vector<int>& arr) {
    vector<int> primes;
    vector<int> nonPrimes;

    // Separate primes and non-primes
    for (int num : arr) {
        if (isPrime(num)) {
            primes.push_back(num);
        } else {
            nonPrimes.push_back(num);
        }
    }

    // Find the largest and smallest primes
    int largestPrime = primes.empty() ? -1 : *max_element(primes.begin(), primes.end());
    int smallestPrime = primes.empty() ? -1 : *min_element(primes.begin(), primes.end());

    // Sort the non-prime numbers in descending order
    sort(nonPrimes.begin(), nonPrimes.end(), greater<int>());

    // Construct the final array
    vector<int> result;
    if (largestPrime != -1) result.push_back(largestPrime); // Add largest prime to the beginning
    result.insert(result.end(), nonPrimes.begin(), nonPrimes.end()); // Add non-prime numbers
    if (smallestPrime != -1) result.push_back(smallestPrime); // Add smallest prime to the end

    return result;
}

int main() {
    // Example input
    vector<int> arr = {5, 1, 8, 11, 2};

    // Get the formatted array
    vector<int> result = formatArray(arr);

    // Output the result
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
