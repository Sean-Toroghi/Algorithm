# Core algorithms


--- 

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


  
