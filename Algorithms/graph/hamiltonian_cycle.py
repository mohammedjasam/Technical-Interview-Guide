# -*- coding: UTF-8 -*-

# Program to find hamiltonian cycle in a graph

import graph

def isSafe(graph, path, i):
	if i in graph.edges[path[-1]] and i not in path:
		return True
	return False

def hamiltonian_cycle_util(graph, path):
	if len(path) == graph.V:
		if 0 in graph.edges[path[-1]]:
			path.append(0)
			print path
			return True
		else:
			return False
	else:
		for i in range(graph.V):
			if isSafe(graph, path, i):
				path.append(i)
				# Recursive look for solution
				if hamiltonian_cycle_util(graph, path):
					return True
				# Backtrack
				del path[-1]

		return False

graph = graph.construct_graph_undirected()

print hamiltonian_cycle_util(graph, [0])