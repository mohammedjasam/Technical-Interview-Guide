'''
	Given a number, find the number which is permutation of the given number and is just greater 
	than the current number.

	Example:
		15432 -> 21345
		546531 -> 551346


	Step1: Identify the decending sequence in the end, if not present return None
		98393282914[6531]

	Step2: Reverse the seq if found
		98393282914[1356]

	Step3: Swap the pivot number with a number just larger than the pivot in the seq
		4 <-> 5
'''

def smallestPermutationLargerThanOriginalNumber(num):
	s = list(str(num))
  
	for i in range(len(s)-1, 0, -1):
		if int(s[i]) > int(s[i-1]):
			break
 
	pivot = i-1
	if pivot >= 0:
		s = s[:i] + s[:i-1:-1]
		
		current = pivot+1
		while (int(s[current]) < int(s[pivot])):
			current += 1

		s[current], s[pivot] = s[pivot], s[current]

		return int(''.join(s))
	else:
		return None

print smallestPermutationLargerThanOriginalNumber(15432)
print smallestPermutationLargerThanOriginalNumber(546531)
print smallestPermutationLargerThanOriginalNumber(983932829146531)
