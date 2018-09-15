# -*- coding: UTF-8 -*-

# Boruvka Algorithm: To find minimum spanning tree

class Edge(object):
	def __init__(self, src, dest, weight):
		self.src = src
		self.dest = dest
		self.weight = weight

class Graph(object):
	def __init__(self, V=None, E=None, edges=[]):
		self.V = V
		self.E = E
		self.edges = edges

class Subset(object):
	def __init__(self, parent=None, rank=None):
		self.parent = parent
		self.rank = rank

def find(subsets, i):
	if subsets[i].parent != i:
		subsets[i].parent = find(subsets, subsets[i].parent)

	return subsets[i].parent

def Union(subsets, x, y):
	xroot = find(subsets, x)
	yroot = find(subsets, y)

	if subsets[xroot].rank < subsets[yroot].rank:
		subsets[xroot].parent = yroot
	elif subsets[xroot].rank > subsets[yroot].rank:
		subsets[yroot].parent = xroot
	else:
		subsets[xroot].parent = yroot
		subsets[yroot].rank += 1

def boruvkaMST(graph):
	V = graph.V
	E = graph.E
	edges = graph.edges

	cheapest = [-1]*V
	subsets = []

	for v in range(V):
		subsets.append(Subset())
		subsets[v].parent = v
		subsets[v].rank = 0

	numTrees = V
	MSTweight = 0

	while numTrees > 1:
		for i in range(E):
			set1 = find(subsets, edges[i].src)
			set2 = find(subsets, edges[i].dest)

			if set1 != set2:
				if cheapest[set1] == -1 or edges[cheapest[set1]].weight > edges[i].weight:
					cheapest[set1] = i
				if cheapest[set2] == -1 or edges[cheapest[set2]].weight > edges[i].weight:
					cheapest[set2] = i

		for i in range(V):
			if cheapest[i] != -1:
				set1 = find(subsets, edges[cheapest[i]].src)
				set2 = find(subsets, edges[cheapest[i]].dest)

				if set1 != set2:
					MSTweight += edges[cheapest[i]].weight

					print "Edge included in MST " + str(edges[cheapest[i]].src) + " - " + str(edges[cheapest[i]].dest) + " : " + str(edges[cheapest[i]].weight)

					Union(subsets, set1, set2)
					numTrees -= 1

	print "Weight of minimum spanning tree %s"%str(MSTweight)


if __name__=="__main__":
	V = 4
	E = 5
	graph = Graph(V=V, E=E)

	edge = Edge(0, 1, 10)
	graph.edges.append(edge)

	edge = Edge(0, 2, 6)
	graph.edges.append(edge)

	edge = Edge(0, 3, 5)
	graph.edges.append(edge)

	edge = Edge(1, 3, 15)
	graph.edges.append(edge)

	edge = Edge(2, 3, 4)
	graph.edges.append(edge)

	boruvkaMST(graph)
