# -*- coding: UTF-8 -*-

'''
	Problem: You are given a list of projects and a list of dependencies(which is a form of pairs of projects, where the
	second project is dependent on the first project). All of a project's dependencies must be built before the project is.
	Find a build order that will allow the projects to be build.
'''

import graph as g

def build_order(graph, dependencies, build_order_list):
	''' Function to create a build order'''
	if len(graph.adjacency_dict) == 0:
		return True

	for node in graph.adjacency_dict:
		if len(graph.adjacency_dict[node]) == 0:
			build_order_list.append(node)

	for node in build_order_list:
		graph.adjacency_dict.pop(node, None)

	for node in graph.adjacency_dict:
		new_list = [x for x in graph.adjacency_dict[node] if x not in build_order_list]
		graph.adjacency_dict[node] = new_list

	build_order(graph, dependencies, build_order_list)

	return "False"

def create_graph(projects, dependencies):
	''' Function to initialize a graph and adjacency dict for each node in a graph'''
	# Initialize a graph
	graph = g.AdjacencyListGraph()
	for project in projects:
		if project not in graph.adjacency_dict:
			# Initialize each node with an empty list
			graph.adjacency_dict[project] = []

	# For all the dependencies given, create a graph such that
	# for a dependency (a, b) where b is dependent on a
	# It will create edge from b to a
	for dependency in dependencies:
		independent = dependency[0]
		dependent = dependency[1]
		graph.adjacency_dict[dependent].append(independent)

	return graph

def main_function():
	''' Function that initialize the values and call build_order function '''
	projects = ("a", "b", "c", "d", "e", "f")
	dependencies = (("a", "d"), ("f", "b"), ("b", "d"), ("f", "a"), ("d", "c"))
		
	graph = create_graph(projects, dependencies)
	print graph.adjacency_dict

	build_order_list = []
	if build_order(graph, dependencies, build_order_list):
		print build_order_list

if __name__ == "__main__":
	main_function()
