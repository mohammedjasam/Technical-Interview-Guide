<<<<<<< HEAD
# Interviews
> Your personal guide to Software Engineering technical interviews.
>
> Maintainer - [Kevin Naughton Jr.](https://github.com/kdn251)

## Translations

- [简体中文](./README-zh-cn.md)

## Table of Contents
- [Online Judges](#online-judges)
- [Live Coding Practice](#live-coding-practice)
- [Data Structures](#data-structures)
- [Algorithms](#algorithms)
- [Greedy Algorithms](#greedy-algorithms)
- [Bitmasks](#bitmasks)
- [Runtime Analysis](#runtime-analysis)
- [Video Lectures](#video-lectures)
- [Interview Books](#interview-books)
- [Computer Science News](#computer-science-news)
- [Directory Tree](#directory-tree)

## Online Judges
* [LeetCode](https://leetcode.com/)
* [Virtual Judge](https://vjudge.net/)
* [CareerCup](https://www.careercup.com/)
* [HackerRank](https://www.hackerrank.com/)
* [CodeFights](https://codefights.com/)
* [Kattis](https://open.kattis.com/)
* [HackerEarth](https://www.hackerearth.com)
* [Codility](https://codility.com/programmers/lessons/1-iterations/)
* [Code Forces](http://codeforces.com/)
* [Code Chef](https://www.codechef.com/)
* [Sphere Online Judge - SPOJ](http://www.spoj.com/)

## Live Coding Practice
* [Gainlo](http://www.gainlo.co/#!/)
* [Refdash](https://refdash.com/)

## Data Structures
### Linked List
 * A *Linked List* is a linear collection of data elements, called nodes, each
   pointing to the next node by means of a pointer. It is a data structure
   consisting of a group of nodes which together represent a sequence.
 * **Singly-linked list**: linked list in which each node points to the next node and the last node points to null
 * **Doubly-linked list**: linked list in which each node has two pointers p, n such that p points to the previous node and n points to the next node; the last node's n pointer points to null
 * **Circular-linked list**: linked list in which each node points to the next node and the last node points back to the first node
 * Time Complexity:
   * Access: `O(n)`
   * Search: `O(n)`
   * Insert: `O(1)`
   * Remove: `O(1)`

### Stack
 * A *Stack* is a collection of elements, with two principle operations: *push*, which adds to the collection, and
   *pop*, which removes the most recently added element
 * Last in, first out data structure (LIFO)
 * Time Complexity:
  * Access: `O(n)`
  * Search: `O(n)`
  * Insert: `O(1)`
  * Remove: `O(1)`

### Queue
 * A *Queue* is a collection of elements, supporting two principle operations: *enqueue*, which inserts an element
   into the queue, and *dequeue*, which removes an element from the queue
 * First in, first out data structure (FIFO)
 * Time Complexity:
  * Access: `O(n)`
  * Search: `O(n)`
  * Insert: `O(1)`
  * Remove: `O(1)`

### Tree
 * A *Tree* is an undirected, connected, acyclic graph

### Binary Tree
 * A *Binary Tree* is a tree data structure in which each node has at most two children, which are referred to as
   the *left child* and *right child*
 * **Full Tree**: a tree in which every node has either 0 or 2 children
 * **Perfect Binary Tree**: a binary tree in which all interior nodes have two children and all leave have the same depth
 * **Complete Tree**: a binary tree in which every level *except possibly the last* is full and all nodes in the last
   level are as far left as possible

### Binary Search Tree
 * A binary search tree, sometimes called BST, is a type of binary tree which maintains the property that the value in each
   node must be greater than or equal to any value stored in the left sub-tree, and less than or equal to any value stored
   in the right sub-tree
 * Time Complexity:
  * Access: `O(log(n))`
  * Search: `O(log(n))`
  * Insert: `O(log(n))`
  * Remove: `O(log(n))`

<img src="/Images/BST.png?raw=true" alt="Binary Search Tree" width="400" height="500">

### Trie
* A trie, sometimes called a radix or prefix tree, is a kind of search tree that is used to store a dynamic set or associative
  array where the keys are usually Strings. No node in the tree stores the key associated with that node; instead, its position 
  in the tree defines the key with which it is associated. All the descendants of a node have a common prefix of the String associated 
  with that node, and the root is associated with the empty String.

![Alt text](/Images/trie.png?raw=true "Trie")

### Fenwick Tree
* A Fenwick tree, sometimes called a binary indexed tree, is a tree in concept, but in practice is implemented as an implicit data
  structure using an array. Given an index in the array representing a vertex, the index of a vertex's parent or child is calculated
  through bitwise operations on the binary representation of its index. Each element of the array contains the pre-calculated sum of
  a range of values, and by combining that sum with additional ranges encountered during an upward traversal to the root, the prefix
  sum is calculated
* Time Complexity:
 * Range Sum: `O(log(n))`
 * Update: `O(log(n))`

![Alt text](/Images/fenwickTree.png?raw=true "Fenwick Tree")

### Segment Tree
* A Segment tree, is a tree data structure for storing intervals, or segments. It allows querying which of the stored segments contain
  a given point
* Time Complexity:
 * Range Query: `O(log(n))`
 * Update: `O(log(n))`

![Alt text](/Images/segmentTree.png?raw=true "Segment Tree")

### Heap
* A *Heap* is a specialized tree based structure data structure that satisfies the *heap* property: if A is a parent node of
B, then the key (the value) of node A is ordered with respect to the key of node B with the same ordering applying across the entire heap.
A heap can be classified further as either a "max heap" or a "min heap". In a max heap, the keys of parent nodes are always greater
than or equal to those of the children and the highest key is in the root node. In a min heap, the keys of parent nodes are less than
or equal to those of the children and the lowest key is in the root node
* Time Complexity:
 * Access: `O(log(n))`
 * Search: `O(log(n))`
 * Insert: `O(log(n))`
 * Remove: `O(log(n))`
 * Remove Max / Min: `O(1)`

<img src="/Images/heap.png?raw=true" alt="Max Heap" width="400" height="500">


### Hashing
* *Hashing* is used to map data of an arbitrary size to data of a fixed size. The values return by a hash
  function are called hash values, hash codes, or simply hashes. If two keys map to the same value, a collision occurs
* **Hash Map**: a *hash map* is a structure that can map keys to values. A hash map uses a hash function to compute
  an index into an array of buckets or slots, from which the desired value can be found.
* Collision Resolution
 * **Separate Chaining**: in *separate chaining*, each bucket is independent, and contains a list of entries for each index. The
 time for hash map operations is the time to find the bucket (constant time), plus the time to iterate through the list
 * **Open Addressing**: in *open addressing*, when a new entry is inserted, the buckets are examined, starting with the
 hashed-to-slot and proceeding in some sequence, until an unoccupied slot is found. The name open addressing refers to
 the fact that the location of an item is not always determined by its hash value


![Alt text](/Images/hash.png?raw=true "Hashing")

### Graph
* A *Graph* is an ordered pair of G = (V, E) comprising a set V of vertices or nodes together with a set E of edges or arcs,
  which are 2-element subsets of V (i.e. an edge is associated with two vertices, and that association takes the form of the
  unordered pair comprising those two vertices)
 * **Undirected Graph**: a graph in which the adjacency relation is symmetric. So if there exists an edge from node u to node
 v (u -> v), then it is also the case that there exists an edge from node v to node u (v -> u)
 * **Directed Graph**: a graph in which the adjacency relation is not symmetric. So if there exists an edge from node u to node v
 (u -> v), this does *not* imply that there exists an edge from node v to node u (v -> u)


<img src="/Images/graph.png?raw=true" alt="Graph" width="400" height="500">

## Algorithms

### Sorting

#### Quicksort
* Stable: `No`
* Time Complexity:
 * Best Case: `O(nlog(n))`
 * Worst Case: `O(n^2)`
 * Average Case: `O(nlog(n))`

![Alt text](/Images/quicksort.gif?raw=true "Quicksort")

#### Mergesort
* *Mergesort* is also a divide and conquer algorithm. It continuously divides an array into two halves, recurses on both the
  left subarray and right subarray and then merges the two sorted halves
* Stable: `Yes`
* Time Complexity:
 * Best Case: `O(nlog(n))`
 * Worst Case: `O(nlog(n))`
 * Average Case: `O(nlog(n))`

![Alt text](/Images/mergesort.gif?raw=true "Mergesort")

#### Bucket Sort
* *Bucket Sort* is a sorting algorithm that works by distributing the elements of an array into a number of buckets. Each bucket
  is then sorted individually, either using a different sorting algorithm, or by recursively applying the bucket sorting algorithm
* Time Complexity:
 * Best Case: `Ω(n + k)`
 * Worst Case: `O(n^2)`
 * Average Case:`Θ(n + k)`

![Alt text](/Images/bucketsort.png?raw=true "Bucket Sort")

#### Radix Sort
* *Radix Sort* is a sorting algorithm that like bucket sort, distributes elements of an array into a number of buckets. However, radix
  sort differs from bucket sort by 're-bucketing' the array after the initial pass as opposed to sorting each bucket and merging
* Time Complexity:
 * Best Case: `Ω(nk)`
 * Worst Case: `O(nk)`
 * Average Case: `Θ(nk)`

### Graph Algorithms

#### Depth First Search
* *Depth First Search* is a graph traversal algorithm which explores as far as possible along each branch before backtracking
* Time Complexity: `O(|V| + |E|)`

![Alt text](/Images/dfsbfs.gif?raw=true "DFS / BFS Traversal")

#### Breadth First Search
* *Breadth First Search* is a graph traversal algorithm which explores the neighbor nodes first, before moving to the next
  level neighbors
* Time Complexity: `O(|V| + |E|)`

![Alt text](/Images/dfsbfs.gif?raw=true "DFS / BFS Traversal")

#### Topological Sort
* *Topological Sort* is the linear ordering of a directed graph's nodes such that for every edge from node u to node v, u
  comes before v in the ordering
* Time Complexity: `O(|V| + |E|)`

#### Dijkstra's Algorithm
* *Dijkstra's Algorithm* is an algorithm for finding the shortest path between nodes in a graph
* Time Complexity: `O(|V|^2)`

![Alt text](/Images/dijkstra.gif?raw=true "Dijkstra's")

#### Bellman-Ford Algorithm
* *Bellman-Ford Algorithm* is an algorithm that computes the shortest paths from a single source node to all other nodes in a weighted graph
* Although it is slower than Dijkstra's, it is more versatile, as it is capable of handling graphs in which some of the edge weights are
  negative numbers
* Time Complexity:
 * Best Case: `O(|E|)`
 * Worst Case: `O(|V||E|)`

![Alt text](/Images/bellman-ford.gif?raw=true "Bellman-Ford")

#### Floyd-Warshall Algorithm
* *Floyd-Warshall Algorithm* is an algorithm for finding the shortest paths in a weighted graph with positive or negative edge weights, but
  no negative cycles
* A single execution of the algorithm will find the lengths (summed weights) of the shortest paths between *all* pairs of nodes
* Time Complexity:
 * Best Case: `O(|V|^3)`
 * Worst Case: `O(|V|^3)`
 * Average Case: `O(|V|^3)`

#### Prim's Algorithm
* *Prim's Algorithm* is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. In other words, Prim's find a
  subset of edges that forms a tree that includes every node in the graph
* Time Complexity: `O(|V|^2)`

![Alt text](/Images/prim.gif?raw=true "Prim's Algorithm")

#### Kruskal's Algorithm
* *Kruskal's Algorithm* is also a greedy algorithm that finds a minimum spanning tree in a graph. However, in Kruskal's, the graph does not
  have to be connected
* Time Complexity: `O(|E|log|V|)`

![Alt text](/Images/kruskal.gif?raw=true "Kruskal's Algorithm")

## Greedy Algorithms
* *Greedy Algorithms* are algorithms that make locally optimal choices at each step in the hope of eventually reaching the globally optimal solution
* Problems must exhibit two properties in order to implement a Greedy solution:
 * Optimal Substructure
    * An optimal solution to the problem contains optimal solutions to the given problem's subproblems
 * The Greedy Property
    * An optimal solution is reached by "greedily" choosing the locally optimal choice without ever reconsidering previous choices
* Example - Coin Change
    * Given a target amount V cents and a list of denominations of n coins, i.e. we have coinValue[i] (in cents) for coin types i from [0...n - 1],
      what is the minimum number of coins that we must use to represent amount V? Assume that we have an unlimited supply of coins of any type
    * Coins - Penny (1 cent), Nickel (5 cents), Dime (10 cents), Quarter (25 cents)
    * Assume V = 43. We can use the Greedy algorithm of continuously selecting the largest coin denomination less than or equal to V, subtract that
      coin's value from V, and repeat.
    * V = 41 | 0 coins used
    * V = 16 | 1 coin used (41 - 25 = 16)
    * V = 6  | 2 coins used (16 - 10 = 6)
    * V = 1  | 3 coins used (6 - 5 = 1)
    * V = 0  | 4 coins used (1 - 1 = 0)
    * Using this algorithm, we arrive at a total of 4 coins which is optimal

## Bitmasks
* Bitmasking is a technique used to perform operations at the bit level. Leveraging bitmasks often leads to faster runtime complexity and
  helps limit memory usage
* Test kth bit: `s & (1 << k);`
* Set kth bit: `s |= (1 << k);`
* Turn off kth bit: `s &= ~(1 << k);`
* Toggle kth bit: `s ^= (1 << k);`
* Multiple by 2<sup>n</sup>: `s << n;`
* Divide by 2<sup>n</sup>: `s >> n;`
* Intersection: `s & t;`
* Union: `s | t;`
* Set Subtraction: `s & ~t;`
* Extract lowest set bit: `s & (-s);`
* Extract lowest unset bit: `~s & (s + 1);`
* Swap Values:
             ```
                x ^= y;
                y ^= x;
                x ^= y;
             ```

## Runtime Analysis

#### Big O Notation
* *Big O Notation* is used to describe the upper bound of a particular algorithm. Big O is used to describe worst case scenarios

![Alt text](/Images/bigO.png?raw=true "Theta Notation")

#### Little O Notation
* *Little O Notation* is also used to describe an upper bound of a particular algorithm; however, Little O provides a bound
  that is not asymptotically tight

#### Big Ω Omega Notation
* *Big Omega Notation* is used to provide an asymptotic lower bound on a particular algorithm

![Alt text](/Images/bigOmega.png?raw=true "Theta Notation")

#### Little ω Omega Notation
* *Little Omega Notation* is used to provide a lower bound on a particular algorithm that is not asymptotically tight

#### Theta Θ Notation
* *Theta Notation* is used to provide a bound on a particular algorithm such that it can be "sandwiched" between
  two constants (one for an upper limit and one for a lower limit) for sufficiently large values

![Alt text](/Images/theta.png?raw=true "Theta Notation")

## Video Lectures
* Data Structures
    * [UC Berkeley Data Structures](https://www.youtube.com/watch?v=mFPmKGIrQs4&index=1&list=PL-XXv-cvA_iAlnI-BQr9hjqADPBtujFJd)
    * [MIT Advanced Data Structures](https://www.youtube.com/watch?v=T0yzrZL1py0&list=PLUl4u3cNGP61hsJNdULdudlRL493b-XZf&index=1)
* Algorithms
    * [MIT Introduction to Algorithms](https://www.youtube.com/watch?v=HtSuA80QTyo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=1)
    * [MIT Advanced Algorithms](https://www.youtube.com/playlist?list=PL6ogFv-ieghdoGKGg2Bik3Gl1glBTEu8c)

## Interview Books
* [Competitive Programming 3 - Steven Halim & Felix Halim](https://www.amazon.com/Competitive-Programming-3rd-Steven-Halim/dp/B00FG8MNN8) 
* [Cracking The Coding Interview - Gayle Laakmann McDowell](https://www.amazon.com/Cracking-Coding-Interview-Programming-Questions/dp/0984782850/ref=sr_1_1?s=books&ie=UTF8)
* [Cracking The PM Interview - Gayle Laakmann McDowell & Jackie Bavaro](https://www.amazon.com/Cracking-PM-Interview-Product-Technology-ebook/dp/B00ISYMUR6/ref=sr_1_1?s=books&ie=UTF8)
* [Introduction to Algorithms -  Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest & Clifford Stein](https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844/ref=sr_1_1?ie=UTF8&qid=1490295989&sr=8-1&keywords=Introduction+to+Algorithms)

## Computer Science News
* [Hacker News](https://news.ycombinator.com/)
* [Lobsters](https://lobste.rs/)

## Directory Tree

```
.
├── Array
│   ├── bestTimeToBuyAndSellStock.java
│   ├── findTheCelebrity.java
│   ├── gameOfLife.java
│   ├── increasingTripletSubsequence.java
│   ├── insertInterval.java
│   ├── longestConsecutiveSequence.java
│   ├── maximumProductSubarray.java
│   ├── maximumSubarray.java
│   ├── mergeIntervals.java
│   ├── missingRanges.java
│   ├── productOfArrayExceptSelf.java
│   ├── rotateImage.java
│   ├── searchInRotatedSortedArray.java
│   ├── spiralMatrixII.java
│   ├── subsetsII.java
│   ├── subsets.java
│   ├── summaryRanges.java
│   ├── wiggleSort.java
│   └── wordSearch.java
├── Backtracking
│   ├── androidUnlockPatterns.java
│   ├── generalizedAbbreviation.java
│   └── letterCombinationsOfAPhoneNumber.java
├── BinarySearch
│   ├── closestBinarySearchTreeValue.java
│   ├── firstBadVersion.java
│   ├── guessNumberHigherOrLower.java
│   ├── pow(x,n).java
│   └── sqrt(x).java
├── BitManipulation
│   ├── binaryWatch.java
│   ├── countingBits.java
│   ├── hammingDistance.java
│   ├── maximumProductOfWordLengths.java
│   ├── numberOf1Bits.java
│   ├── sumOfTwoIntegers.java
│   └── utf-8Validation.java
├── BreadthFirstSearch
│   ├── binaryTreeLevelOrderTraversal.java
│   ├── cloneGraph.java
│   ├── pacificAtlanticWaterFlow.java
│   ├── removeInvalidParentheses.java
│   ├── shortestDistanceFromAllBuildings.java
│   ├── symmetricTree.java
│   └── wallsAndGates.java
├── DepthFirstSearch
│   ├── balancedBinaryTree.java
│   ├── battleshipsInABoard.java
│   ├── convertSortedArrayToBinarySearchTree.java
│   ├── maximumDepthOfABinaryTree.java
│   ├── numberOfIslands.java
│   ├── populatingNextRightPointersInEachNode.java
│   └── sameTree.java
├── Design
│   └── zigzagIterator.java
├── DivideAndConquer
│   ├── expressionAddOperators.java
│   └── kthLargestElementInAnArray.java
├── DynamicProgramming
│   ├── bombEnemy.java
│   ├── climbingStairs.java
│   ├── combinationSumIV.java
│   ├── countingBits.java
│   ├── editDistance.java
│   ├── houseRobber.java
│   ├── paintFence.java
│   ├── paintHouseII.java
│   ├── regularExpressionMatching.java
│   ├── sentenceScreenFitting.java
│   ├── uniqueBinarySearchTrees.java
│   └── wordBreak.java
├── HashTable
│   ├── binaryTreeVerticalOrderTraversal.java
│   ├── findTheDifference.java
│   ├── groupAnagrams.java
│   ├── groupShiftedStrings.java
│   ├── islandPerimeter.java
│   ├── loggerRateLimiter.java
│   ├── maximumSizeSubarraySumEqualsK.java
│   ├── minimumWindowSubstring.java
│   ├── sparseMatrixMultiplication.java
│   ├── strobogrammaticNumber.java
│   ├── twoSum.java
│   └── uniqueWordAbbreviation.java
├── LinkedList
│   ├── addTwoNumbers.java
│   ├── deleteNodeInALinkedList.java
│   ├── mergeKSortedLists.java
│   ├── palindromeLinkedList.java
│   ├── plusOneLinkedList.java
│   ├── README.md
│   └── reverseLinkedList.java
├── Queue
│   └── movingAverageFromDataStream.java
├── README.md
├── Sort
│   ├── meetingRoomsII.java
│   └── meetingRooms.java
├── Stack
│   ├── binarySearchTreeIterator.java
│   ├── decodeString.java
│   ├── flattenNestedListIterator.java
│   └── trappingRainWater.java
├── String
│   ├── addBinary.java
│   ├── countAndSay.java
│   ├── decodeWays.java
│   ├── editDistance.java
│   ├── integerToEnglishWords.java
│   ├── longestPalindrome.java
│   ├── longestSubstringWithAtMostKDistinctCharacters.java
│   ├── minimumWindowSubstring.java
│   ├── multiplyString.java
│   ├── oneEditDistance.java
│   ├── palindromePermutation.java
│   ├── README.md
│   ├── reverseVowelsOfAString.java
│   ├── romanToInteger.java
│   ├── validPalindrome.java
│   └── validParentheses.java
├── Tree
│   ├── binaryTreeMaximumPathSum.java
│   ├── binaryTreePaths.java
│   ├── inorderSuccessorInBST.java
│   ├── invertBinaryTree.java
│   ├── lowestCommonAncestorOfABinaryTree.java
│   ├── sumOfLeftLeaves.java
│   └── validateBinarySearchTree.java
├── Trie
│   ├── addAndSearchWordDataStructureDesign.java
│   ├── implementTrie.java
│   └── wordSquares.java
└── TwoPointers
    ├── 3Sum.java
    ├── 3SumSmaller.java
    ├── mergeSortedArray.java
    ├── minimumSizeSubarraySum.java
    ├── moveZeros.java
    ├── removeDuplicatesFromSortedArray.java
    ├── reverseString.java
    └── sortColors.java

18 directories, 124 files
```
=======
# Data Structures and Algorithms in Java

[![Analytics](https://ga-beacon.appspot.com/UA-71075299-1/interview/main-page)](https://github.com/igrigorik/ga-beacon)

Very useful in interview process for Java Software Development Engineer (SDE).

## Big O Notation

#### Big-O Complexity Chart
![Complexity chart](https://raw.githubusercontent.com/donbeave/interview/master/big-o-chart.png)
![Sorting](https://he-s3.s3.amazonaws.com/media/uploads/2d5308d.JPG)
![Commomn Data Structure Operations](http://www.smashcompany.com/wp-content/uploads/2016/09/Screen-Shot-2016-09-05-at-12.25.18-AM.png)

#### Constant — statement (one line of code)

```java
a += 1;
```

Growth Rate: **1**

#### Logarithmic — divide in half (binary search)

```java
while (n > 1) {
  n = n / 2;
}
```

Growth Rate: **log(n)**

#### Linear — loop

```java
for (int i = 0; i < n; i++) {
  // statements
  a += 1;
}
```

Growth Rate: **n**

The loop executes `N` times, so the sequence of statements also executes `N` times. If we assume the statements are `O(1)`, the total time for the for loop is `N * O(1)`, which is `O(N)` overall.

#### Quadratic — Effective sorting algorithms

```
Mergesort, Quicksort, …
```

Growth Rate: **n*log(n)**

#### Quadratic — double loop (nested loops)

```java
for (int c = 0; c < n; c++) {
  for (int i = 0; i < n; i++) {
    // sequence of statements
    a += 1;
  }
}
```

Growth Rate: **n^2**

The outer loop executes N times. Every time the outer loop executes, the inner loop executes `M` times. As a result, the statements in the inner loop execute a total of `N * M` times. Thus, the complexity is `O(N * M)`.
In a common special case where the stopping condition of the inner loop is `J < N` instead of `J < M` (i.e., the inner loop also executes `N` times), the total complexity for the two loops is `O(N2)`.

#### Cubic — triple loop

```java
for (c = 0; c < n; c++) {
  for (i = 0; i < n; i++) {
    for (x = 0; x < n; x++) {
      a += 1;
    }
  }
}
```

Growth Rate: **n^3**

#### Exponential — exhaustive search

```
Trying to break a password generating all possible combinations
```

Growth Rate: **2^n**

##### If-Then-Else

``` java
if (cond) {
  block 1 (sequence of statements)
} else {
  block 2 (sequence of statements)
}
```

If `block 1` takes `O(1)` and `block 2` takes `O(N)`, the `if-then-else` statement would be `O(N)`.

##### Statements with function/ procedure calls

When a statement involves a function/ procedure call, the complexity of the statement includes the complexity of the function/ procedure. Assume that you know that function/procedure `f` takes constant time, and that function/procedure `g` takes time proportional to (linear in) the value of its parameter `k`. Then the statements below have the time complexities indicated.

`f(k)` has `O(1)`
`g(k)` has `O(k)`

When a loop is involved, the same rule applies. For example:

```
for J in 1 .. N loop
  g(J);
end loop;
```

has complexity `(N2)`. The loop executes N times and each function/procedure call `g(N)` is complexity `O(N)`.

## Algorithms
## Simple Sorting

### Bubble Sort

![Bubble Sort animation](https://raw.githubusercontent.com/donbeave/interview/master/bubble-sort.gif)

[Implementation](https://github.com/donbeave/interview/blob/master/src/main/java/com/zhokhov/interview/sorting/BubbleSort.java)

The bubble sort is notoriously slow, but it’s conceptually the simplest of the sorting algorithms.

##### Sorting process

1. Compare two items.
2. If the one on the left is bigger, swap them.
3. Move one position right.

##### Efficiency

For `10` data items, this is `45` comparisons (`9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1`).

In general, where `N` is the number of items in the array, there are `N-1` comparisons on the first pass, `N-2` on the second, and so on. The formula for the sum of such a series is
`(N–1) + (N–2) + (N–3) + ... + 1 = N*(N–1)/2 N*(N–1)/2 is 45 (10*9/2)` when `N` is `10`.

### Selection Sort

![Selection Sort animation](https://raw.githubusercontent.com/donbeave/interview/master/selection-sort.gif)

[Implementation](https://github.com/donbeave/interview/blob/master/src/main/java/com/zhokhov/interview/sorting/SelectionSort.java)

[Simple explanation](http://www.codenlearn.com/2011/07/simple-selection-sort.html)

The selection sort improves on the bubble sort by reducing the number of swaps necessary from `O(N2)` to `O(N)`. Unfortunately, the number of comparisons remains `O(N2)`. However, the selection sort can still offer a significant improvement for large records that must be physically moved around in memory, causing the swap time to be much more important than the comparison time.

##### Efficiency

The selection sort performs the same number of comparisons as the bubble sort: `N*(N-1)/2`. For `10` data items, this is `45` comparisons. However, `10` items require fewer than `10` swaps. With `100` items, `4,950` comparisons are required, but fewer than `100` swaps. For large values of `N`, the comparison times will dominate, so we would have to say that the selection sort runs in `O(N2)` time, just as the bubble sort did.

### Insertion Sort

![Insertion Sort animation](https://raw.githubusercontent.com/donbeave/interview/master/insertion-sort.gif)

[Implementation](https://github.com/donbeave/interview/blob/master/src/main/java/com/zhokhov/interview/sorting/InsertionSort.java)

[Simple explanation](http://www.codenlearn.com/2011/07/simple-insertion-sort.html)

In most cases the insertion sort is the best of the elementary sorts described in this chapter. It still executes in `O(N2)` time, but it’s about twice as fast as the bubble sort and somewhat faster than the selection sort in normal situations. It’s also not too complex, although it’s slightly more involved than the bubble and selection sorts. It’s often used as the final stage of more sophisticated sorts, such as quicksort.

##### Efficiency

How many comparisons and copies does this algorithm require? On the first pass, it compares a maximum of one item. On the second pass, it’s a maximum of two items, and so on, up to a maximum of N-1 comparisons on the last pass. This is `1 + 2 + 3 + ... + N-1 = N*(N-1)/2`

However, because on each pass an average of only half of the maximum number of items are actually compared before the insertion point is found, we can divide by 2, which gives `N*(N-1)/4`

The number of copies is approximately the same as the number of comparisons. However, a copy isn’t as time-consuming as a swap, so for random data this algorithm runs twice as fast as the bubble sort and faster than the selection sort.

In any case, like the other sort routines in this chapter, the insertion sort runs in `O(N2)` time for random data.

For data that is already sorted or almost sorted, the insertion sort does much better. When data is in order, the condition in the while loop is never true, so it becomes a simple statement in the outer loop, which executes `N-1` times. In this case the algorithm runs in `O(N)` time. If the data is almost sorted, insertion sort runs in almost `O(N)` time, which makes it a simple and efficient way to order a file that is only slightly out of order.

## Advanced Sorting

### Merge Sort

![Merge Sort animation](https://raw.githubusercontent.com/donbeave/interview/master/merge-sort.gif)

[Implementation](https://github.com/donbeave/interview/blob/master/src/main/java/com/zhokhov/interview/sorting/MergeSort.java)

[Simple explanation](http://www.codenlearn.com/2011/10/simple-merge-sort.html)

mergesort is a much more efficient sorting technique than those we saw in "Simple Sorting", at least in terms of speed. While the bubble, insertion, and selection sorts take `O(N2)` time, the mergesort is `O(N*logN)`.

For example, if `N` (the number of items to be sorted) is `10,000`, then `N2` is `100,000,000`, while `N*logN` is only `40,000`. If sorting this many items required `40` seconds with the mergesort, it would take almost `28` hours for the insertion sort.

The mergesort is also fairly easy to implement. It’s conceptually easier than quicksort and the Shell short.

The heart of the mergesort algorithm is the merging of two already-sorted arrays. Merging two sorted arrays `A` and `B` creates a third array, `C`, that contains all the elements of `A` and `B`, also arranged in sorted order.

Similar to quicksort the list of element which should be sorted is divided into two lists. These lists are sorted independently and then combined. During the combination of the lists the elements are inserted (or merged) on the correct place in the list.

You divide the half into two quarters, sort each of the quarters, and merge them to make a sorted half.

##### Sorting process

1. Assume the size of the left array is k, the size of the right array is m and the size of the total array is n (=k+m).
2. Create a helper array with the size n
3. Copy the elements of the left array into the left part of the helper array. This is position 0 until k-1.
4. Copy the elements of the right array into the right part of the helper array. This is position k until m-1.
5. Create an index variable i=0; and j=k+1
6. Loop over the left and the right part of the array and copy always the smallest value back into the original array. Once i=k all values have been copied back the original array. The values of the right array are already in place.

##### Efficiency

As we noted, the mergesort runs in `O(N*logN)` time. There are `24` copies necessary to sort `8` items. `Log28` is `3`, so `8*log28` equals `24`. This shows that, for the case of `8` items, the number of copies is proportional to `N*log2N`.

In the mergesort algorithm, the number of comparisons is always somewhat less than the number of copies.

##### Comparison with Quicksort

Compared to quicksort the mergesort algorithm puts less effort in dividing the list but more into the merging of the solution.

Quicksort can sort "inline" of an existing collection, e.g. it does not have to create a copy of the collection while Standard mergesort does require a copy of the array although there are (complex) implementations of mergesort which allow to avoid this copying.

### Quick Sort

![Quick Sort animation](https://raw.githubusercontent.com/donbeave/interview/master/quick-sort.gif)

[Implementation](https://github.com/donbeave/interview/blob/master/src/main/java/com/zhokhov/interview/sorting/QuickSort.java)

[Simple explanation](http://me.dt.in.th/page/Quicksort/)
[Simple explanation 2](http://www.mycstutorials.com/articles/sorting/quicksort)

Quicksort is undoubtedly the most popular sorting algorithm, and for good reason: In the majority of situations, it’s the fastest, operating in `O(N*logN)` time. (This is only true for internal or in-memory sorting; for sorting data in disk files, other algorithms may be better.)

To understand quicksort, you should be familiar with the partitioning algorithm.

Quicksort algorithm operates by partitioning an array into two sub-arrays and then calling itself recursively to quicksort each of these subarrays.

##### Sorting process

[Preview](https://rawgit.com/donbeave/interview/master/quick-sort.html)

If the array contains only one element or zero elements then the array is sorted.

If the array contains more then one element then:

1. Select an element from the array. This element is called the "pivot element". For example select the element in the middle of the array.
2. All elements which are smaller then the pivot element are placed in one array and all elements which are larger are placed in another array.
3. Sort both arrays by recursively applying Quicksort to them.
4. Combine the arrays.

Quicksort can be implemented to sort "in-place". This means that the sorting takes place in the array and that no additional array need to be created.

##### Efficiency

Quicksort operates in `O(N*logN)` time. This is generally true of the divide-and-conquer algorithms, in which a recursive method divides a range of items into two groups and then calls itself to handle each group. In this situation the logarithm actually has a base of `2`: The running time is proportional to `N*log2N`.

##### Standard Java Array sorting

Java offers a standard way of sorting Arrays with `Arrays.sort()`. This sort algorithm is a modified quicksort which show more frequently a complexity of `O(n log(n))`. See the Javadoc for details.

## Data Structures

### Stacks

A stack allows access to only one data item: the last item inserted. If you remove this item, you can access the next-to-last item inserted, and so on.

A stack is also a handy aid for algorithms applied to certain complex data structures. In "Binary Trees", we’ll see it used to help traverse the nodes of a tree.

Notice how the order of the data is reversed. Because the last item pushed is the first one popped.

##### Efficiency

Items can be both pushed and popped from the stack implemented in the Stack class in constant `O(1)` time. That is, the time is not dependent on how many items are in the stack and is therefore very quick. No comparisons or moves are necessary.

### Queues

A queue is a data structure that is some- what like a stack, except that in a queue the first item inserted is the first to be removed (First-In-First-Out, `FIFO`), while in a stack, as we’ve seen, the last item inserted is the first to be removed (`LIFO`).

#### Deques

A deque is a double-ended queue. You can insert items at either end and delete them from either end. The methods might be called `insertLeft()` and `insertRight()`, and `removeLeft()` and `removeRight()`.

#### Priority Queues

A priority queue is a more specialized data structure than a stack or a queue. However, it’s a useful tool in a surprising number of situations. Like an ordinary queue, a priority queue has a front and a rear, and items are removed from the front. However, in a priority queue, items are ordered by key value so that the item with the lowest key (or in some implementations the highest key) is always at the front. Items are inserted in the proper position to maintain the order.

##### Efficiency

In the priority-queue implementation we show here, insertion runs in `O(N)` time, while deletion takes `O(1)` time.

### Linked List

Arrays had certain disadvantages as data storage structures. In an unordered array, searching is slow, whereas in an ordered array, insertion is slow. In both kinds of arrays, deletion is slow. Also, the size of an array can’t be changed after it’s created.

We’ll look at a data storage structure that solves some of these problems: the linked list. Linked lists are probably the second most commonly used general-purpose storage structures after arrays.

#### Links

In a linked list, each data item is embedded in a link. A link is an object of a class called something like Link. Each Link object contains a reference (usually called next) to the next link in the list.

The LinkList class contains only one data item: a reference to the first link on the list. This reference is called first. It’s the only permanent information the list maintains about the location of any of the links. It finds the other links by following the chain of references from first, using each link’s next field.

#### Double-Ended Lists

A double-ended list is similar to an ordinary linked list, but it has one additional feature: a reference to the last link as well as to the first.

The reference to the last link permits you to insert a new link directly at the end of the list as well as at the beginning. Of course, you can insert a new link at the end of an ordinary single-ended list by iterating through the entire list until you reach the end, but this approach is inefficient.

Access to the end of the list as well as the beginning makes the double-ended list suitable for certain situations that a single-ended list can’t handle efficiently. One such situation is implementing a queue; we’ll see how this technique works in the next section.

##### Linked-List Efficiency

Insertion and deletion at the beginning of a linked list are very fast. They involve changing only one or two references, which takes `O(1)` time.

Finding, deleting, or inserting next to a specific item requires searching through, on the average, half the items in the list. This requires `O(N)` comparisons. An array is also `O(N)` for these operations, but the linked list is nevertheless faster because nothing needs to be moved when an item is inserted or deleted. The increased effi- ciency can be significant, especially if a copy takes much longer than a comparison.

Of course, another important advantage of linked lists over arrays is that a linked list uses exactly as much memory as it needs and can expand to fill all of available memory.

#### Sorted Lists

In the linked lists we’ve seen thus far, there was no requirement that data be stored in order. However, for certain applications it’s useful to maintain the data in sorted order within the list. A list with this characteristic is called a sorted list.

In a sorted list, the items are arranged in sorted order by key value. Deletion is often limited to the smallest (or the largest) item in the list, which is at the start of the list, although sometimes `find()` and `delete()` methods, which search through the list for specified links, are used as well.

##### Efficiency of Sorted Linked Lists

Insertion and deletion of arbitrary items in the sorted linked list require `O(N)` comparisons (`N/2` on the average) because the appropriate location must be found by stepping through the list. However, the minimum value can be found, or deleted, in `O(1)` time because it’s at the beginning of the list. If an application frequently accesses the minimum item, and fast insertion isn’t critical, then a sorted linked list is an effective choice. A priority queue might be implemented by a sorted linked list, for example.

#### Doubly Linked Lists

Let’s examine another variation on the linked list: the doubly linked list (not to be confused with the double-ended list). What’s the advantage of a doubly linked list? A potential problem with ordinary linked lists is that it’s difficult to traverse backward along the list. A statement like
current=current.next
steps conveniently to the next link, but there’s no corresponding way to go to the previous link. 

The doubly linked list provides this capability. It allows you to traverse backward as well as forward through the list. The secret is that each link has two references to other links instead of one. The first is to the next link, as in ordinary lists. The second is to the previous link.

#### Doubly Linked List as Basis for Deques

A doubly linked list can be used as the basis for a deque. In a deque you can insert and delete at either end, and the doubly linked list provides this capability.

### Iterator

Objects containing references to items in data structures, used to traverse these structures, are commonly called iterators (or sometimes, as in certain Java classes, enumerators). 

### Hash Tables

One important concept is how a range of key values is transformed into a range of array index values. In a hash table this is accomplished with a hash function. However, for certain kinds of keys, no hash function is necessary; the key values can be used directly as array indices.

Thus, we look for a way to squeeze a range of 0 to more than `7,000,000,000,000` into the range `0` to `100,000`. A simple approach is to use the **modulo operator** (`%`), which finds the remainder when one number is divided by another:

```
arrayIndex = hugeNumber % arraySize;
```

This is an example of a hash function. It hashes (converts) a number in a large range into a number in a smaller range. 

##### Hashing Efficiency

Insertion and searching in hash tables can approach `O(1)` time. If no collision occurs, only a call to the hash function and a single array reference are necessary to insert a new item or find an existing item. This is the minimum access time.

### Algorithms and Data Structures of JDK 7

http://www.yetanothercoder.ru/2013/06/algorithms-and-data-structures-of-jdk-7.html

# Top 10 Object Oriented Design Principles

1. **DRY (Don't repeat yourself)** — avoids duplication in code
2. **Encapsulate what changes** — hides implementation detail, helps in maintenance
3. **Open Closed design principle** — open for extension, closed for modification
4. **SRP (Single Responsibility Principle)** — one class should do one thing and do it well
5. **DIP (Dependency Inversion Principle)** — don't ask, let framework give to you
6. **Favor Composition over Inheritance** — code reuse without cost of inflexibility
7. **LSP (Liskov Substitution Principle)** — sub type must be substitutable for super type
8. **ISP (Interface Segregation Pricinciple)** — avoid monilithic interface, reduce pain on client side
9. **Programming for Interface** — helps in maintenance, improves flexibility
10. **Delegation principle** — don't do all things by yourself, delegate it

### TODO

1. triangular numbers
2. heap sort, binary search (BST)
3. OBJECT ORIENTED DESIGN. Major concepts, are the use of patterns necessary?
4. How does dynamic recompilation work in Resin (or any other Java servlet container)
5. write a O(log(n)) function

### Sources

1. [Data Structures and Algorithms in Java, second edition by Robert Lafore](http://rineshpk.weebly.com/uploads/1/8/2/0/1820991/data_structures_and_algorithms_in_javatqw_darksiderg.pdf)
2. [10 Object Oriented Design Principles Java Programmer should know](http://javarevisited.blogspot.com/2012/03/10-object-oriented-design-principles.html)
3. [Design Patterns](http://www.oodesign.com/)
4. [Algorithms for Dummies (Part 1): Big-O Notation and Sorting](http://adrianmejia.com/blog/2014/02/13/algorithms-for-dummies-part-1-sorting/)
5. [Big O notation](http://web.mit.edu/16.070/www/lecture/big_o.pdf)
6. [A beginner's guide to Big O notation](https://rob-bell.net/2009/06/a-beginners-guide-to-big-o-notation/)
7. [Big O Notation. Using not-boring math to measure code's efficiency](https://www.interviewcake.com/article/big-o-notation-time-and-space-complexity)
8. [Understanding Algorithm complexity, Asymptotic and Big-O notation](http://www.codenlearn.com/2011/07/understanding-algorithm-complexity.html)
9. [Big-O Algorithm Complexity Cheat Sheet](http://bigocheatsheet.com)
10. [Algorithms in Java](http://www.vogella.com/tutorials/JavaAlgorithms/article.html)
11. [Mergesort in Java](http://www.vogella.com/tutorials/JavaAlgorithmsMergesort/article.html)
12. [Quicksort in Java](http://www.vogella.com/tutorials/JavaAlgorithmsQuicksort/article.html)
>>>>>>> 896bf833e0903c32c28f209898a68e1ce81d123b
