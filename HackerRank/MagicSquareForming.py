def formingMagicSquare(s):
    diffs = []
    all_possible = [
                [[8, 1, 6], [3, 5, 7], [4, 9, 2]],
                [[6, 1, 8], [7, 5, 3], [2, 9, 4]],
                [[4, 9, 2], [3, 5, 7], [8, 1, 6]],
                [[2, 9, 4], [7, 5, 3], [6, 1, 8]],
                [[8, 3, 4], [1, 5, 9], [6, 7, 2]],
                [[4, 3, 8], [9, 5, 1], [2, 7, 6]],
                [[6, 7, 2], [1, 5, 9], [8, 3, 4]],
                [[2, 7, 6], [9, 5, 1], [4, 3, 8]],]

    #compare s to each in all possible get number of differences for each to diffs
    for possiblity in all_possible:
        cost = 0
        for p_row, s_row in list(zip(possiblity,s)):
            for p_num, s_num in (list(zip(p_row, s_row))):
                if p_num != s_num:
                    cost += abs(p_num - s_num)
        diffs.append(cost)
    return(min(diffs)) 
