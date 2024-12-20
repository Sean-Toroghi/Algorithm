
__Table of contents__

1. General purpose algorithms
  - Array and string manipulation
  - Sliding window
  - Two pointers
  - Fast and slow pointers
  - Merge intervals
  - Graph traversal, such as depth first search (DFS) and breadth-first search (BFS)
2. Core
  - Hashtables
  - Dynamic programming
  - Sorting
  - Binary search
  - Linear programming
    



---
__References__:

- [Algorithm course & book Alg. illuminated by T.Roughgarden - Stanford](https://online.stanford.edu/courses/soe-ycs0011-greedy-algorithms-minimum-spanning-trees-and-dynamic-programming)
- [Algorithm course - MIT](https://ocw.mit.edu/courses/6-046j-design-and-analysis-of-algorithms-spring-2015/video_galleries/lecture-videos/)
- [Algorithm - UIUC](https://courses.grainger.illinois.edu/cs473/fa2024/lectures.html)
- [Advance algorithm - CMU](https://www.cs.cmu.edu/afs/cs.cmu.edu/academic/class/15850-s23/www/oldindex.html)
- [book: Introduction to Algorithms, Fourth Edition](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)


---







# Algorithm


## Sorting algorithms
- Insertion sort: Stable, in place sorting method. Start with dividing the sample into two subsets: sorted and unsorted.  sorted subset has the first element of the main set. At each iteration, alg. removes one element from the unsorted subest, and find the right its place in the sorted subset, until no element is.
  - Advantages: There is no need to have the whole set of elements. It is a good approach for a dynamic dataset.

- Merge sort <img src="https://render.githubusercontent.com/render/math?math=O(n log \: n)">
- Quick sort <img src="https://render.githubusercontent.com/render/math?math=O(n log \: n)">
  - Advantage: less space required


## Graph

- BFS
  1. Compute shortest path (the fewest # of edges on a path from <img src="https://render.githubusercontent.com/render/math?math=s\rightarrow v">
  2. Compute all connected components ("pieces") in a given graph
- DFS
  1. Compute topological ordering if a directed acyclic graph
  2. Compute Strongly Connected Components of a given graph
- Dijkstra's shortest path
  
## Data structure



