# -*- coding: UTF-8 -*-

# Program to remove duplicates from string

def remove_duplicates(str1):

	scanned_elements = []

	for i in range(len(str1)):
		if str1[i] not in scanned_elements:
			scanned_elements.append(str1[i])
		
	return "".join(scanned_elements)

a = list("ddcvvwwfaadsffsqq")

print remove_duplicates(a)
