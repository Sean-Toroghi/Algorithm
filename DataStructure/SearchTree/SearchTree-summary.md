<h1>Search tree</h1>

## Overivew

Binary search tree is a simple and fast data structure suitable to store evolving data (dynamic). It is basically an enhanced version of sorted array, in which the two operation _Insert()_ and _Delecte()_ can be run much faster. This makes it suitable for the case in which the data keeps updating. The downside is some of the operations is a bit slower than the sorted array data structure.

## BST properties
Binary search tree has the following two properties:
- all the sub-trees on the left of each node have values less than the node
- all the sub-trees on the right of each node have value larger than the node

## Main operation

- Insert()                 - $O(\log n)$
- Delete()                 - $O(\log n)$
- Search()                 - $O(\log n)$
- Min/Max()                - $O(\log n)$
- Predecessor/Successor()  - $O(\log n)$
- Select()                 - $O(\log n)$
- Rank()                   - $O(\log n)$
The ReturnSorted() also require $O(n)$ time to run.

## Balanced search tree and its variants
 
The binary search tree does not guarantee fast operation, unless it is a balanced version. The operations mentioned for this data strcutre require $O(\text{Tree's height})$ and a balanced tree will guarantee $O(\log n)$.

There are several approaches to maintain balance requirement for the binary search tree, including Red-Black and ALV. Also there are some additional variant of BST, such as Treap which  satisfies both properties of Heap and BST.



