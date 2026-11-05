# CENG203 – Lab Worksheet #6 (Trees & BSTs)

## What is here

- `Lab Worksheet 6 - COMPLETED.docx` – the worksheet with every written answer and every table filled in.
- `CENG203_Lab6/` – the complete, compilable source code (Part B).

```
CENG203_Lab6/
├── main.cpp
├── Labs/
│   ├── Labs.h
│   └── Week06.cpp
└── Tree/
    ├── TreeNode.h
    ├── TreeUtils.h / TreeUtils.cpp
    ├── BST.h / BST.cpp
    └── ExpressionTree.h / ExpressionTree.cpp
```

## Expected program output (menu option 6)

```
--- Week 6: Trees and Binary Search Trees ---
[Q2] preorder : 1 2 4 5 3 6
[Q2] inorder  : 4 2 5 1 3 6
[Q2] postorder: 4 5 2 6 3 1
[Q2] nodes = 6  leaves = 3
[Q3] height(root) = 2  height(node 4) = 0  height(empty) = -1
[Q3] level order: 1 2 3 4 5 6
[Q4] insert(10) again = false
[Q4] inorder  : 3 5 7 10 12 15 20
[Q4] preorder : 10 5 3 7 15 12 20
[Q4] postorder: 3 7 5 12 20 15 10
[Q5] find(7) = true  find(8) = false
[Q5] min = 3  max = 20
[Q6] height = 2  balanced = true
[Q6] chain 1..5: height = 4  balanced = false
[Q6] chain preorder: 1 2 3 4 5
[Q7] remove(3) leaf       : 5 7 10 12 15 20
[Q7] remove(5) one child  : 7 10 12 15 20
[Q7] remove(10) two kids  : 7 12 15 20
[Q7] preorder now: 12 7 15 20
[Q7] remove(99) = false
[Q8] prefix : * + 3 4 - 5 2
[Q8] postfix: 3 4 + 5 2 - *
[Q9] infix  : ((3 + 4) * (5 - 2))
[Q9] value  = 21
[Q9] infix  : (8 / (2 - 2))
[Q9] Error: Division by zero
```

## Using it inside your own Visual Studio project

If you already have `C:\CENG203\CENG203_Lab`, copy the files into the same folders
(`Tree\`, `Labs\`), then add to your existing `Labs\Labs.h`:

```cpp
void runWeek06();
```

and to your existing `main.cpp` menu / switch:

```cpp
cout << " 6. Week 6 - Trees and BSTs" << endl;
...
case 6:  runWeek06(); break;
```

Finally add the new files to the project (Show All Files → right-click → Include In Project)
or add these lines to `CENG203_Lab.vcxproj` inside the `<ItemGroup>`:

```xml
<ClCompile Include="Labs\Week06.cpp" />
<ClCompile Include="Tree\TreeUtils.cpp" />
<ClCompile Include="Tree\BST.cpp" />
<ClCompile Include="Tree\ExpressionTree.cpp" />
```

```xml
<ClInclude Include="Tree\TreeNode.h" />
<ClInclude Include="Tree\TreeUtils.h" />
<ClInclude Include="Tree\BST.h" />
<ClInclude Include="Tree\ExpressionTree.h" />
```

Build with Ctrl+Shift+B until the Output window says `1 succeeded`, then run with Ctrl+F5.

## Before you submit

- Put your **name, student number and signature** on the cover table of the .docx.
- Put your **repository URL** in the last answer (Q10 e).
- Commit and push with the message: `Week 6 - trees`.
