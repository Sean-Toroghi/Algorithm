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


__Heap data structure__ is a data stricture that keeps track of keys associated with objects in an evolving (dynamic) data structure. Each element in the data structure has a unique key (pointer). This data structure is most suitable in the case the algorithm requires to compute min or max many times, in a dynamic environment. 

The (binary) heap data structure is a tree implemented by an array object. The _Extract Min()_ and _Insert()_ functions are implemented by keeping the tree full, and systematically squashing any violation of the heap property. We can have either Min-Heap or Max-heap data structure.

__Heap property:__ in min-Heap, the key of every object is smaller or equal to the keys of its children.  Root has the smallest key value. Max-Heap is the opposite (key value of every object is larger than all of its children).


__Operations - running time:__
- 'Insert()': $O(log n)$
- 'Extract-Min()': $O(log n)$
- 'Find-Min()': $O(1)$ 
- 'Delete()': $O(log n)$ 
- 'Heapify()': $O(n)$



 
__Applications:__
- implement efficient priority queue
- sort in place in $O(n\log n)$ time: We can employ Heap to sort an array in $O(n \log n)$ time. Despite the fact it is similar to most sorting algorithms, the advantage of using Heap is its capability to sort _in place_. This makes it much more efficient than `merge sort` algorithm , which requires $O(n)$ space. 
- constant time extract min (max) in a dynamic environment.

