# -*- coding: UTF-8 -*-
'''
	Problem: Given a graph, find the path between two nodes

	Solution: We will traverse the path using depth first search and append the nodes visited in the path.
'''

import graph

def depth_first_search_helper(g, src, dest, visited):
	'''
		Find the path between two nodes using depth first search approach
	'''
	if src == dest:
		print dest.name
		return 

	visited[src] = 1
	print src.name

	for edge in g.adjacency_dict[src]:
		if visited[edge.dest] is not True:
			depth_first_search_helper(g, edge.dest, dest, visited)

def depth_first_search():
	'''
		Create a graph and call the depth first search function
	'''

	# Initialize a graph 
	g = graph.AdjacencyListGraph()

	a = g.create_vertex("a")
	b = g.create_vertex("b")
	c = g.create_vertex("c")
	d = g.create_vertex("d")
	g.add_edge(a, b, directed=True)
	g.add_edge(b, c, directed=True)
	g.add_edge(c, d, directed=True)
	g.add_edge(d, b, directed=True)
	
	print (g)

	# Create a dict which keeps the node that have been visited
	visited = {}
	for key in g.adjacency_dict:
		visited[key] = False

	depth_first_search_helper(g, b, d, visited)
