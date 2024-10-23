#
#   CSAcademy Problem - Rigged Dice
#   From: IEEEXtreme 15.0
#   Solved By: Dimitrios and Petros Papakonstantinou
#   Submission Score: 100/100 (1023ms - 4400KB)
#

# Function to process a single game
def process_game():
    # Get the number of rounds in the game
    n = int(input())
    
    # Initialize lists to store dice rolls for each die
    d1, d2 = [], []
    
    # Initialize total scores for Alice and Bob
    alice_total, bob_total = 0, 0
    
    # Flag to track which die Alice is currently using (True for d1, False for d2)
    current_alice_die1 = True
    
    # Process each round of the game
    for _ in range(n):
        # Get Alice's and Bob's rolls for this round
        alice, bob = map(int, input().split())
        
        # Update total scores
        alice_total += alice
        bob_total += bob
        
        # Assign rolls to the appropriate die based on the current state
        if current_alice_die1:
            d1.append(alice)
            d2.append(bob)
        else:
            d2.append(alice)
            d1.append(bob)
        
        # Switch Alice's die if the scores are not tied
        if alice_total != bob_total:
            current_alice_die1 = not current_alice_die1
    
    # Count the number of 6's rolled with each die
    d1_count = d1.count(6)
    d2_count = d2.count(6)
    
    # Print the result: "1" if d1 has more 6's, "2" otherwise
    print("1" if d1_count > d2_count else "2")

# Main function to handle multiple games
def main():
    # Get the number of games to be played
    game_num = int(input())
    
    # Process each game
    for _ in range(game_num):
        process_game()

# Entry point of the program
if __name__ == "__main__":
    main()
