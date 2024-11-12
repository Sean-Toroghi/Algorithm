<h1>Hash table; Bloom filter - summary</h1>

[Codes]()

# Overview
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

---
# Bloom filter

## Design a good hash table
To design a high-performing hash function, we need to consider several factors:
- a good threshold for load factor, and maintain it though the life of the algorithm. For example, once reaching  the threshold, we can double the size of the table. Also, we can define a lower band threshold to downsize the table, to avoid keeping a sparse array.
- a good hash function is also a decisive factor. There are several implementations of hash functions, such as _FarmHash_, _MD5_, _SpookyHash_, and _MurmurHash_.
- An effective strategy to handle the collision is also an important factor for designing a high-performing hash function.

