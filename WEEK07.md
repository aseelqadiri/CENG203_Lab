# CENG203 – Week 7 (Heaps & Priority Queues)

`Heap/` contains the max-heap and the priority queue; `Labs/Week07.cpp` contains
the tests and the interactive heap menu. `SHOW_Q4` and `SHOW_Q6` are enabled.

Run option **7** from the main menu. At the end answer **n** to skip the menu,
or **y** to play the session in Q5.

## Key expected output

```
[Q1] parent(4) = 1  leftChild(1) = 3  rightChild(1) = 4
[Q1] parent(1) = 0  parent(2) = 0  parent(0) = 0
[Q1] 20 15 10 4 0  max-heap? true
[Q1] 10 4 15  max-heap? false
[Q1] 9 9 9  max-heap? true
[Q1] 50 30 40 10 20 35  max-heap? true
[Q1] 5 3 4 6  max-heap? false
[Q2] insert 10: swaps = 0  heap: 10
[Q2] insert  4: swaps = 0  heap: 10 4
[Q2] insert 15: swaps = 1  heap: 15 4 10
[Q2] insert 20: swaps = 2  heap: 20 15 10 4
[Q2] insert  0: swaps = 0  heap: 20 15 10 4 0
[Q2] size = 5  valid = true
[Q3] getMax = true  top = 20  size is still 5
[Q3] removeMax = 20: swaps = 2  heap: 15 4 10 0
[Q3] removeMax = 15: swaps = 1  heap: 10 4 0
[Q3] removeMax = 10: swaps = 1  heap: 4 0
[Q3] removeMax =  4: swaps = 0  heap: 0
[Q3] removeMax =  0: swaps = 0  heap: (empty)
[Q3] removeMax on an empty heap = false
[Q6] insert swaps: increasing = 8  decreasing = 0
[Q6] remove swaps: increasing = 3  decreasing = 4
[Q6] n = 1000 increasing: insert swaps = 7987  remove swaps = 6988
[Q6] n = 1000 decreasing: insert swaps = 0  remove swaps = 7317
[Q7] Deniz (priority 9, ticket 3)
[Q7] Berk (priority 5, ticket 1)
[Q7] Ece (priority 5, ticket 4)
[Q7] Ali (priority 2, ticket 0)
[Q7] Cem (priority 2, ticket 2)
[Q7] dequeue on an empty queue = false
```

## Files to add to the Visual Studio project

```xml
<ClCompile Include="Heap\MaxHeap.cpp" />
<ClCompile Include="Heap\PriorityQueue.cpp" />
<ClCompile Include="Labs\Week07.cpp" />
```
```xml
<ClInclude Include="Heap\MaxHeap.h" />
<ClInclude Include="Heap\PriorityQueue.h" />
```

Includes from `Labs\Week07.cpp`: `"../Heap/MaxHeap.h"` and `"../Heap/PriorityQueue.h"`.

Repository: https://github.com/aseelqadiri/CENG203_Lab
Commit message: `Week 7 - heaps`
