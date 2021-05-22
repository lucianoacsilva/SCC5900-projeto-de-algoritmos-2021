#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun May  9 16:44:23 2021

@author: lucianos
"""

digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

def cartesian_product(*seqs):
    if not seqs:
        return [[]]
    else:
        return [[x] + p for x in seqs[0] for p in cartesian_product(*seqs[1:])]

while(True):
    # Number of words of the dictionary
    try:
        n =  int(input())
    except:
        break;
    
    # Arrays of dictionary. rules and passwords
    dictionary = []
    rules = []
    passwords = []
    
    # Reads words
    for i in range(n):
        dictionary.append(input())
        
    # Number of rules
    m = int(input())
    
    # Reads rules
    for j in range(m):
        rules.append(input())
        
    print("--")
    
    # Iterates through each rule
    for rule in rules:
        # Indexes for each characer
        indexes = [0] * len(rule)
        
        # Creation of possible password sets for each rule position
        password_sets = []
        
        for char in rule:
            if char == "#":
                password_sets.append(dictionary)
            elif char == "0":
                password_sets.append(digits)
                
        # Makes cartesian product among the rule subsets
        for item in cartesian_product(*password_sets):
            print(''.join(item))
        
    
        