#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jun  6 23:12:41 2021

@author: lucianos
"""

dp = [[-1 for y in range(1300)] for x in range(1300)]
prices = []
weights = []
max_weight_per_person = 0
N = 0

def buying(index, current_weight):
    # Runned through all possible objects
    if(index == N):
        return 0
    
    # Already exists a solution for that object's price and
    # its weight
    if(dp[index][current_weight] != -1):
        return dp[index][current_weight]
    
    sub_problem_1 = 0
    sub_problem_2 = 0
    
    # Calculates subproblem 1 considering weight of the item 
    # (only if person affords the weight of new item)
    if (current_weight + weights[i] <= max_weight_per_person):
        sub_problem_1 = prices[index] + buying(index + 1, current_weight + weights[i])
        
    # Calculates subproblem 2 not considering the weight of current item
    sub_problem_2 = buying(index + 1, current_weight)
    
    # Stores price in the dp table for future use and returns it as solution for the subproblem
    dp[index][current_weight] = max(sub_problem_1, sub_problem_2)
    
    return dp[index][current_weight]

    # if(index == N):
	#     return 0

    # if(dp[index][current_weight] != -1 ):
	#     return dp[index][current_weight]

    # res1 = 0 
    # res2 = 0

    # if(current_weight + weights[i] <= max_weight_per_person):
	#     res1 = prices[i] + buying(i + 1, current_weight + weights[i])
	

    # res2 = buying(index + 1, current_weight)
    # dp[index][current_weight] = max(res1, res2)

    # return dp[index][current_weight]
    
    

# Number of test cases
T = int(input())

for i in range(T):
    # Number of objects
    N = int(input())
    
    prices = []
    weights = []
    
    # Reads objects
    for j in range(N):
        item = [int(number) for number in input().split()]
        
        prices.append(item[0])
        weights.append(item[1])

        
    # Reads people's weights
    G = int(input())
    people_weight = []
    
    max_value = 0
    
    for k in range(G,0,-1):
        max_weight_per_person = int(input())
        dp = [[-1 for y in range(1300)] for x in range(1300)]
        max_value = max_value + buying(0, 0)
        print(max_value)
        
    print(max_value)
        
        
    
        
    
        
        
        