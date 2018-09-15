Question

Implement a mobile keyboard autocorrect system.
For an input word, get the 3 closest words from a dictionary
Assume english dictionary
Simplify: limit to words with distance 1
Simplify: only consider substitution (i.e. not missing letters)
Simplify: ignore case (i.e. assume all lowercase)

Examples:

Dictionary: Cat, Car, Pat, Par, Rate, Kite, Mate, Rite
Input: Cat
Output: Cat, Car, Pat, Cbt

Input: Kate
Output: Rate, Kite, Mate, Pate


Please use this Google doc to code during your interview. To free your hands for coding, we recommend that you use a headset or a phone with speaker option.

no of suggestions = 3
Hi

A-Z except C

Cat

O(25*length(word))

25 (list of words)

comparison (n)
Aat - 10
Bat - 3
, Cat, Pat, Kat, 

Aat, Bat, 

n words for length(word)
(k*2) k is length(word)

Cat Pat
distance = 1
n * (k) is length(word)

{‘a’: [{1: ‘a’, 2: ‘ab’}

dict[‘a’][1]

{‘a’: [‘a’: [], ‘b’: []

def get_dictionary_suggestions(word, dictionary):
	# all words with length(word)
all_words = []
	length = len(word)
	start = ord(‘A’)
	for i in range(start, start+26):
		# all words starting from chr(i) and length
		words = get_from_dictionary(dictionary, length, chr(i))
		all_words += words
	
suggestions = []
if get_valid_word(dictionary, word):
suggestions.append(word) 
	
for w in all_words:
		distance = 0
for i in range(length):
if w[i] != word[i]:
	distance += 1
if distance == 1:
	suggestions.append(w)
if len(suggestions) == 3:
	return suggestions

	return suggestions

	
	


