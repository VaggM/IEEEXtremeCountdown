//
//   CSAcademy Problem - Rigged Dice
//   From: IEEEXtreme 15.0
//   Solved By: Dimitrios and Petros Papakonstantinou
//   Submission Score: 100/100 (69ms - 776KB)
//

use std::io::{self, BufRead};

fn main() {
    // Set up buffered reader for standard input
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    // Read the number of games to be played
    let game_num: i32 = lines.next().unwrap().unwrap().trim().parse().unwrap();

    // Process each game
    for _ in 0..game_num {
        // Read the number of rounds for the current game
        let n: i32 = lines.next().unwrap().unwrap().trim().parse().unwrap();

        // Initialize vectors to store dice rolls for each die
        let mut d1 = Vec::new();
        let mut d2 = Vec::new();

        // Initialize total scores for Alice and Bob
        let mut alice_total = 0;
        let mut bob_total = 0;

        // Flag to track which die Alice is currently using (true for d1, false for d2)
        let mut current_alice_die1 = true;

        // Process each round of the game
        for _ in 0..n {
            // Read and parse Alice's and Bob's rolls for this round
            let round: Vec<i32> = lines
                .next()
                .unwrap()
                .unwrap()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect();

            let alice = round[0];
            let bob = round[1];

            // Update total scores
            alice_total += alice;
            bob_total += bob;

            // Assign rolls to the appropriate die based on the current state
            if current_alice_die1 {
                d1.push(alice);
                d2.push(bob);
            } else {
                d2.push(alice);
                d1.push(bob);
            }

            // Switch Alice's die if the scores are not tied
            if alice_total != bob_total {
                current_alice_die1 = !current_alice_die1;
            }
        }

        // Count the number of 6's rolled with each die
        let d1_count = d1.iter().filter(|&&x| x == 6).count();
        let d2_count = d2.iter().filter(|&&x| x == 6).count();

        // Print the result: "1" if d1 has more 6's, "2" otherwise
        if d1_count > d2_count {
            println!("1");
        } else {
            println!("2");
        }
    }
}
