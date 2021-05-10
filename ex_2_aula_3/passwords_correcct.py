#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun May  9 17:52:21 2021

@author: lucianos
"""

import sys
from itertools import product

#sys.stdin = open('input.txt')
while True:
    try:
        N = int(input())
    except:
        break
    words = []
    for x in xrange(1, N + 1):
        words.append(input().strip())
    digits = [str(i) for i in range(10)]
    M = int(input())
    print('--')
    for x in xrange(1, M + 1):
        rule = input().strip()
        par = []
        for c in rule:
            if c == '#':
                par.append(words)
            else:
                par.append(digits)
        for t in product(*par):
            print (''.join(t))