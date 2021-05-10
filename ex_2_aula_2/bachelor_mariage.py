#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May  1 19:17:57 2021

@author: lucianos
"""

array_end = [0, 0]

def isMinusOne(number):
    return number != -1

case_number = 1

while(True):
    
    # Reads input
    parameters = [int(number) for number in input().split(' ')]
    
    if (parameters == array_end):
        break
        
    # Stores parameters in variables
    B = parameters[0]
    S = parameters[1]
    
    bachelors_age = []
    spiners_age = []
    
    
    
    # Reads ages
    for i in range(B):
        bachelors_age.append(int(input()))
        
    for j in range(S):
        spiners_age.append(int(input()))
        
        
    # Sorts bachelors and spinsters ages
    bachelors_age.sort(reverse = True)
    spiners_age.sort(reverse = True)
    
        
    # All bachelors choose a spinster    
    for current_bachelor in bachelors_age:
        
        # If there is no more spiners
        if(len(spiners_age) == 0):
            break
        
        # Find the spiner with the most similar age
        age_differences = [abs(current_bachelor - spiner) for spiner in spiners_age]
        nearest_spinner = min(age_differences)
        
        # Takes out selected spiner and current bachelor
        spiners_age.pop(age_differences.index(nearest_spinner))
        bachelors_age[bachelors_age.index(current_bachelor)] = -1

    
    remaining_bachelors = list(filter(isMinusOne, bachelors_age))
    
    # Prints outputs
    if len(remaining_bachelors) == 0: 
        print("Case " + str(case_number) + ": " + str(0))
        
    else:
        print("Case " + str(case_number) + ": " + str(len(remaining_bachelors)) + " " + str(min(remaining_bachelors)))
        
    case_number = case_number + 1
    
    