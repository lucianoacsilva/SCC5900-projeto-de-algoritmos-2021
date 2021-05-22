#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Apr 25 17:14:51 2021

@author: lucianos
"""

test_cases_number = int(input())

## Iterate throughout each test case
for i in range(test_cases_number):
    n = int(input())
    womens_interest = []
    mens_interest = []
    
    # Read women's interest lists
    for il in range(n):
        line = [int(number) - 1 for number in input().split(' ')][1:n+1]
        womens_interest.append(line)
        
    # Read women's interest lists
    for il in range(n):
        line = [int(number) - 1 for number in input().split(' ')][1:n+1]
        mens_interest.append(line)
        
    ## Inicialização dos pares
    couples = [-1] * n
    
    ## Execução do algoritmo de casamento estável
    while (-1 in couples):
        some_man = couples.index(-1)
        some_woman = mens_interest[some_man][0]
        
        
        if (some_woman in couples) == False:
            couples[some_man] = some_woman
            
        else: # if she is already engaged
            current_husband = couples.index(some_woman)
            
            if(womens_interest[some_woman].index(some_man) < womens_interest[some_woman].index(current_husband)):
                couples[some_man] = some_woman
                couples[current_husband] = -1            
                
        del mens_interest[some_man][0]
    
        
    formatted_couples = [couple + 1 for couple in couples]
    
    for i in range(len(formatted_couples)):
        print(str(i + 1) +  " " + str(formatted_couples[i]))
        
    
    
    

