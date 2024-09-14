<h1>Dynamic programming - summary and notes</h1>

References
- [Algorithm course - Stanford](https://online.stanford.edu/courses/soe-ycs0011-greedy-algorithms-minimum-spanning-trees-and-dynamic-programming)
- [Algorithm course - MIT](https://ocw.mit.edu/courses/6-046j-design-and-analysis-of-algorithms-spring-2015/video_galleries/lecture-videos/)
- [Algorithm - UIUC](https://courses.grainger.illinois.edu/cs473/fa2024/lectures.html)
- [Advance algorithm - CMU](https://www.cs.cmu.edu/afs/cs.cmu.edu/academic/class/15850-s23/www/oldindex.html)
- [book: Introduction to Algorithms, Fourth Edition - Ch.14](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)

__Table of contents__
[Summary - Notes](#summary)
- Overview
- Problem: Longest common subsequence
- Problem: Longest increasing subsequence
- Problem:  

__Codes__
- 1D dynamic programming [link](https://github.com/Sean-Toroghi/Algorithm/blob/cff510dccdddfb03256bd595d2387a5c10db0e10/DynamicProgramming/DynamicProgramming_1Dim.ipynb)
- nD dynamic programming
 



# <a name = 'summary'>Dynamic programming - Note and sumamry</a>

Dynamic programming approach requires to have the following two:
1. optimal sub-structure
2. overlapping subproblems

__Optimal sub-structure__
- the solution of a problem requires to make a choice leading to one or more subproblems to be solve.
- the choice leads to optimal solution.
- given the choice, the next task is to determine which subproblems ensue
- solution to each subprolem is by itself an optimal solution

__Overlapping subproblems__
- the concept of over-lapping subproblems gives the dynamic programming possibility of employ memoization. This leads to its efficient implementation.
- the recursive algorithm in dynamic progamming is not efficient, however the ability of memoizing the overlapping subprolem makes it efficnet.


## Problem: Longest common subsequence
Given a sequence $X = \\{x_1; x_2; ... ; x_m \\}$, another sequence $Z = \\{z1; z2; ... ; z_k \\}$ is a subsequence of $X$ if there exists a strictly increasing sequence $\\{i_1; i_2; ... ; i_k \\}$ of indices of $X$ such that for all $j = \\{ 1; 2;  : : ; k\\}$ we have $x_{i_j} = Z_j$ .

Given two sequences $X$ and $Y$, we say that a sequence Z is a common subsequence of $X$ and $Y$ if $Z$ is a subsequence of both $X$ and $Y$. The goal is to find the longest $Z$.

