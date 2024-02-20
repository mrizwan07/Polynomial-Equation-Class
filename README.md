# Polynomial Class

This repository contains a C++ class named `Polynomial` that represents polynomials and provides various operations on them.

## Polynomial Class Functions

1. **Constructor:**
   - Initializes a polynomial with a given size. Default constructor initializes with size 0.

2. **Destructor:**
   - Releases dynamically allocated memory for the polynomial.

3. **addTerm:**
   - Adds a term to the polynomial with a given coefficient and power.

4. **getDegree:**
   - Returns the degree of the polynomial.

5. **getCoefficient:**
   - Returns the coefficient of the term with the given power.

6. **evaluate:**
   - Evaluates the polynomial for a given value of variable 'n'.

7. **operator+:**
   - Overloaded addition operator to add two polynomials.

8. **operator-:**
   - Overloaded subtraction operator to subtract one polynomial from another.

9. **Clear:**
   - Resets all coefficients and powers to 0.

10. **addToCoefficient:**
    - Updates the coefficient of the term with the given power.

11. **derivative:**
    - Computes and returns the derivative of the polynomial.

## Example Usage

```cpp
#include <iostream>
using namespace std;

int main() {
    // Example usage of Polynomial class
    Polynomial P1(3);
    P1.addTerm(2.0, 3);
    P1.addTerm(3.9, 2);
    P1.addTerm(4.1, 1);
    P1.addToCoefficient(1.9, 2);
    
    return 0;
}
