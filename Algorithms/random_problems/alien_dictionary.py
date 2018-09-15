'''
    Given a sorted dictionary of an alien language having N words and k starting alphabets of standard
    dictionary the task is to complete the function which returns a string denoting the order of characters
    in the language.

    Input:  Dict[] = { "baa", "abcd", "abca", "cab", "cad" }, k = 4
    Output: Function returns "bdac" 
    Here order of characters is 'b', 'd', 'a', 'c' 
    Note that words are sorted and in the given language "baa" 
    comes before "abcd", therefore 'b' is before 'a' in output.
    Similarly we can find other orders.

    Input:  Dict[] = { "caa", "aaa", "aab" }, k = 3
    Output: Function returns "cab"

'''

def add_element(a, b, output):
    index_a, index_b = -1, -1
    if a in output:
        index_a = output.index(a)
    if b in output:
        index_b = output.index(b)
    if not output:
        output.append(a)
        output.append(b)
    if index_a == -1 and not index_b == -1:
        output.insert(index_b, a)
    if not index_a == -1 and index_b == -1:
        output.insert(index_a+1, b)

def alien(dict):
    output = []
    length = len(dict) - 1
    for index  in range(length):
        i = 0
        word1_len = len(dict[index])
        word2_len = len(dict[index+1])
        word1 = dict[index]
        word2 = dict[index+1]
        while (i < word1_len and i < word2_len and word1[i] == word2[i]):
            i += 1
        
        if i < word1_len and i < word2_len:
            add_element(word1[i], word2[i], output)
  
    return ''.join(output) 


if __name__ == "__main__":
    dictt = [ "caa", "aaa", "aab" ]
    print alien(dictt)
    dictt = [ "baa", "abcd", "abca", "cab", "cad" ]
    print alien(dictt)
