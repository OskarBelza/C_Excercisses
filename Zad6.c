#include <stdio.h>
#include <stdlib.h>

#define MAX_ROUNDS 10

// Definition of an enumeration type (enum) for moves
enum Move {
    ROCK,
    PAPER,
    SCISSORS
};

// Definition of an enumeration type (enum) for round results
enum RoundResult {
    WIN,
    DRAW,
    LOSS
};

// Array with move names
const char *moveNames[] = {"rock", "paper", "scissors"};

int main() {
    enum Move playerMove, computerMove;
    int playerScore = 0, computerScore = 0;
    enum RoundResult historyResults[MAX_ROUNDS]; // Array to store round results
    enum Move historyMoves[MAX_ROUNDS][2]; // Array to store move history (player, computer)
    int roundsPlayed = 0;

    printf("Welcome to the game of Rock, Paper, Scissors!\n");

    while(roundsPlayed < MAX_ROUNDS) {
        printf("\nRound %d\n", roundsPlayed + 1);
        printf("Choose your move (0 - rock, 1 - paper, 2 - scissors): ");
        scanf("%d", (int *)&playerMove); // Player's move input

        // Randomly choose computer's move
        computerMove = rand() % 3;

        // Store moves in history
        historyMoves[roundsPlayed][0] = playerMove;
        historyMoves[roundsPlayed][1] = computerMove;

        // Check the result of the round
        if ((playerMove == ROCK && computerMove == SCISSORS) || (playerMove == PAPER && computerMove == ROCK) || (playerMove == SCISSORS && computerMove == PAPER)) {
            printf("You win!\n");
            playerScore++;
            historyResults[roundsPlayed] = WIN;
        } else if (playerMove == computerMove) {
            printf("Draw!\n");
            historyResults[roundsPlayed] = DRAW;
        } else {
            printf("You lose!\n");
            computerScore++;
            historyResults[roundsPlayed] = LOSS;
        }

        roundsPlayed++;

        // Choose whether to continue the game
        printf("Do you want to continue? (0 - No, 1 - Yes): ");
        int continueGame;
        scanf("%d", &continueGame);
        if (continueGame == 0) {
            break;
        }
    }

    // Display round results
    printf("\nRound results:\n");
    for (int i = 0; i < roundsPlayed; i++) {
        printf("Round %d: %s vs %s, ", i + 1, moveNames[historyMoves[i][0]], moveNames[historyMoves[i][1]]);
        switch (historyResults[i]) {
            case WIN:
                printf("Win\n");
                break;
            case DRAW:
                printf("Draw\n");
                break;
            case LOSS:
                printf("Loss\n");
                break;
        }
    }

    // Display final score
    printf("\nFinal score:\n");
    printf("Player: %d, Computer: %d\n", playerScore, computerScore);

    return 0;
}
