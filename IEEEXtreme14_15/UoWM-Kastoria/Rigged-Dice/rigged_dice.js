//
//   CSAcademy Problem - Rigged Dice
//   From: IEEEXtreme 15.0
//   Solved By: Dimitrios and Petros Papakonstantinou
//   Submission Score: 100/100 (1957ms - 36.6MB)
//

const readline = require('readline');

// Create an interface to read from standard input and output
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let gameNum;           // Total number of games to be played
let currentGame = 0;    // Index of the current game being processed
let n;                 // Number of rounds in the current game
let currentRoll = 0;    // Counter for the number of rounds processed in the current game

// Function to process a single game
function processGame() {
  let d1 = [], d2 = [];               // Arrays to store dice rolls for Alice and Bob
  let aliceTotal = 0, bobTotal = 0;    // Variables to track total scores for Alice and Bob
  let currentAliceDie1 = true;         // Flag to toggle whose roll is added to d1/d2

  // Function to process a single round of rolls (for Alice and Bob)
  function processRoll() {
    rl.question('', (line) => {
      // Parse the current round's dice rolls for Alice and Bob
      const [alice, bob] = line.split(' ').map(Number);

      // Update the total scores for Alice and Bob
      aliceTotal += alice;
      bobTotal += bob;

      // Depending on the value of currentAliceDie1, store Alice's and Bob's rolls in d1 or d2
      if (currentAliceDie1) {
        d1.push(alice);  // Add Alice's roll to d1 and Bob's to d2
        d2.push(bob);
      } else {
        d2.push(alice);  // Add Alice's roll to d2 and Bob's to d1
        d1.push(bob);
      }

      // If the total scores for Alice and Bob are unequal, switch the die assignments for the next round
      if (aliceTotal !== bobTotal) {
        currentAliceDie1 = !currentAliceDie1;  // Toggle die assignment
      }

      currentRoll++;  // Increment the round counter

      // If there are more rounds left in the current game, process the next roll
      if (currentRoll < n) {
        processRoll();
      } else {
        // If all rounds for the current game are processed, count the number of sixes in each die
        const d1Count = d1.filter(x => x === 6).length;  // Count the sixes in d1
        const d2Count = d2.filter(x => x === 6).length;  // Count the sixes in d2

        // Determine the winner based on the count of sixes
        console.log(d1Count > d2Count ? '1' : '2');  // Alice wins if d1 has more sixes, otherwise Bob wins

        currentGame++;  // Move to the next game

        // If more games are left, start the next game
        if (currentGame < gameNum) {
          startNextGame();
        } else {
          rl.close();  // Close the readline interface if all games are processed
        }
      }
    });
  }

  // Read the number of rounds (n) for the current game and start processing rolls
  rl.question('', (input) => {
    n = parseInt(input);  // Parse the number of rounds
    currentRoll = 0;      // Reset the round counter for the new game
    processRoll();        // Start processing the first roll
  });
}

// Function to start the next game
function startNextGame() {
  processGame();  // Process a new game
}

// Start by reading the number of games
rl.question('', (input) => {
  gameNum = parseInt(input);  // Parse the number of games
  startNextGame();            // Start processing the first game
});
