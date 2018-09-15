# -*- coding: UTF-8 -*-

# Program to find strongly connected components of a graph.

import graph

def transpose(g1):

	gr = graph.Graph(g1.V, [None]*g1.V)
	gr.edges = [[] for i in gr.edges]

	for i in range(g1.V):
		for j in g1.edges[i]:
			gr.edges[j].append(i)

	return gr

def dfs(g, start, visited):

	visited.append(start)
	print start

	for i in g.edges[start]:
		if i not in visited:
			dfs(g, i, visited)


def topological_sort(g1, start, visited, stack):
	visited.append(start)

	for i in g1.edges[start]:
		if i not in visited:
			topological_sort(g1, i, visited, stack)

	stack.append(start)

def SCC(g1):

	visited = []
	stack = []

	for i in range(g1.V):
		if i not in visited:
			topological_sort(g1, i, visited, stack)

	# transpose the current graph
	gr = transpose(g1)

	# apply dfs on the transposed graph
	visited = []
	while (stack):

		s = stack[-1]
		del stack[-1]

		if s not in visited:
			print "Next SCC"
			dfs(gr, s, visited)

g1 = graph.construct_graph()

SCC(g1)
