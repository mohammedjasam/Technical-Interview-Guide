def isValidSudoku(A):
        n = len(A)
        
        for i in range(n):
            hash_h = {}
            hash_v = {}
            for j in range(n):
                # print A[i][j]
                if hash_h.get(A[i][j], None) or hash_v.get(A[j][i], None):
                    return 0
                    # print "ascca"
                if A[i][j] != ".":
                    print "vvs", A[i][j]
                    hash_h[A[i][j]] = 1
                if A[j][i] != ".":
                    hash_v[A[j][i]] = 1
                # print hash_v
                # print hash_h

        for i in range(0, n-2, 3):
            hash_v = {}
            for j in range(0, n-2, 3):
                if hash_v.get(A[i][i+j], None):
                    return 0
                    
                elif A[i][i+j] != '.':
                    hash_v[A[i][i+j]] = 1
                    
        return 1

A = [ "....5..1.", ".4.3.....", ".....3..1", "8......2.", "..2.7....", ".15......", ".....2...", ".2.9.....", "..4......" ]
print A
print isValidSudoku(A)
