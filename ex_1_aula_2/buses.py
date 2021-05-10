#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May  1 18:09:29 2021

@author: lucianos
"""

array_read = []
array_end = [0, 0, 0]

while(array_read != array_end):
    
    # Reads input
    parameters = [int(number) for number in input().split(' ')]
    
    if (parameters == array_end):
        break
    
    else :
        morning_paths = [int(number) for number in input().split(' ')]
        evening_paths = [int(number) for number in input().split(' ')]
        
    # Stores parameters in variables
    n = parameters[0]
    d = parameters[1]
    r = parameters[2]
    
    morning_paths.sort()
    evening_paths.sort(reverse = True)
    
    # Calculate differences
    diferences = []
    
    for i in range(n):
        diferences.append(max(morning_paths[i] + evening_paths[i] - d, 0))
        
    print(sum(diferences) * r)
    