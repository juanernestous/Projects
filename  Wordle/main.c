#include <stdio.h>
#include <string.h>

// Juan E. Leon
// COP 3223
// March 20, 2022
// Assignment #5: "Wordle With a Twist"

int main() {

    // First, we define variables.
    char my_word[20] = "FLIGHT"; // String array (the hidden word).
    char guess[20]; // String array for user's input.
    int attempts = 10; // Max. allowed attempts.
    int show[strlen(my_word)]; // integer array for what will be displayed.

    // Create a while loop that will run until the user inputs 10 guesses.
    while(attempts > 0){
        // Set all characters in show to 0, which we convert later into "_".
        for (int i=0; i<strlen(my_word); i++)
            show[i]=0;

        // Take user's guess as input and store it in the array defined above.
        printf("What is the hidden word?\n");
        scanf("%s", guess);

        // This nested loop compares each character in my_word to each in guess.
        for(int i=0; i<6; i++) {
            for(int j=0; j<6; j++) {
                // If the letter is present at all, set the corresponding show[] value to 1.
                if (guess[j] == my_word[i])
                    show[j] = 1;
            }
            // Then, check if any letter is in the right position, if so, set show[] value to 2
            if(guess[i]==my_word[i])
                show[i]=2;
        }

        // This loop will display the game's current state based on show[i]'s current numeric value.
        // 0 = not guessed("_") | 1 = not in position("+") | 2 = correct guess ("*").
        for(int i = 0; i<strlen(my_word); i++){
            if(show[i]==0)
                printf("_");
            else if(show[i]==1)
                printf("+");
            else if(show[i]==2)
                printf("*");
        }
        //new lines to separate the display from the next run.
        printf("\n\n");

        // This determines whether the user has guessed the whole word and ends the program if so.
        if(strcmp(my_word,guess)==0) {
            printf("Good job! You got it!\n");
            attempts = 0;
        }
        // Deduct an attempt each time the loop runs.
        attempts--;
    }
    return 0;
}
