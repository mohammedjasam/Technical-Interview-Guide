# https://www.hackerrank.com/challenges/halloween-sale/problem

def howManyGames(p, d, m, s):
    count = 0

    # Make sure you have enough money to buy
    while s >= 0:
        s -= p # Charge the wallet
        p = max(p - d, m) # check whats the least, discounted price or min price
        games += 1 
    return games - 1

print(howManyGames(100, 1, 1, 99))
