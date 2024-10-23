//
//   CSAcademy Problem - Rigged Dice
//   From: IEEEXtreme 15.0
//   Solved By: Dimitrios and Petros Papakonstantinou
//   Submission Score: 100/100 (112ms - 776KB)
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000   // Maximum length for an input line
#define MAX_ROUNDS 1000 // Maximum number of rounds in a game

// Function to count the number of sixes in a given array
int count_sixes(int *arr, int size) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == 6) // If the value is 6, increment the count
      ++count;
  }
  return count; // Return the total count of sixes
}

int main(void) {
  int game_num;

  // Read the number of games
  if (scanf("%d", &game_num) != 1) {
    // Error handling if reading game number fails
    fprintf(stderr, "Error reading number of games\n");
    return 1; // Return non-zero to indicate an error
  }
  getchar(); // Consume the newline after the number input

  // Loop through each game
  for (int game = 0; game < game_num; ++game) {
    int n;

    // Read the number of rounds for the current game
    if (scanf("%d", &n) != 1) {
      // Error handling if reading the number of rounds fails
      fprintf(stderr, "Error reading number of rounds\n");
      return 1; // Return non-zero to indicate an error
    }
    getchar(); // Consume the newline after the number input

    // Arrays to store Alice's and Bob's dice rolls
    int d1[MAX_ROUNDS], d2[MAX_ROUNDS];
    int d1_size = 0, d2_size = 0; // Sizes of Alice's and Bob's roll arrays
    int alice_total = 0,
        bob_total = 0;          // Track the total scores for Alice and Bob
    int current_alice_die1 = 1; // A flag to alternate the die assignments

    char line[MAX_LINE]; // Buffer for reading each line of input

    // Process each round
    for (int i = 0; i < n; ++i) {
      // Read a line from input (containing Alice's and Bob's rolls)
      if (fgets(line, sizeof(line), stdin) == NULL) {
        // Error handling if reading the input fails
        fprintf(stderr, "Error reading input\n");
        return 1; // Return non-zero to indicate an error
      }

      int alice, bob;
      // Parse the input line into two integers (Alice's and Bob's dice rolls)
      if (sscanf(line, "%d %d", &alice, &bob) != 2) {
        // Error handling if parsing the line fails
        fprintf(stderr, "Error parsing input\n");
        return 1; // Return non-zero to indicate an error
      }

      // Update the total scores for Alice and Bob
      alice_total += alice;
      bob_total += bob;

      // Depending on the flag, assign rolls to different dice sets
      if (current_alice_die1) {
        d1[d1_size++] = alice; // Alice's roll goes to d1, Bob's roll to d2
        d2[d2_size++] = bob;
      } else {
        d2[d2_size++] = alice; // Swap roles: Alice's roll to d2, Bob's to d1
        d1[d1_size++] = bob;
      }

      // If the totals are no longer equal, toggle the die assignment flag
      if (alice_total != bob_total) {
        current_alice_die1 = !current_alice_die1; // Switch dice for next round
      }
    }

    // Count the number of sixes in both dice arrays
    int d1_count = count_sixes(d1, d1_size);
    int d2_count = count_sixes(d2, d2_size);

    // Determine the winner based on the number of sixes
    if (d1_count > d2_count) {
      printf("1\n"); // Print "1" if Alice's dice have more sixes
    } else {
      printf("2\n"); // Print "2" if Bob's dice have more sixes
    }
  }

  return 0; // Return 0 to indicate successful execution
}
