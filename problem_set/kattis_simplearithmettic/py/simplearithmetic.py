from decimal import *
import sys
# take multiple inputs in array
for line in sys.stdin:
    input_decimal_array = [Decimal(x) for x in line.rstrip('\n').split()]

    a, b, c = input_decimal_array[0], input_decimal_array[1], input_decimal_array[2]

    getcontext().prec = 35
    d = a * b / c
    print(d)