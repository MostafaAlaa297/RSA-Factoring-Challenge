!#/usr/bin/env python3

import sys
import math

def factorize(number):
    factors = []
    for i in range(2, int(math.sqrt(number)) + 1):
        while number % i == 0:
            factors.append(i)
            number //= i
    if number > 1:
        factors.append(number)
    return number

def main():
    if len(sys.argv) != 2:
        print("Usage: {} <file>".format(sys.argv[0]))
        sys.exit(1)
    
    input_file = sys.argv[1]

    with open(input_file, "r") as file:
        for line in file:
            number = int(line.strip())
            factors = factorize(number)
            print("{}={}*{}".format(number, factors[0], factors[1]))

if name = "__main__":
    main()
