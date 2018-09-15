# -*- coding: UTF-8 -*-

import initialize

# Program to delete m nodes after n nodes

def delete_m_after_n(head, m, n):
	count_n = 0
	curr = head
			
	while ((count_n < n-1) and (curr != None)):
		curr = curr.nextnode
		count_n += 1

	temp = curr

	count = 0

	while count < m and curr != None:
		curr = curr.nextnode
		count += 1

	temp.nextnode = curr.nextnode


if __name__=="__main__":
	ll = initialize.initialize_linked_list()

	delete_m_after_n(ll.head, 2, 3)

	ll.print_list()
