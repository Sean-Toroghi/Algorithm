<h1>Hash table; Bloom filter</h1>

__Table of contents__
- [hash tables - short summary](#hashsummary)
- [Hash tables - detail summary](#hashdetail) 
- [Bloom filter - summary](#bloom)

__References__
- [Book - Algorithms Illuminated (Part 2): Graph Algorithms and Data Structures](https://www.algorithmsilluminated.org/)
- [Book - Introduction to Algorithms, fourth edition](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)
- [Course CMU -  Principles of Imperative Computation (Fall 2024)](https://www.cs.cmu.edu/~15122/handouts/lectures/12-hashing.pdf)
- [Course CMU - Algorithm (2024)](https://courses.grainger.illinois.edu/cs473/fa2024/index.html)


__Status__
- [x] active
- [ ] completed
- [ ] updating

__Code__
- [Problems solved by hash table approach](https://github.com/Sean-Toroghi/Algorithm/blob/e3819391785d981dee93978d3dcb88084c9e2e8d/DataStructure/HashTables/HashTables.ipynb)



---



# Overview and short summary<a id='hashsummary'></a>

One of the most useful and ubiquitous data structures is hash tables. The most useful application of hash tables is the case of _fast search_. It is very useful in the case of evolving set of objects that also require fast lookup.

## Operation
- Lookup - expected $O(1)$
- Insert - $O(1)$
- Delete - expected $O(1)$

A good implementation of a hashtable (which is in most cases an impossible thing, no matter what, there will be an adversary who could crack down the hashtable) has constant time Lookup() and Delete() operations.


## Implementation

The main issue with hash table implementation is finding a strategy to map objects to keys in the hash table, with a minimum number of collisions. In the worse case, all objects will be mapped to a single key at which the hash table becomes a linked-list with time complexity of $O(n)$ for the operations. 

## Hash functon
Hash function is responsible for mapping the keys from the Universe (a very large set of keys, so we could assign a unique key to each object in the Universe) to a position (index) in the hash table (array). Since the size of the hash table is much smaller than the size of the Universe, the hash function provides a pointer to indicate where is a good starting point for searching for a key in the hash table (lookup function). 

## Address collision
No matter how good a hash function is, we will encounter collisions (assigning more than one key to a single position in the hash table). In the case of a collision occurs, two mitigation options are 1. chaining, and 2. open addressing. 

The chaining solution creates a linked-list in the case of a collision and stores those keys that are pointed at the same location in the linked-list. However, in the worse case, we may encounter the situation that hash function maps all keys to the same position, resulting in the creation of a linked-list with the size of input data.

The open-addressing approach, suggests conducting a new mapping, each time a collision occurs, until the hash function can not find any free space in the hash table. There are several methods for implementing open addressing, among which here are some:
- Linear probing: One simple approach is to look for the next free spot in the hash table. This method employs a flogger if we delete an item from the table, to indicate the spot was previously occupied. This is needed for returning the correct value when running lookup in the future.
- Double hashing: in this approach, if collision occurs, the algorithm uses a different hash function, from a set of hash functions.

## Load factor
The performance of a hash table drops as the population of input data increases. _Load factor_ is defined as the ratio of the size of data we want to store to the size of the hash table we define to store it is an indicator for managing and maintaining the performance of the hash table. Once we reach a threshold, we need to start storing the data in a new table, or regenerate the hash table with a larger table size. 

A good threshold for load factor is 70%. Once the load factor reaches the threshold, the algorithm requires to resize the table size, in order to maintain expected linear time for operations (lookup). 



## Design a good hash table
To design a high-performing hash function, we need to consider several factors:
- a good threshold for load factor, and maintain it though the life of the algorithm. For example, once reaching  the threshold, we can double the size of the table. Also, we can define a lower band threshold to downsize the table, to avoid keeping a sparse array.
- a good hash function is also a decisive factor. There are several implementations of hash functions, such as _FarmHash_, _MD5_, _SpookyHash_, and _MurmurHash_.
- An effective strategy to handle the collision is also an important factor for designing a high-performing hash function.







---
# Hash tables - detail summary<a id='hashdetail'></a>

A hash table (or hash map) is a data structure for storing a set of items, so that we can quickly determine whether an item is or is not in the set. Dictionary (also called map or associate array), is an primitive data structure that maps its values to indices called keys. To implement a dictionary, we can simply employ linkedlist, which $O(n)$ time to lookup for a key. A sorted array takes $O(\log n)$ to find a key (BTS algorithm). Implementing a dictionary that takes constant for lookup requires employ hashing. Two important concepts comes with hashing are: average case complexity and randomness. The time complexity is average with hash table and while its behaviour is deteministic, but there is randomness inside the hash function implementation.

The basic idea is to pick a hash function h that maps every possible item x to a small integer h(x). Formaly given universe $\mathbb{U}$ of size $u$, and array $T$ of size $m$ called hash table, where $m<<u$, hash function maps each item in universe to an index the hash table: 

$$h: \mathbb{U}\rightarrow \\{1, 2,\dots, m-1 \\}$$

In this case, an array is a special form of a hash table, in which $u=m$. It is also called _direct access table_. The main idea for using hash table, is inmost cases we do not store all items in a universe. Hense, the data structure needs to store a portion of the items (actualy needed to store vs probably need to store) in the universe. This makes the hash function feasible for mapping item in universe to a smaller size array called hash table. The upside is we can then employ the hash function for lookup in average constant time. The issue arrise when collion occurs, in which more than one item in the universe is assigned to an index in the hash table: $h(x) = h(y)$. This leads to two important design decisions:
- how to define a hash function to minimize risk of collision
- if collision occurs, how to handle it that minimizes its effect on the model performance (time complexity)

## Hash function: randomness, unform, universal, near-universal, and k-uniform

- __Randomness__

  Randomness becomes handy when it comes to design a hash function. If we design a predictable hash function, an adversery will take advantage of it by introducing inputs that always return the same position in hash table. We can introduce randomness in hash function as following: 
  - fix a set of hash functions $\mathbb{H}$ that all could map universte to hash table of size m
  - at runtime, for each hash table choose a hash function randomly from $\mathbb{H}$ and use it for the life of that hash table.
  - each hash table uses its own hash function that is independent of the other hash functions


- __Uniform hash function__

  A family $\mathbb{H}$ of hash functions is _uniform_ if choosing a hash function uniformly at random from $H$ makes every hash value equally likely for every item in the universe:

$$Pr( h(x) = i) = \frac{1}{m}  \quad \forall x \in H$$

  However, this property does not work! A constant function that maps universe tto a constant value $a$ in hash table, while the probaiblity of mapping to location $a$ is
  $\frac{1}{m}$, but it is not a good hash function. 

- __Universal hash function__
  
   A family of hash  functions is universal if, for any two items in the universe, the probability of collision is as small as possible:

$$Pr( h(x) = h(y)) \leq \frac{1}{m}  \quad \forall x \neq y $$
   
   This consition minimizes number of collisions. However, this is an ideal consition, and for most cases a near universal hash function provides sufficient performance guarantees.

- __Near universal hash function__

  A family of hash  functions is _near-universal_ if, for any two items in the universe, the probability of collision holds the followng constrain:

$$Pr( h(x) = h(y)) \leq \frac{2}{m}  \quad \forall x \neq y $$

- __strongly k-universal or k-uniform hash function__

  A family of hash functions is _strongly k-universal or k-uniform_ if for any sequence  of k disjoint keys and any sequence of k hash values, the probability that each key maps to the  corresponding hash value is $\frac{1}{m^k}$:

$$pr\[ \bigwedge h(x_j) = i_j\] = \frac{1}{m^k} \quad \forall \text{  distinct  } x_j \quad \forall i_j $$


## Mitigate collision

### Chaining
One option for mitigating collision is chaining, by storing colide items as a linked-list. The expected length of the linked-list is the governing factor for lookup running time, and is at most $\frac{n}{m}$. For _newar-univeral_ hash function this ratio (called load factor needs to be at most 2. As long as the number of items n is only a constant factor bigger than the table size m, the search time is a constant. 

### Open addressing
Open addressing is another metod for resolving collision, by looking elsewhere in the table. This method employs a set of hash function, in which for an imput $x$, they each map a different location in the hash table. Then the lookup function iterates through all the mapped locations, and returns index, if it could find the item in any of those locations in hash table, or None if it could not find the item in any of the mapped locations in the hash table.  

## Design a hash function

### Multiplicative hashing
Multiplicatie hashing is a imple hash function that achieves either near-universal hashing or universal hashing, first introduced by Lawrence Carter and Mark Wegman in the late 1970s. Among many varients of this hash function, two widely use ones are: 1- using modular arithmetic with prime numbers, 2- using modular arithmetic with powers of two. To perform this method we need to set up the folowings:
- For a non negative integer $n$, define two sets: $set(n) = \\{0,1,\dots, n-1 \\}$ and $set(n^+) = \\{1,2,\dots, n-1\\}$.
- Define a random integer $a$, called _salt_, which is assigned to a hash table and remain the same for that hash table for the life of the table.

  Given a prime number $p$ larger than the size of universe ($p>|U|$), $a \in \[p\]^+$

- Define a random integer $b$, which is assigned to a hash table and remain the same for that hash table for the life of the table.

  Given a prime number $p$ larger than the size of universe ($p>|U|$), $a \in \[p\]$

__Muiltiplicative hash function - using modular arithmetic with prime numbers Version 1 - near-universal hashing__, mapping universe to hash table of size $m$:

  $$h_{multiplicative, a, p}(x) =  (ax \mod p)\mod m$$

  To proove this hash function satisfies near-universal hashing requirement, we first proove there exist a unique value $z$ for a given value $a$ that hold this equality: $(az \mod p) = 1$. Second step is to proove, for two input values $x,y$, collision occurs only if either:
  - $x=y$, or
  - $h_{multiplicative, a, p}((x − y) \mod p)=0$, or
  - $h_{multiplicative, a, p}((y - x) \mod p)=0$
 
  Finaly we need to proove for any integer $z\in \[p\]^+$, $Pr_a\[h_{multiplicative, a, p}\] \leq \frac{1}{m}$
  
__Muiltiplicative hash function - using modular arithmetic with prime numbers Version 2 - universal hashing__

With a small modification to version 1, the following hash function satisfies _universal hashing_ requirement:

$$h_{multiplicative, a, ,b, p}(x) =   ((ax + b) \mod p)\mod m$$



__Muiltiplicative hash function -  using modular arithmetic with powers of two - near-universal hashing__

Binary multiplicative hashing is a slightly simpler variant of multiplicative hashing, by avoiding the need for large prime numbers and was first proposed by 
Martin Dietzfelbinger, Torben Hagerup, Jyrki Katajainen, and Martti Penttonen in 1997. To simsplify the problem without loosing generalizty, assuming universe $U$ is a list of w-bits ($U = \[2^w\]$) and the hash table is a smaller set of l-bits integers of size ($m = \[2^l\]$). The goal is to map universe (words) to l-bit integer (labels). 

To set up the hash function, we need to define _salt_ as following:
- pick a random odd integer $a \in \[2^w\]$ 

And the hash function is defined as:

$$h_{multiplicative, a}(x) := \frac{(a·x)\mod2^w}{2^{w-l}}$$

To proove this hash function satifies near-univeral hashing requirement, we proove for any integer $x,z \in w$, there is exactly one integer $a \in w$ that such that $x \mod 2w = z$, then use the lemma to prove it is a near-universal hashing.

### Probing (linear, binary, quadratic) and double hashing

__Linear probing__ hash function is designed based on the concept of _open addressing_, $h_i(x) := (h(x)+i) \mod m$. __Advantages__ of linear probing are: 1. probing strategy visits consecutive entries in the has table, result in better cache performance than other strategies, and 2. with load factor less than 1,  the expected length of any probe sequence is constant.

__Binary probing__ is a simpler version of linear probing, is binary probing: $h_i(x) := h(x)⊕i$. Here we assume $m=2^l$, and ⊕ denotes bitwise exlusive-or.

__Quadratic probing__ uses a single hash function h and set has function as follow: $h_i(x) := (h(x)+i^2)\mod m$.

__Double hashing__ use two hash functions h and h′ to define the hash function:  $h_i(x) := (h(x)+i ·h′(x)) \mod m$.

---
# Bloom filter<a id='bloom'></a>

