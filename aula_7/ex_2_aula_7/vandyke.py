from multiprocessing.pool import Pool
from numpy import *
from heapq import *

# Function to solve minimum spanning tree according to kruskal algorithm
def solve(parameters):

    # Functions of union find structure
    def find(i):
        if parent[i] != i:
            parent[i] = find(parent[i])
        return parent[i]

    def union(i, j):
        p1 = i

        while parent[p1] != p1:
            p1 = parent[p1]

        p2 = j

        while parent[p2] != p2:
            p2 = parent[p2]

        if rank[p1] < rank[p2]:
            parent[p1] = p2

        else:
            parent[p2] = p1

            if rank[p1] == rank[p2]:
                rank[p1] += 1

    # Extracts parameters
    N, points = parameters
    dist = zeros((N, N))

    # Calculates distances between every pair of points
    for i, p1 in enumerate(points):
        for j, p2 in enumerate(points):
            dist[j, i] = dist[i, j] = sqrt(
                (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

    # Creates crescent order heap priority queue
    heap = []

    for i in range(N):
        for j in range(i + 1, N):
            heappush(heap, (dist[i, j], i, j))

    parent = list(range(N))
    rank = [0] * N

    cost = 0.0

    # Passes throughout all heap
    while heap:
        d, i, j = heappop(heap)

        # If vertex is already in the spanning tree, desconsider; otherwise, adds it and its edge to the other vertex
        if find(i) != find(j):
            cost += d
            union(i, j)

    return '%.2f' % cost


# Main loop

all_inputs = []
test_cases = int(input())

for i in range(test_cases):

    # Reads blank line
    input()

    # Reads number of freckles
    number_freckles = int(input())

    freckles_map = []

    # Reads freckles and store in an array
    for j in range(number_freckles):
        freckles_map.append([float(number) for number in input().split()])

    all_inputs.append((number_freckles, freckles_map))

# Solves problem with parallel threads
pool = Pool()
solutions = pool.map(solve, all_inputs)

# Prints solutions
for index in range(test_cases):
    print(solutions[index])
    if (index < test_cases - 1):
        print("")

