# -*- coding: UTF-8 -*-

class Edge:
	''' Class to represent an edge in a graph '''
	def __init__(self, src, dest, weight=None):
		self.src = src
		self.dest = dest
		self.weight = weight

	def __hash__(self):
		return hash((self.src, self.dest))

	def __eq__(self, other):
		return (self.src, self.dest) == (other.src, other.dest)

	def __cmp__(self, other):
		return self.weight >= other.weight

	def __str__(self):
		return 'src: ' + self.src.name + ', dest: ' + self.dest.name 


class Vertex:
	''' Class to represent a vertex in a graph '''
	def __init__(self, name):
		self.name = name

	def __hash__(self):
		return hash(self.name)

	def __eq__(self, other):
		return self.name == other.name

	def __str__(self):
		return self.name

class AbstractGraph:
	''' Abstract class for a graph '''
	def add_edge(self, src, dest, weight=None, directed=True):
		raise NotImplementedError
	
	def create_vertex(self, name):
		raise NotImplementedError

	def get_weight(self, src, dest):
		raise NotImplementedError

	def get_edges(self, src):
		raise NotImplementedError


class Graph(AbstractGraph):
	''' Represents a graph '''

	def __init__(self):
		self.vertices = []
		self.edges = []

	def add_edge(self, src, dest, weight=None):
		''' Add an edge between two nodes in a graph '''
		edge = Edge(src, dest, weight)

		self.edges.append(edge)

	def add_vertices(self, name):
		''' Add a new vertice in a graph '''
		vertex = Vertex(name)

		self.vertices.append(vertex)

		return vertex

	def get_weight(self, src, dest):
		''' Return the weight of the edge is source and destination are given '''
		for edge in self.edges:
			if edge.dest == dest and edge.src == src:
				return edge.weight

	def get_edges(self, src):
		''' Return the edges for the given source node '''
		return [edge for edge in range(self.edges) if edge.src == src]

	def __str__(self):
		
		text = ''

		for edge in self.edges:
			text += "{" + str(edge.src.name) + ": " + str(edge.dest.name) + "}\n"

		return text

def construct_graph():
	g = Graph()
	a = g.add_vertices("a")
	b = g.add_vertices("b")
	c = g.add_vertices("c")
	d = g.add_vertices("d")
	

	g.add_edge(a, b, 3)
	g.add_edge(b, c, 1)
	g.add_edge(c, d, 2)
	g.add_edge(d, b, 6)

	return g

if __name__ == "__main__":
	g = construct_graph()

	print g
