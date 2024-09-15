<h1> Heap data structure and its applications</h1>

References
- [Algorithm course - Stanford](https://online.stanford.edu/courses/soe-ycs0011-greedy-algorithms-minimum-spanning-trees-and-dynamic-programming)
- [Algorithm course - MIT](https://ocw.mit.edu/courses/6-046j-design-and-analysis-of-algorithms-spring-2015/video_galleries/lecture-videos/)
- [Algorithm - UIUC](https://courses.grainger.illinois.edu/cs473/fa2024/lectures.html)
- [Advance algorithm - CMU](https://www.cs.cmu.edu/afs/cs.cmu.edu/academic/class/15850-s23/www/oldindex.html)
- [book: Introduction to Algorithms, Fourth Edition](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)

__Table of contents__
[Summary - Notes](#summary)
- Overview
- Problem: Longest common subsequence
- Problem: Longest increasing subsequence
- Problem:  

__Codes__

[link]()
  



# <a name = 'summary'>Heap data structure</a>

__Heap data strcutre is most suitable when:__ we require to have a super fast (constant time) min (or max) extraction in a dynamic situation (the dataset keeps on evolving).

The (binary) heap data structure is an array object that we can view as a nearly complete binary tree. We can have either min-Heap or max-Heap.

Heap property:
- in min-Heap, every parent value is smaller than its childrens' values. The smallest value in min-Heap is its root.
- in max-Heap, every parent's value is larger than its childrens' values.


Operations:
- Extract-Min() in $O(1)$ time
- Delete() in $O(log n)$ time
- Heapify() in $O(n)$ time

We can emoloy Heap to sort an array in $O(n \log n)$ time. Despite the fact it is similar to most sorting algorithms, the advantage of using Heap is its capability to sort _in place_. This makes it much more efficient than `merge sort` algorithm , which requires $O(n)$ space. 

 
Applications
- implement efficient priority queue
- sort in place in $O(n\log n)$ time
- constant time extract min (max) in a dynamic environment

## Problem:   


