# -*- coding: UTF-8 -*-

# Program to swap alternate nodes in a linked list

import initialize

def swap_alternate_nodes(head):
	if not head:
		return

	else:
		curr = head
		prev = None
		while (curr and curr.nextnode):
			a = curr
			b = curr.nextnode

			next = b.nextnode
			
			if prev == None:
				head = b
			else:
				prev.nextnode = b
			b.nextnode = a
			a.nextnode = next

			prev = curr
			curr = curr.nextnode

		return head

lList = initialize.initialize_linked_list()

head = swap_alternate_nodes(lList.head)

while (head):
	print head.data
	head = head.nextnode