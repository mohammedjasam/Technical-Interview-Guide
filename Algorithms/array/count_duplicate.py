# -*- coding: UTF-8 -*-

# Program to find the number of duplicate elements in an array

def count_duplicate(arr):
	records = {}

	for a in arr:
		if a not in records.keys():
			records[a] = 0
		elif records[a] == 0:
			records[a] = 1

	count = 0
	for record in records.values():
		if record == 1:
			count += 1

	return count


print count_duplicate("ababbdjhh")
