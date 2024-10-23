//
//   CSAcademy Problem - Rigged Dice
//   From: IEEEXtreme 15.0
//   Solved By: Dimitrios and Petros Papakonstantinou
//   Submission Score: 100/100 (180ms - 780KB)
//

#include <algorithm> // For std::count
#include <iostream>  // For input/output
#include <sstream>   // For string stream to parse input
#include <string>    // For std::string
#include <vector>    // For dynamic arrays (std::vector)

int main(void) {
  int game_num;

  // Read the number of games
  std::cin >> game_num;
  std::cin.ignore(); // Consume the newline character after the integer input

  // Loop through each game
  for (int game = 0; game < game_num; ++game) {
    int n;

    // Read the number of rounds for the current game
    std::cin >> n;
    std::cin.ignore(); // Consume the newline character after the integer input

    // Vectors to store Alice's and Bob's dice rolls
    std::vector<int> d1, d2;
    int alice_total = 0,
        bob_total = 0; // Track the total score for Alice and Bob
    bool current_alice_die1 =
        true; // Flag to track whose roll goes to which die

    // Process each round of dice rolls
    for (int i = 0; i < n; ++i) {
      std::string line;
      std::getline(std::cin,
                   line); // Read the entire line of input for the current round

      std::istringstream iss(line); // Create a string stream to parse the input
      int alice, bob;
      iss >> alice >>
          bob; // Extract Alice's and Bob's dice rolls from the input

      // Update the total scores for Alice and Bob
      alice_total += alice;
      bob_total += bob;

      // Assign rolls based on the current die assignment
      if (current_alice_die1) {
        d1.push_back(alice); // Alice's roll goes to d1, Bob's roll to d2
        d2.push_back(bob);
      } else {
        d2.push_back(alice); // Switch roles: Alice's roll to d2, Bob's to d1
        d1.push_back(bob);
      }

      // If Alice and Bob's total scores differ, toggle the die assignment for
      // the next round
      if (alice_total != bob_total) {
        current_alice_die1 = !current_alice_die1; // Switch dice assignment
      }
    }

    // Count the number of sixes in both dice arrays
    int d1_count =
        std::count(d1.begin(), d1.end(), 6); // Count sixes in Alice's die (d1)
    int d2_count =
        std::count(d2.begin(), d2.end(), 6); // Count sixes in Bob's die (d2)

    // Determine the winner: whoever has more sixes
    if (d1_count > d2_count) {
      std::cout << "1" << std::endl; // Print "1" if Alice (d1) has more sixes
    } else {
      std::cout << "2" << std::endl; // Print "2" if Bob (d2) has more sixes
    }
  }

  return 0; // Exit the program successfully
}
