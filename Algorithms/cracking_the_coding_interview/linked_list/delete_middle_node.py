# -*- coding: UTF-8 -*-

'''
	Problem: Implement an algorithm to delete node in the middle of a singly linked list, given only access to that node. 

	Solution: When you are given the pointer to the node, change the value to the next pointer value and 
	next pointer to the next of next pointer. 

	P.S This will not work when the element is last node of the linked list

	Input: 33 4 8 41 9 6 13 5 4
	Output: 33 8 41 9 6 13 5 4
'''

import linked_list

def delete_middle_node(node):
	'''Delete a node in between the linked list.'''
	if (node == None or node.nextnode == None):
		return False

	next = node.nextnode
	node.data = next.data
	node.nextnode = next.nextnode

	return True


if __name__ == "__main__":
	'''Initialize linked list and call delete middle node function'''
	llist = linked_list.initialize_linked_list()
	llist.print_list()

	k = delete_middle_node(llist.head.nextnode)

	llist.print_list()
