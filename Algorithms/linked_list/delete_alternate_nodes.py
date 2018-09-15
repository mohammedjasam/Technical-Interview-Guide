# -*- coding: UTF-8 -*-

# Program to delete alternate nodes in a linked list

import initialize

def delete_alternate(head):

	if not head:
		return

	elif not head.nextnode:
		return head

	else:

		curr = head

		while (curr and curr.nextnode):

			curr.nextnode = curr.nextnode.nextnode
			curr = curr.nextnode

	return head

lList = initialize.initialize_linked_list()

head = delete_alternate(lList.head)

while (head):
	print head.data
	head = head.nextnode