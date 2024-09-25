#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6
#define WORD_SIZE 100

void display_hangman(int tries);
void to_uppercase(char *str);	

int main() {
    const char *word = "PROGRAMMING";  // The word to guess
    int word_length = strlen(word);
    char guessed_word[WORD_SIZE];
    char guessed_letters[WORD_SIZE] = "";
    int tries = 0;
    int correct_guesses = 0;
    char guess;

    // Initialize guessed_word with underscores
    for (int i = 0; i < word_length; i++) {
        guessed_word[i] = '_';
    }
    guessed_word[word_length] = '\0';
 
printf("welcome to hangman\n");

    while (tries < MAX_TRIES && correct_guesses < word_length) {
        printf("\n%s\n", guessed_word);
        printf("Guessed letters: %s\n", guessed_letters);
        printf("Tries left: %d\n", MAX_TRIES - tries);

        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        // Check if the letter has already been guessed
        if (strchr(guessed_letters, guess) != NULL) {
            printf("You've already guessed that letter.\n");
            continue;
        }

        // Add the guessed letter to guessed_letters
        strncat(guessed_letters, &guess, 1);

        int found = 0;
        for (int i = 0; i < word_length; i++) {
            if (word[i] == guess) {
                guessed_word[i] = guess;
                found = 1;
                correct_guesses++;
            }
        }

        if (!found) {
            tries++;
        }

        display_hangman(tries);
    }

    if (correct_guesses == word_length) {
        printf("\nCongratulations! You guessed the word: %s\n", word);
    } else {
        printf("\nSorry, you lost. The word was: %s\n", word);
    }

    return 0;
}

void display_hangman(int tries) {
    switch (tries) {
        case 0:
            printf("\n +---+\n     |\n     |\n     |\n    ===\n");
            break;
        case 1:
            printf("\n +---+\n O   |\n     |\n     |\n    ===\n");
            break;
        case 2:
            printf("\n +---+\n O   |\n |   |\n     |\n    ===\n");
            break;
        case 3:
            printf("\n +---+\n O   |\n/|   |\n     |\n    ===\n");
            break;
        case 4:
            printf("\n +---+\n O   |\n/|\\  |\n     |\n    ===\n");
            break;
        case 5:
            printf("\n +---+\n O   |\n/|\\  |\n/    |\n    ===\n");
            break;
        case 6:
            printf("\n +---+\n O   |\n/|\\  |\n/ \\  |\n    ===\n");
            break;
    }
}

void to_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

