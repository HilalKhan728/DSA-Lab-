🏥 **ER Patient Management System (Doubly Linked List)**

---

### 📌 **Overview**

This project implements an **Emergency Room (ER) Patient Management System** using a **Doubly Linked List (DLL)** in C++.
Each patient is represented as a node containing a unique **patient ID**, and the system manages a queue that prioritizes patients based on their condition:

* **Critical patients** are added to the **front** of the queue.
* **Normal patients** are added to the **end** of the queue.
* Patients can also be inserted at **specific positions** in the list.
* **Treated patients** are removed from the **front** (simulating treatment completion).

This approach effectively models the **priority handling mechanism** of a real-world emergency room.

---

### 🧠 **Concepts Used**

* **Doubly Linked List** (with `prev` and `next` pointers)
* **Dynamic Memory Allocation**
* **Object-Oriented Programming (Classes and Methods)**
* **Menu-Driven Program Structure**

---

### 🧩 **Features**

✅ Add a **critical patient** at the beginning
✅ Add a **normal patient** at the end
✅ Add a **patient at a specific position**
✅ Remove a **treated patient** from the beginning
✅ **Display** the current ER queue (forward traversal)

---

### 🧱 **Data Structure**

```cpp
struct Node {
    int patientID;
    Node* next;
    Node* prev;
};
```

* `next` → Points to the next patient in the queue
* `prev` → Points to the previous patient in the queue

---

### ⚙️ **Class Definition**

| **Function Name**        | **Description**                             |
| ------------------------ | ------------------------------------------- |
| `addFront(int id)`       | Add a critical patient at the beginning     |
| `addEnd(int id)`         | Add a normal patient at the end             |
| `addAt(int id, int pos)` | Add a patient at a specific position        |
| `removeFront()`          | Remove the first (treated) patient          |
| `display()`              | Display all patients currently in the queue |

---

### 💻 **Menu (Main Program)**

```
=== ER Patient Management System ===

1. Add critical patient at beginning
2. Add normal patient at end
3. Add patient at specific position
4. Remove treated patient from beginning
5. Display all patients
6. Exit

Enter your choice (1-6):
```

---

### 🧮 **Example Run**

**Input:**

```
1
Enter patient ID: 200
2
Enter patient ID: 101
2
Enter patient ID: 102
3
Enter patient ID: 150
Enter position: 2
5
4
5
6
```

**Output:**

```
Critical patient added. Updated ER Queue: 200
Normal patient added. Updated ER Queue: 200 <-> 101
Normal patient added. Updated ER Queue: 200 <-> 101 <-> 102
Patient added at position 2. Updated ER Queue: 200 <-> 150 <-> 101 <-> 102
Current ER Queue: 200 <-> 150 <-> 101 <-> 102
Patient Treated: 200
Updated ER Queue: 150 <-> 101 <-> 102
Thank you for using the ER Management System. Exiting...
```

---

### 🔍 **Dry Run Example**

**Initial State:**
Empty list → `head = nullptr`, `tail = nullptr`

**Operations:**

```
addEnd(101)
addEnd(102)
addFront(200)
addAt(150, 2)
removeFront()
addEnd(300)
```

**Final List:**

```
head → [150] <-> [101] <-> [102] <-> [300] ← tail
```

**Results:**

* (a) **Head = 150**
* (b) **Tail = 300**
* (c) **Forward:** 150 → 101 → 102 → 300
* (d) **Backward:** 300 → 102 → 101 → 150

---

### 🧾 **How to Compile and Run**

**Using Terminal / Command Prompt:**

```
g++ ERQueue.cpp -o ERQueue
./ERQueue
```

**Using Code::Blocks or Dev-C++:**

1. Create a new C++ project.
2. Paste the code into the main file.
3. Build and run the program.

---

### 🧑‍💻 **Author**

**Name:** *Hilal Ahmad Khan*
**Course:** Data Structures (C++)
**Instructor:** *Sir Shayan Ali Shah*
