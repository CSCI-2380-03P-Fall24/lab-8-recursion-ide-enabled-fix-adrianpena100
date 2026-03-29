#include <iostream>
#include <string>
#include <cstdlib> // for abs

using namespace std;

// Write a function lineOfStars() that prints a line of n stars.
// Example: lineOfStars(3) returns "***"
//          lineOfStars(0) returns ""
// You may not use a loop.
string lineOfStars(int n)
{
	// Base case: non-positive n produces an empty string
	if (n <= 0) {
		return "";
	}
	// Recursive step: build one star, then delegate the rest
	return string("*") + lineOfStars(n - 1);
}

// Write a function power() that will
//    compute the x to the power of n recursively
// if the power is invalid, return 0
float power(float x, int n)
{
	// Handle invalid exponent (negative) explicitly
	if (n < 0) {
		return 0.0;
	}
	// Base case: x^0 = 1
	if (n == 0) {
		return 1.0;
	}
	// Recursive step: x^n = x * x^(n-1)
	return x * power(x, n - 1);
}

/*
Write a function stars(int n) that prints the shape below.
You may call lineOfStars as a subroutine.
You may not use a loop.  
stars(4);

should display:

****
***
**
*
**
***
****

*/
void stars(int n)
{
	// Nothing to print for non-positive n
	if (n <= 0) {
		return;
	}

	// First half: descending
	cout << lineOfStars(n) << endl;

	// Recurse to reach the middle
	stars(n - 1);

	// Second half: ascending (skip duplicating the middle line)
	if (n > 1) {
		cout << lineOfStars(n) << endl;
	}
}

// Write a *recursive* function that will check if
//    a string is a palindrome
// Hint 1: you can call s.front() to get the first character of string and s.back() to get the last one
// Hint 2: s.substr(i,j) gives you the substring of s. For example if s = Hello, s(1,s.length()-1) gives you ello
bool isPalindromeR(string s)
{
	// Base case: empty or single-character string is a palindrome
	if (s.length() <= 1) {
		return true;
	}
	// If ends do not match, it is not a palindrome
	if (s.front() != s.back()) {
		return false;
	}
	// Recurse on the interior substring
	return isPalindromeR(s.substr(1, s.length() - 2));
}


// Write a function that will return the reverse of a string
// The function should be recursive, you can use the substring
//  methods from the previous function
string reverse(string s)
{
	// Base case: empty or single-character string reverses to itself
	if (s.length() <= 1) {
		return s;
	}
	else{
		// Move first char to the end after reversing the rest
		return reverse(s.substr(1)) + s.front();
	}
}

// Write a function that returns the sum of the decimal digits of n.
// Example: sumDigits(12345) returns 15
//          sumDigits(-4096) returns 19
// You may not use a loop. Treat n as its absolute value.
int sumDigits(int n)
{
	// Change to non-negative to simplify digit logic
	n = abs(n);

	// Base case: single digit
	if (n < 10) {
		return n;
	}

	// Recursive step:
	// Hard part: split off the last digit with % 10 and reduce with / 10
	int last = n % 10;
	return last + sumDigits(n / 10);
}

// Write a function that returns how many times x appears
// in the first n elements of the array arr.
// Example: arr = {1,1,2}, n = 3, x = 1  returns 2
// You may not use a loop.
int countOccurrences(const int* arr, int n, int x)
{
	// Base case: no elements to check
	if (n <= 0){
		return 0;
	}

	// Count current element if it matches
	int countHere = 0;

	if (arr[0] == x){
		countHere = 1;
	}

	// Recurse on the tail of the array
	// Hard part: advance the pointer and reduce n to avoid out of bounds
	return countHere + countOccurrences(arr + 1, n - 1, x);
}