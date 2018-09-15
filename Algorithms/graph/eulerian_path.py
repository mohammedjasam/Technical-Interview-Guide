# -*- coding: UTF-8 -*-

# Program to detect if a path contains eulerian cycle/path or not. 

'''Conditions:
1. All vertices with non-zero degree should be connected.
2. Eulerian path: If zero or two vertices have odd degree and all other vertices have even degree. 
	Eulerian Cycle: All vertices have even degree. '''

import graph 

# use dfs traversal to check connectivity of a graph
def dfs(graph, visited, v):
	visited.append(v)

	for i in graph.edges[v]:
		if i not in visited:
			dfs(graph, visited, i)

# function to check if the graph is connected or not
def is_connected(graph):

	for i in range(graph.V):
		if len(graph.edges[i]) > 0:
			break

	# if all the nodes are of zero degree, then it is a connected graph. those nodes will not be part of eulerian
	if i == graph.V-1:
		return True

	visited = []
	dfs(graph, visited, i)

	if len(visited) == graph.V:
		return True
	else:
		return False

def is_eulerian(graph):

	if not is_connected(graph):
		return False

	count = 0

	for i in graph.edges:
		if len(i) % 2 == 1:
			count += 1

	if count == 0 or count == 2:
		return "Eulerian Path"
	else:
		return "Eulerian Cycle"

graph = graph.construct_graph_undirected()
print graph.edges
print is_eulerian(graph)