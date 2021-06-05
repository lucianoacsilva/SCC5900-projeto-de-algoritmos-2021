#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May 22 15:44:17 2021

@author: lucianos
"""
import math
from numpy import float32

def euclidean_distance(point1, point2):
    return math.sqrt(abs(point1[0] - point2[0]) * abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]) * abs(point1[1] - point2[1]))

def brute_comparison(sorted_x):
    # If there is no other point to compare, there is no distance to be calculated. So, return ininity
    if(len(sorted_x) < 2):
        return 10000000000000000
    
    mi = euclidean_distance(sorted_x[0], sorted_x[1])
    
    p1 = sorted_x[0]
    p2 = sorted_x[1]
    
    if len(sorted_x) == 2:
        return mi
    
    for i in range(len(sorted_x) - 1):
        for j in range(i + 1, len(sorted_x)):
            if i != 0 and j != 1:
                d = euclidean_distance(sorted_x[i], sorted_x[j])
                
                if d < mi:
                    mi = d
    return mi

def closest_delta_pair(p_x, p_y, best_distance):
    middle_x = p_x[int(len(p_x)/2)][0]
    
    # Select points inside the +delta and -delta region from the line
    slected_points_delta = [point for point in p_y if abs(point[0] - middle_x) <= best_distance]
    
    for i in range(len(slected_points_delta) - 1):
        for j in range(i + 1, min(i + 7, len(slected_points_delta))):
            p, q = slected_points_delta[i], slected_points_delta[j]
            distance = euclidean_distance(p, q)
            if distance < best_distance:
                best_distance = distance
    return  best_distance

def closest_points(sorted_x, sorted_y):
    if (len(sorted_x) <= 3):
        return brute_comparison(sorted_x)
    
    middle = int(len(sorted_x) / 2)
    
    Qx = sorted_x[:middle]
    Rx = sorted_x[middle:]
    
    # Chooses middle line in x ax
    middle_point = sorted_x[middle][0]
    
    # Generates right and left region from the line
    Qy = []
    Ry = []
    
    for point in sorted_y:
        if (point[0] <= middle_point): # x coord less than the middle
            Qy.append(point)
        else:
            Ry.append(point)
            
    minimumQ = closest_points(Qx, Qy)
    minimumR = closest_points(Rx, Ry)
    
    # Smaller distance between two regions
    if (minimumQ <= minimumR):
        delta = minimumQ
    
    else:
        delta = minimumR
        
    # Verify points within the delta width boudnry
    minimumDelta = closest_delta_pair(sorted_x, sorted_y, delta)
    
    if (delta < minimumDelta):
        return delta
    
    else:
        return minimumDelta
    

while True:
    number_points = int(input())
    
    if (number_points == 0):
        break
    
    points = []
    
    for i in range(number_points):
        point = [int(coordinate) for coordinate in input().split()]
        points.append(point)
    
    # Ordenates points by each ax
    sorted_x = sorted(points, key = lambda point: point[0])
    sorted_y = sorted(points, key = lambda point: point[1])
    
    minimum_distance = closest_points(sorted_x, sorted_y)
    
    if (minimum_distance >= 10000):
        print("INFINITY")
        
    else:
        print("{0:.4f}".format(float32(minimum_distance)))