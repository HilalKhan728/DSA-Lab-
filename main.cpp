//-----------ASSINGMENT---------------
//----------LAB 1 TASKS---------------


//NAME HILAL AHMAD KHAN
//Programme: BS AI(A)
//Submitted to: SIR SHAYAN SHAH
//Date: 27/09/2025

//-------------
//TASK 1
//-------------

//#include <iostream>
//using namespace std;
//
//int main() {
//    // Prices
//    float Espresso = 100.0;
//    float Latte = 200.0;
//    float Capuccino = 250.0;
//
//    // Quantities
//    int Q_E, Q_L, Q_C;
//
//    // Input
//    cout << "Enter the Quantity of Espresso: ";
//    cin >> Q_E;
//
//    cout << "Enter the Quantity of Latte: ";
//    cin >> Q_L;
//
//    cout << "Enter the Quantity of Capuccino: ";
//    cin >> Q_C;
//
//    // Pointers
//    float* ptrEsp = &Espresso;
//    float* ptrLat = &Latte;
//    float* ptrCap = &Capuccino;
//
//    int* ptrQ_E = &Q_E;
//    int* ptrQ_L = &Q_L;
//    int* ptrQ_C = &Q_C;
//
//    // Total calculation
//    float Total = (*ptrEsp * *ptrQ_E) + (*ptrLat * *ptrQ_L) + (*ptrCap * *ptrQ_C);
//
//    // Bill
//    cout << "---------- Cafe Bill ----------\n";
//    cout << "Espresso   (" << *ptrQ_E << " x " << *ptrEsp << " ) = " << (*ptrEsp * *ptrQ_E) << endl;
//    cout << "Latte      (" << *ptrQ_L << " x " << *ptrLat << " ) = " << (*ptrLat * *ptrQ_L) << endl;
//    cout << "Capuccino  (" << *ptrQ_C << " x " << *ptrCap << " ) = " << (*ptrCap * *ptrQ_C) << endl;
//    cout << "-------------------------------\n";
//    cout << "Total = " << Total << endl;
//
//    return 0;
//}

//----------------
//TASK 2
//----------------

#include <iostream>
using namespace std;
// Function to generate the secret code (factorial)
//int generateCode(int n) {
//    if (n == 0) {
//        return 1;   // base case (bonus twist)
//    }
//
//    int result = 1;
//    for (int i = n; i >= 1; i--) {
//        result *= i;
//    }
//    return result;
//}
//
//int main() {
//    int number;
//
//    // Function pointer declaration
//    int (*codePtr)(int);
//
//    // Assign pointer to the function
//    codePtr = generateCode;
//
//    // User input
//    cout << "Enter a number: ";
//    cin >> number;
//
//    // Call function via pointer
//    int secretCode = codePtr(number);
//
//    // Output
//    cout << "Your secret code is: " << secretCode << endl;
//
//    return 0;
//}

//----------------
//TASK 3
//----------------

//#include <iostream>
//#include <cstdlib>   // for malloc() and free()
//using namespace std;
//
//int main() {
//    int numPlayers;
//
//    // Step 1: Ask the user how many players
//    cout << "Enter the number of players: ";
//    cin >> numPlayers;
//
//    // Step 2: Allocate memory dynamically using malloc
//    int* scores = (int*) malloc(numPlayers * sizeof(int));
//
//    // Check if allocation succeeded
//    if (scores == NULL) {
//        cout << "Memory allocation failed!" << endl;
//        return 1; // exit program
//    }
//
//    // Step 3: Take input for all scores
//    cout << "\nEnter the scores for each player:\n";
//    for (int i = 0; i < numPlayers; i++) {
//        cout << "Player " << (i + 1) << ": ";
//        cin >> scores[i];
//    }
//
//    // Step 4: Display the scores back
//    cout << "\n--- Tournament Scores ---\n";
//    for (int i = 0; i < numPlayers; i++) {
//        cout << "Player " << (i + 1) << " scored: " << scores[i] << endl;
//    }
//
//    // Step 5: Release the memory back to the system
//    free(scores);
//
//    return 0;
//}

//-------------
//TASK 4
//-------------

//#include <iostream>
//#include <cstdlib>   
//using namespace std;
//
//int main() {
//    int numParticipants;
//
//    // Ask how many participants
//    cout << "Enter the number of participants: ";
//    cin >> numParticipants;
//
//    if (numParticipants <= 0) {
//        cout << "Please enter a positive number of participants.\n";
//        return 0;
//    }
//
//    // Allocate with calloc -> memory initialized to 0 (all absent)
//    int* attendance = (int*) calloc(numParticipants, sizeof(int));
//    if (attendance == NULL) {
//        cout << "Memory allocation failed!\n";
//        return 1;
//    }
//
//    // Show the initial (clean) attendance — should all be zeros
//    cout << "\nInitial attendance (0 = absent, 1 = present):\n";
//    for (int i = 0; i < numParticipants; ++i) {
//        cout << "Participant " << (i + 1) << ": " << attendance[i] << '\n';
//    }
//
//    // Let user mark some participants as present
//    int presentCount;
//    cout << "\nHow many participants are present? ";
//    cin >> presentCount;
//
//    if (presentCount < 0) presentCount = 0;
//    if (presentCount > numParticipants) {
//        cout << "You asked to mark more participants present than exist. "
//             << "Only the first " << numParticipants << " entries will be accepted.\n";
//        presentCount = numParticipants;
//    }
//
//    cout << "Enter the participant numbers (1 to " << numParticipants << ") who are present:\n";
//    for (int i = 0; i < presentCount; ++i) {
//        int index;
//        cin >> index;
//        if (index >= 1 && index <= numParticipants) {
//            attendance[index - 1] = 1;  // mark present
//        } else {
//            cout << "Invalid participant number: " << index << " (ignored)\n";
//        }
//    }
//
//    // Display final attendance list
//    cout << "\n--- Final Attendance Register ---\n";
//    for (int i = 0; i < numParticipants; ++i) {
//        cout << "Participant " << (i + 1) << ": " 
//             << attendance[i] << "  (" << (attendance[i] ? "Present" : "Absent") << ")\n";
//    }
//
//    // Free memory
//    free(attendance);
//
//    return 0;
//}

