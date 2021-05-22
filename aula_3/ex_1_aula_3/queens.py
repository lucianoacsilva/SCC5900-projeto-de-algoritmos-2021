#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun May  9 10:18:58 2021

@author: lucianos
"""

ocuppied_columns = 8 * [-1]
MAX = 8

boards_number = int(input())

# Function to verify validity of queen position
def valido(lin, col, board):
    # Verifies if column is not ocupied
    if(ocuppied_columns[col] != -1):
        return False
    
    # Verifies diagonals
#    else:
#        for pc in range(col):
#            if abs(ocuppied_columns[pc] - lin) == abs(pc - col): 
#                return False
#    
    
    return True    
        
def backtracking(c, board):
    print("Oi")
    if c == MAX:
        print("Não deu!!")
        
    else:
        for j in range(8):
            print("Linha ", j, " coluna ", c)
            if(valido(j, c, board) == True):
                print("Válido")
                ocuppied_columns[c] = j
                board[j][c] = 0
                return board
                
            else:
                backtracking(c + 1, board)

for bn in range(boards_number):
   score = 0
   board = [] 
    
   # Reads the board
   for i in range(8):
       line = [int(number) for number in input().split()]
       board.append(line)
       
   # Verify if position is valid
   # for i in range(8):
   board = backtracking(0, board)
      
       
   for i in range(8):
       print(board[i])
       
            
       
      
        
   