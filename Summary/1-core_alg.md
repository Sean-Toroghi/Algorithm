# Core algorithms


--- 

## General

__Algorithm design phase__

1. The design phase: In the design phase, the architecture, logic, and implementation details of the algorithm are envisioned and documented. At this phase both accuracy and performance are objectives, and the outcome of this phase is more than one candidate algorithm.
2. Coding phase converts the designed algorithm into a program.
3. Implement/deploy, which requires to design a production environment for the code to be run at. For data-intensive algorithms, a data ingress pipeline and the strategy to cache and store data may need to be designed.

__Fine-tune algorithm__
- Does the alg. generate the expected results?
- Is the alg. in hand, the most optimal approach?
- Does the alg. perform the same in a real world scenario (larger dataset, adverserial attack, edge cases, ...)

Design of an algorithms requires to satisfy both functional (exact required specification and expected features) and non-functional (preformance, scalability, usability, and accuracy) requirements.


__Analyze algorithm__
- space complexity: runtime memory requirements 
- time complexity: time the alg. will take to run

| Complexity Class | Name        | Example Operations                    |
|------------------|-------------|---------------------------------------|
| O(1)             | Constant    | Append, get item, set item.           |
| O(logn)          | Logarithmic | Finding an element in a sorted array. |
| O(n)             | Linear      | Copy, insert, delete, iteration       |
| O(n^2)            | Quadratic   | Nested loops                          |

---

__Algorithm types__

Algorithm categorized, in gneeral, into following two categories:
1. detrministic: a particular input, always generates exactly the same output
2. randomized: the randomization characteristic of the algorithm generates slightly different output for the same input.

--- 

## Data structure

Data structure plays a crusial role in developing an algorithm efficiently. Dependung on wwhether an algorithm has a specific logic (such as recursive or iterative), the data structure specifically designed for that logit is required when implementing it. 

---

__python built in data structures__

| Data Structure | Brief Explanation                                         | Example                              |
|----------------|-----------------------------------------------------------|--------------------------------------|
| List           | An ordered, possibly nested, mutable sequence of elements | ["John", 33,"Toronto", True]         |
| Tuple          | An ordered immutable sequence of elements                 | ('Red','Green','Blue','Yellow')      |
| Dictionary     | An unordered collection of key-value pairs                | {'brand': 'Apple', 'color': 'black'} |
| Set            | An unordered collection of elements                       | {'a', 'b', 'c'}                      |

---

__Other data structures__

__Stack__
- follows LIFO or FILO
- operations
  - push $O(1)$
  - pop $O(1)$

_Queue__
- follows FIFO
- operations
  - dequeue $O(1)$
  - enqueue $O(1)$

---
__Trees__

__Types of trees__
- Binary tree
- Full tree: every node has either zero or two children
- Perfect tree: A perfect tree is a special type of full tree in which all the leaf nodes are at the same level. 
- Ordered tree:  If the children of a node are organized in some order according to particular criteria, the tree is called an ordered tree.
 
---
## Sort and search algorithms

