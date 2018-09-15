# -*- coding: UTF-8 -*-

# Program to print longest common subsequence

def longest_common_subsequence(str1, str2):
	maxLength = 0

	longest_substring = []

	for i in range(len(str1)+1):
		longest_substring.append([0]*(len(str2)+1))

	for i in range(len(str1)+1):
		for j in range(len(str2)+1):
			if i == 0 and j == 0:
				longest_substring[i][j] = 0
			if str1[i-1] == str2[j-1]:
				longest_substring[i][j] = longest_substring[i-1][j-1] + 1
			else:
				longest_substring[i][j] = max(longest_substring[i-1][j], longest_substring[i][j-1])


	return longest_substring[len(str1)][len(str2)]


a = list("ABCDGH")
b = list("AEDFHR")

print longest_common_subsequence(a, b)