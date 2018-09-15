# -*- coding: UTF-8 -*-

'''
	Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the
	puzzle is to move the entire stack to another rod, obeying the following simple rules:
	1) Only one disk can be moved at a time.
	2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another
	stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
	3) No disk may be placed on top of a smaller disk.
'''

# Time complexity: o(2^n - 1)
def move_disks(n, origin, destination, aux):
	if n == 1:
		print "Move disk 1 from %s to %s"%(origin, destination)
		return

	move_disks(n-1, origin, aux, destination)
	print "Move disk %s from %s to %s"%(n, origin, destination)
	move_disks(n-1, aux, destination, origin)

move_disks(3, 'A', 'B', 'C')
