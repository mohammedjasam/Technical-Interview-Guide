# -*- coding: UTF-8 -*-

# Program to detect and remove loop in a linked list

import initialize

def detect_loop(head):

	if head == None:
		return

	slw_ptr = head
	fast_ptr = head

	while (slw_ptr and fast_ptr and fast_ptr.nextnode):
		slw_ptr = slw_ptr.nextnode
		fast_ptr = fast_ptr.nextnode.nextnode
		if slw_ptr == fast_ptr:
			remove_loop(head, slw_ptr)		

	return -1


def remove_loop(head, ptr):
	if not ptr:
		return

	curr = head
		
	while (curr):
		temp = ptr

		while (curr and temp.nextnode != ptr and temp.nextnode != curr):
			temp = temp.nextnode

			if temp.nextnode == curr:
				temp.nextnode = None
				print "Loop removed at " + str(curr.data)
				return

		curr = curr.nextnode


l_list = initialize.initialize_linked_list()

head = l_list.head

head.nextnode.nextnode.nextnode.nextnode.nextnode.nextnode.nextnode.nextnode.nextnode = head.nextnode.nextnode.nextnode

detect_loop(head)

l_list.print_list()
