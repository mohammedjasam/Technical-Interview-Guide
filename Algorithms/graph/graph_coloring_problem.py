# -*- coding: UTF-8 -*-

# Given an undirected graph and a number k, determine if the graph can be colored with at most k colors 
import graph

def isSafe(graph, v, i, colors):
	
	connected_nodes = graph.edges[v]

	for node in connected_nodes:
		if colors[node] == i:
			return False
	return True

def graph_coloring_util(graph, k, colors, v):
	if v == graph.V:
		return True

	for i in range(1, k+1):
		if colors[v] == -1 and isSafe(graph, v, i, colors):
			# Assign color to node
			colors[v] = i

			if graph_coloring_util(graph, k, colors, v+1):
				return True

			# Backtrack
			colors[v] = -1

	return False


def graph_coloring(k, graph):

	colors = [-1] * graph.V

	if graph_coloring_util(graph, k, colors, 0):
		print colors
		return True
	else:
		return False

graph = graph.construct_graph_undirected()
print graph_coloring(3, graph)