// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame(); // Setting up game

    // PrintLine(FString::Printf(TEXT("The HiddenWord is: %s. It's %i char long."), *HiddenWord, WordLength)); //Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    // If game is over then clear screen and SetupGame() 
    // else Check PlayerGuess
    if (RemainLives <= 0) {
        EndGame();
    }

    if (bGameOver) {
        ClearScreen();
        SetupGame();
    } else {
        if (HiddenWord == Input) {
            PrintLine(TEXT("Your guess is correct! Congratulation"));
            EndGame();
        } else {
            --RemainLives;
            if (RemainLives > 0) {
                // Check the length of player's guess
                if (WordLength != Input.Len()) {
                    PrintLine(TEXT("The length of your word is not %i"), WordLength);
                    PrintLine(TEXT("You lost a live and you still have %i lives remaining."), RemainLives);
                    // EndGame();
                };
            } else {
                PrintLine(TEXT("You have no lives left!"));
                EndGame();
            }

        }
    }

    // Check if Isogram
    // Check right number of chars

    // Remove life
    // Check if lives > 0
    // If Yes, guess again
    // If No, show GameOver and HiddenWord and lives left
    // Check user input
    // Play Again or Quit
}

void UBullCowCartridge::SetupGame() {
    HiddenWord = TEXT("apex");
    WordLength = HiddenWord.Len();
    RemainLives = HiddenWord.Len();
    bGameOver = false;

    // Welcome the player
    PrintLine(TEXT("Hi There! Welcome to Bull & Cows Game!"));
    PrintLine(TEXT("You have %i lives remaining."), RemainLives);

    // Prompt player for guess
    PrintLine(TEXT("Please enter a %i letter word:"), WordLength);

}

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("Game is over. Press enter to continue..."));
}