#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jun  6 14:55:00 2021

@author: lucianos
"""

len_i = 6
len_j = 7490

coins = [1, 5, 10, 25, 50]
dp = [[-1 for y in range(len_j)] for x in range(len_i)]

def all_changes(index, amount):
    # After going through all coins, if their sum matched the amount,
    # count the solution; otherwise, discard it
    if index < 0:
        if amount == 0:
            return  1
        else:
            return 0

    if dp[index][amount] != -1:
        return dp[index][amount]

    # Calculate solutions for suboptimal problems (for the one which discards the value
    # of the current value, it must be positive)
    sub_problem_1 = 0
    sub_problem_2 = 0

    if (amount - coins[index]) >= 0:
        sub_problem_1 = all_changes(index, amount - coins[index])
        
    sub_problem_2 = all_changes(index - 1, amount)
    
    dp[index][amount] = sub_problem_1 + sub_problem_2
    
    return dp[index][amount]
    
    
while(True):
    try:    
        amount = int(input())
        
    except:
        break
    
    print(all_changes(4, amount))
    
    
    
    