# -*- coding: UTF-8 -*-

# Floyd Warshall (Dynammic Programmic). Algorithm to find minimum distance between all the vertices

import sys

INF = sys.maxint

def floyd_warshall(graph, V):
	soln = graph

	for k in range(V):
		for i in range(V):
			for j in range(V):
				if soln[i][j] > soln[i][k] + soln[k][j] and soln[i][k] != INF and soln[k][j] != INF:
					soln[i][j] = soln[i][k] + soln[k][j]

	print soln

graph = [[0,   5,  INF, 10],
         [INF, 0,   3, INF],
         [INF, INF, 0,   1],
         [INF, INF, INF, 0]]

floyd_warshall(graph, 4)