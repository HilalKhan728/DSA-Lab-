                                  CHEAT SHEET (STUDENT GUIDE) 

Name: Hilal Ahmad Khan
Programme: BS AI
Group: A
Teacher: Sir Shayan Ali Shah

1️⃣ BST Structure Overview

Each Node stores:

Node {
    rating : int   // Key
    name   : string
    hp     : long long
    left   : Node*
    right  : Node*
    sz     : int   // Subtree size
}


BST Invariant:

Left subtree < Node rating < Right subtree


Example BST:

         5
       /   \
      3     8
     / \   / \
    2   4 6   9


sz for node 5 = 7

sz for node 3 = 3

2️⃣ Key Operations (with diagrams)
a) JOIN / LEAVE

JOIN 7 on the above tree:

         5
       /   \
      3     8
     / \   / \
    2   4 6   9
             \
              7


Prints JOINED

Duplicate rating → DUPLICATE

LEAVE 8:

Node 8 has two children → replace with in-order successor (9)

         5
       /   \
      3     9
     / \   / 
    2   4 6  
             \
              7


Prints LEFT

b) STATUS / DAMAGE / HEAL

STATUS 3 → prints 3 name hp

DAMAGE 3 2 → reduces HP:

3 HP = max(0, HP - 2)


HEAL 6 5 → increases HP:

6 HP = HP + 5

c) NEXT / PREV

NEXT 5: Smallest rating > 5 → 6
PREV 5: Largest rating < 5 → 4

Tree:
         5
       /   \
      3     8
     / \   / \
    2   4 6   9

NEXT(5) → 6
PREV(5) → 4

d) MATCH

Find closest-rated opponent to X = 5:

Predecessor = 4

Successor = 6

Distances: |5-4|=1, |6-5|=1 → tie → choose lower rating (4)

Output: 4 name hp

e) RANGE L R

Print all players with rating in [3,7]:

         5
       /   \
      3     8
     / \   / \
    2   4 6   9
             \
              7


In-order traversal → 3,4,5,6,7

Prints:

3 name hp
4 name hp
5 name hp
6 name hp
7 name hp

f) RANK / KTH

RANK X → number of players < X

Example: RANK 6 → count nodes with rating < 6 → 5

KTH k → k-th smallest rating

Example: KTH 4 → rating = 5

g) STATS

HEIGHT: Max edges from root to leaf (empty = -1)

LEAVES: Nodes with no children

MIN / MAX: Leftmost / Rightmost nodes

h) DUEL

Distance between A = 2 and B = 7:

Find LCA (Lowest Common Ancestor): 5

Depth(A) = 2, Depth(B) = 3

DIST = depth(A) + depth(B) - 2 * depth(LCA)

DIST = 2 + 3 - 2*1 = 3

3️⃣ Input / Output Example

Input:

12
JOIN 5 ALI 50
JOIN 3 BILAL 30
JOIN 8 ZAIN 80
STATUS 3
DAMAGE 3 10
HEAL 5 20
NEXT 5
PREV 5
MATCH 6
RANGE 3 8
DUEL 3 8
STATS


Output:

JOINED
JOINED
JOINED
3 BILAL 30
DAMAGED 20
HEALED 70
8 ZAIN 80
3 BILAL 20
5 ALI 70
3 BILAL 20
5 ALI 70
8 ZAIN 80
DIST 3
HEIGHT 2
LEAVES 3
MIN 3
MAX 8

4️⃣ Programming Notes

Use sz for RANK/KTH → efficient O(h)

Strict inequality for NEXT/PREV

Tie-breaking in MATCH → choose lower rating

Deletion with 2 children → replace with in-order successor

Height / Leaves recursive computation

Fast I/O: ios::sync_with_stdio(false); cin.tie(nullptr);
