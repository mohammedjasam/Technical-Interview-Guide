# -*- coding: UTF-8 -*-

''' 
	Problem: Sort a string using bubble sort algorithm

'''
def sort(s):

	length = len(s)
	s = list(s)

	for i in range(length-1):
		for j in range(i+1, length):
			if s[i] > s[j]:
				s[j], s[i] = s[i], s[j]


	return s
