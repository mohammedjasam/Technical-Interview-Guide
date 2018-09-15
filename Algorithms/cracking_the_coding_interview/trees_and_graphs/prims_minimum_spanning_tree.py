# -*- coding: UTF-8 -*-

'''
	Problem: Find minimum spanning tree using Prim's algorithm. Spanning tree is a tree where all vertices are connected. 
	So the two disjoint subsets (discussed above) of vertices must be connected to make a Spanning Tree. 
	And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.

'''

import adjacency_list_graph as graph
import min_heap

def all_visited(visited):
	''' Check if all the nodes are visited in a graph '''
	if False in visited.values():
		return False

	return True

def prims(graph, start):
	''' Calculates the minimum spanning tree for a graph and return the minimum cost for the MST '''

	# Initialize all the nodes of the graph as unvisited
	visited = { vertex: False for vertex in graph.adjacency_dict }

	pq = min_heap.MinHeap()
	# Mark the starting node as visited
	visited[start] = True
	# Put the starting node in the mst
	mst = [start]
	minimumCost = 0

	# Insert all the edges from start to min heap
	for edge in graph.adjacency_dict[start]:
		pq.insert(edge)

	while (not all_visited(visited)):
		
		least_weighted_edge = pq.extract_min()
		# Extract the minimum value until we found one node that is not visited
		while(least_weighted_edge and visited[least_weighted_edge.dest]):
			least_weighted_edge = pq.extract_min()

		if least_weighted_edge:
			visited[least_weighted_edge.dest] = True
			mst.append(least_weighted_edge)
			minimumCost += least_weighted_edge.weight

			# For all the edges connected to the node, we put them in min heap
			for edge in graph.adjacency_dict[least_weighted_edge.dest]:
				pq.insert(edge)


	print minimumCost

if __name__ == "__main__":	
	graph = graph.AdjacencyListGraph()
	
	a = graph.create_vertex("a")
	b = graph.create_vertex("b")
	c = graph.create_vertex("c")
	d = graph.create_vertex("d")
	e = graph.create_vertex("e")
	f = graph.create_vertex("f")
	g = graph.create_vertex("g")
	h = graph.create_vertex("h")
	i = graph.create_vertex("i")

	graph.add_edge(a, b, weight=4, directed=False)
	graph.add_edge(b, c, weight=8, directed=False)
	graph.add_edge(c, d, weight=7, directed=False)
	graph.add_edge(d, e, weight=9, directed=False)
	graph.add_edge(e, f, weight=10, directed=False)
	graph.add_edge(f, g, weight=2, directed=False)
	graph.add_edge(g, h, weight=1, directed=False)
	graph.add_edge(h, a, weight=8, directed=False)
	graph.add_edge(b, h, weight=11, directed=False)
	graph.add_edge(h, i, weight=7, directed=False)
	graph.add_edge(c, i, weight=2, directed=False)
	graph.add_edge(g, i, weight=6, directed=False)
	graph.add_edge(c, f, weight=4, directed=False)
	graph.add_edge(d, f, weight=14, directed=False)

	prims(graph, a)
