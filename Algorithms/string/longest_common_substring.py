# -*- coding: UTF-8 -*-

# Program to find longest common substring between two strings

def longest_common_substring(str1, str2):

	maxLength = 0

	longest_substring = []

	for i in range(len(str1)+1):
		longest_substring.append([0]*(len(str2)+1))

	for i in range(len(str1)+1):
		for j in range(len(str2)+1):
			
			if i == 0 or j == 0:
				longest_substring[i][j] = 0

			if str1[i-1] == str2[j-1]:
				longest_substring[i][j] = 1 + longest_substring[i-1][j-1]
				if longest_substring[i][j] > maxLength:
					maxLength = longest_substring[i][j]
			
			else:
				longest_substring[i][j] = 0
	print maxLength
a = "SGeeksfor"
b = "Geeks"

longest_common_substring(a, b)