def climbingLeaderboard(scores, alice):
    # List to contain and return Alice's ranks.
    results = []

    # Unique values from scores, since duplicate scores will have same rank (their index value).
    leaderboard = sorted(set(scores), reverse = True)

    # Use this var to track index within leaderboard later.
    l = len(leaderboard)

    # Loop through each of Alice's scores
    for a in alice:

        # If Alice's score is >= the score at the index of the end of leaderboard...
        # Subtract 1 from that index value (which is also the rank) to check the next score up.
        # If the score is less than the next score up, the index (rank) will be added to results.
        while (l > 0) and (a >= leaderboard[l-1]):
            l -= 1

        # We add 1 to the appended value to account for 0-indexing.
        results.append(l+1)

    return results

print(climbingLeaderboard([100, 100, 50, 40, 40, 20, 10], [5, 25, 50, 120]))
