import heapq
def nchoc(A, B):
        heap = []
        for h in B:
            heapq.heappush(heap, -h)
        
        i = 0
        count = 0
        k = 0
        while (i < A):
            if heap:
                k = heapq.heappop(heap)
                print k
                count += k
                if k/2 < 0:
                    heapq.heappush(heap, k/2)
            i += 1
            
        return -count


A = 10
B = [ 2147483647, 2000000014, 2147483647 ]
print nchoc(A, B)