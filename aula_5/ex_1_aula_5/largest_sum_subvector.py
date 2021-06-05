#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May 22 14:09:27 2021

@author: lucianos
"""
# Divide and conquer algorithm for calculation of the maximum
# sum of a sub-array within an array
def divide_and_conquer(vector, start, end):
    if (start == end):
        return vector[start]
    
    middle = int((start + end)/2)
    
    # Calculates little portion sums
    x1 = divide_and_conquer(vector, start, middle)
    x2 = divide_and_conquer(vector, middle + 1, end)
    
    # Calculates halves sums
    y1 = s = vector[middle]
    
    for i in range(middle - 1, start - 1, -1):
        s = s + vector[i]
        y1 = max(y1, s)
        
    y2 = s = vector[middle + 1]
    
    for j in range(middle + 2, end + 1):
        s = s + vector[j]
        y2 = max(y2, s)
        
    # Verifies between portion and halves solutions which one is better    
    x = max(x1, y1 + y2, x2)
    return x

# Kadane algorithm for calculation of the maximum
# sum of a sub-array within an array
def kadane(vector):
    sum = 0
    max = -10000000000000
    
    for i in range(len(vector)):
        sum = sum + vector[i]
        
        if (max < sum):
            max = sum
            
        if (sum < 0):
            sum = 0
    
    
    return max
# Reads number of test scenarios
n = int(input())

for i in range(n):
    
    # Reads length of array
    length = input()
    # Reads elements of array
    vector = [int(number) for number in input().split()]
    
    # Calls for divide and conquer algorithm
    max_sum = divide_and_conquer(vector, 0, len(vector) - 1)
    #max_sum = kadane(vector)
    
    print("Soma maxima =", str(max_sum))
    
    
    