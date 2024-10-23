//
//   CSAcademy Problem - Rigged Dice
//   From: IEEEXtreme 15.0
//   Solved By: Dimitrios and Petros Papakonstantinou
//   Submission Score: 100/100 (1183ms - 36.1MB)
//

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    // Read the number of games
    int game_num = scanner.nextInt();
    scanner.nextLine(); // Consume the newline after the number input

    // Process each game
    for (int game = 0; game < game_num; ++game) {
      // Read the number of rounds for this game
      int n = scanner.nextInt();
      scanner.nextLine(); // Consume the newline after the number input

      // Lists to store dice rolls for Alice and Bob
      List<Integer> d1 =
          new ArrayList<>(); // Represents the rolls for Alice's current die
      List<Integer> d2 =
          new ArrayList<>(); // Represents the rolls for Bob's current die

      int alice_total = 0,
          bob_total = 0; // Keep track of total scores for Alice and Bob
      boolean current_alice_die1 =
          true; // Flag to determine whose roll is stored in d1 and d2

      // Read and process each round
      for (int i = 0; i < n; ++i) {
        // Read the line of input containing Alice's and Bob's rolls
        String line = scanner.nextLine();
        String[] tokens = line.split(
            " "); // Split the input line into Alice's and Bob's rolls

        // Parse the rolls from the input
        int alice = Integer.parseInt(tokens[0]);
        int bob = Integer.parseInt(tokens[1]);

        // Update total scores for Alice and Bob
        alice_total += alice;
        bob_total += bob;

        // Assign the current round's rolls to the respective lists based on
        // whose die is active
        if (current_alice_die1) {
          d1.add(alice); // Alice's roll goes to d1, Bob's to d2
          d2.add(bob);
        } else {
          d2.add(alice); // Switch roles: Alice's roll to d2, Bob's to d1
          d1.add(bob);
        }

        // If Alice and Bob's total scores are unequal, switch the dice
        // assignment for the next round
        if (alice_total != bob_total) {
          current_alice_die1 =
              !current_alice_die1; // Toggle dice assignment for the next round
        }
      }

      // Count the number of sixes in Alice's die (d1) and Bob's die (d2)
      long d1_count =
          d1.stream().filter(x -> x == 6).count(); // Count sixes in d1
      long d2_count =
          d2.stream().filter(x -> x == 6).count(); // Count sixes in d2

      // Determine the winner based on which die (d1 or d2) has more sixes
      if (d1_count > d2_count) {
        System.out.println("1"); // Alice wins if d1 has more sixes
      } else {
        System.out.println(
            "2"); // Bob wins if d2 has more sixes, or if they are equal
      }
    }

    scanner.close(); // Close the scanner after input is processed
  }
}
