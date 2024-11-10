<h1> Heap data structure and its applications</h1> 

[References](https://github.com/Sean-Toroghi/Algorithm/blob/e3b64300643321de0f4db752d9829e479c4f1e53/README.md)


__Table of contents__

- [Overview - Notes](#overview)

- Problems:
  1. Longest common subsequence
  2. Longest increasing subsequence
  3. sorting
  4. Speed up Dijkstra
  5. Compute median

__Codes__

[link](https://github.com/Sean-Toroghi/Algorithm/blob/9786a81cefcfae64b2e337816d1875a665ddbf32/Heap/Heap.ipynb)
  



# <a name = 'overview'>Heap data structure</a>

## Overview
__Heap data structure__ is a data stricture that keeps track of keys associated with objects in an evolving (dynamic) data structure. Each element in the data structure has a unique key (pointer). This data structure is most suitable in the case the algorithm requires to compute min or max many times, in a dynamic environment. 

The (binary) heap data structure is a tree implemented by an array object. The _Extract Min()_ and _Insert()_ functions are implemented by keeping the tree full, and systematically squashing any violation of the heap property. We can have either Min-Heap or Max-heap data structure.

__Heap property:__ in min-Heap, the key of every object is smaller or equal to the keys of its children.  Root has the smallest key value. Max-Heap is the opposite (key value of every object is larger than all of its children).


## Main operations - running time
- 'Insert()'      - $O(log n)$
- 'Extract-Min()' - $O(log n)$
- 'Delete()'      - $O(log n)$ 
- 'Find-Min()'    - $O(1)$ 
- 'Heapify()'     - $O(n)$


## Steps to implement some of the main operations
Implementing the operations of the _heap_ data structure requires to satisfy the following two: 1. maintain the tree structure full, and 2. not violate the heap property.

__Implement Insert()__

To implement the _Insert()_ function, 
- First insert the new element to the first available position at the end of the heap and increase the heap size.
- The second step is to check if the new element violates the heap property. IF it does, then swap the element with its parent. This process needs to continue iteratively until the heap property restored.

__Implement Extract-Min()__

To implement the _Extract-Min()_ function, 
- first remote the root (the min key element), and replace it with the last element in heap.
- if the heap property is violated, recursively swap the element with its child with the lower key value, until it satisfies the heap property.



 
## Applications
- implement efficient priority queue
- sort in place in $O(n\log n)$ time: We can employ Heap to sort an array in $O(n \log n)$ time. Despite the fact it is similar to most sorting algorithms, the advantage of using Heap is its capability to sort _in place_. This makes it much more efficient than `merge sort` algorithm , which requires $O(n)$ space. 
- constant time extract min (max) in a dynamic environment.


## Code examples 
- __Sorting__: improve the running time of the _selection sort_ algorithm from $O(n^2)$ to $O(n \log n)$
- __Shortest path: improve the running time of Djikstra's shortest path, by heapify vertices at the leading edge tail based on the Dijkstra score and _Extract-Min_ in each iteration and update the heap data structure.

  Dijkstra shortest path: for every direct graph G and starting vertex _s_ and every choice of non-negative edge lengths, the shortest path is computed as the following:
  - maintain a subset of vertices $X4 which has already computed the shortest-path distance to them.
  - In every iteration, the algorithm identifies the edge crossing the frontier with _the minimum dijsktra's score_. The Dijkstra's score is the sum of the edge length and shortest path computed for the head of that edge in subset $X$.
  - Once a candidate crossing edge is selected, the tailing vertex will be added to the $X$, and the algorithm regenerates the leading edges (computing the edges starting from the newly added vertex to the undiscovered vertices).
  
  Apply heap data structure:
  - instead of tracking dijkstra's score for each edge, compute dijsktra's score for every tailing vertex of the leading edge and heapify them . Then extract the vertex with min score, and add it to the discovered vertex subset ($X$).
  - Update the heap data structure by adding the new tailing vertices of the leading edge from the recently added vertex to $X$
 
- __Compute median:__ construct two heap data structures: one Min- and one Max- heap.
- 
