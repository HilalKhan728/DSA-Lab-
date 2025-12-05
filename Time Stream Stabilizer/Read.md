Author: Hilal Ahmad Khan
BS AI (A)
Istructor: Sir Shayan Ali Shah


📜 C++ Concepts Overview in the Time-Stream Stabilizer
This project utilizes several fundamental C++ concepts to build a robust and efficient Binary Search Tree (BST), which models our chronological timeline. Understanding these concepts is essential for working with the code.

1. ⚙️ Core Data Structures
A. Structures (struct)
The TimeCapsule is defined as a struct, which is a custom data type used to bundle related information together.

Usage: A TimeCapsule holds the key (year), the associated data (eventName), and the pointers to its child nodes (left and right). This represents a single event in the timeline.

B. Classes (class)
The TimeTree is defined as a class, which encapsulates the data (the root pointer) and the methods (functions) that operate on that data (inject, resolveParadox, etc.).

Usage: The TimeTree manages the entire timeline and enforces the rules of the BST.

C. Pointers (*) and Dynamic Memory Allocation (new, delete)
Pointers are variables that store the memory address of other variables. This is crucial for building linked data structures like trees.

Usage:

TimeCapsule* left; and TimeCapsule* right; are pointers that link nodes together to form the tree structure.

The new keyword is used in the constructor and insertHelper to dynamically allocate memory for new TimeCapsule nodes on the heap.

The delete keyword is used in deleteHelper and the destructor (destroyTree) to explicitly release the memory occupied by nodes when they are removed, preventing memory leaks.

2. 🧠 Object-Oriented Programming (OOP) Principles
A. Encapsulation (Private/Public)
Encapsulation is the bundling of data (attributes) and the methods (behaviors) that operate on the data into a single unit (the class), and restricting direct access to some of the object's components.

private: Used for the internal data (root) and helper functions (insertHelper, deleteHelper, etc.). Users outside the class cannot directly modify the tree's internal structure, ensuring data integrity.

public: Used for the main interface commands (inject, report, search). These are the only ways to interact with the timeline.

B. Constructors and Destructors
These are special member functions that manage the lifecycle of an object.

Constructor (TimeTree()): Initializes the TimeTree object, setting the root pointer to nullptr (an empty timeline).

Destructor (~TimeTree()): Executed when the TimeTree object is destroyed. It calls the destroyTree helper to recursively deallocate all nodes, ensuring clean memory usage.

3. 🔁 Algorithmic Techniques
A. Recursion
Recursion is an algorithmic technique where a function calls itself to solve smaller subproblems until a base case is reached. This is the natural way to process tree structures.

Usage: All core operations (insertHelper, deleteHelper, reportHelper, searchHelper) are implemented using recursion. For example, to inject an event, the insertHelper checks the current node and then calls itself on the left or right child, effectively traversing the tree one step at a time.

Example (In-Order Traversal): The reportHelper calls itself first on the left child, then processes the current node, then calls itself on the right child. This ensures a perfectly sorted, chronological output.

B. Standard Library Headers (<string>, <limits>)
While not tree-specific, standard library components enhance the functionality and safety of the program.

<string>: Used to handle the eventName data type.

<limits>: Used in the main loop to access std::numeric_limits to reliably clear the input buffer and prevent program crashes from malformed console input.
