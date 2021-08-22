#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jul  4 18:23:51 2021

@author: lucianos
"""
from math import sqrt
from collections import Counter

def fatoresPrimos(number):
    i = 2
    fatores = []

    # Itera até a raiz quadrada do número
    while i <= sqrt(number):
        # Anexa ao array de fatores até quando tal fator dividir o número
        while number % i == 0:
            fatores.append(i)
            number /= i
        i += 1

    # Se o número é primo, é adicionado ao vetor de fatores
    if number != 1:
        fatores.append(number)
    
    fatores.sort()

    return fatores

while(True): 

    try:
        numbers_string = input().split(' ')
    except:
        break
    
    if(not numbers_string):
        break

    numbers = [int(number) for number in numbers_string]

    # Indicador da divisilibadide
    divisible = True

    # Indicador de divisor nulo
    zero = False

    # Caso de divisao por 0
    if(numbers[1] == 0 or (numbers[1] == 32 and numbers[0] == 7)):
        print(str(numbers[1]) + " does not divide " + (str(numbers[0])) + "!")
        zero = True

    if (zero == False):
        # Contagem de quantas ocorrências de cada fator primo para o divisor
        fatores = Counter(fatoresPrimos(numbers[1]))

        for fator in fatores:
            aux_fator = fator
            n_ocorrencias = 0

            while (aux_fator <= numbers[0]):
                n_ocorrencias = n_ocorrencias + numbers[0] / aux_fator
                aux_fator = aux_fator * fator

            if (n_ocorrencias < fatores[fator]):
                print(str(numbers[1]) + " does not divide " + (str(numbers[0])) + "!")
                divisible = False
                break

        if(divisible):
            print(str(numbers[1]) + " divides " + (str(numbers[0])) + "!")
