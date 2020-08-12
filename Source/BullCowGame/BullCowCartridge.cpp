// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame(); // Setting up game

    // PrintLine(FString::Printf(TEXT("The HiddenWord is: %s. It's %i char long."), *HiddenWord, WordLength)); //Debug Line
    // Welcome the player
    PrintLine(TEXT("Hi There! Welcome to Bull & Cows Game!"));
    PrintLine(TEXT("Please enter a %i letter word:"), WordLength);

    // Prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    // If game is over then clear screen and SetupGame() 
    // else Check PlayerGuess

    if (bGameOver) {
        ClearScreen();
        SetupGame();
    } else {
        if (HiddenWord == Input) {
            PrintLine(TEXT("Your guess is correct! Congratulation"));
            EndGame();
        } else {
            // Check the length of player's guess
            if (WordLength != Input.Len()) {
                PrintLine(TEXT("The length of your word is not %i"), WordLength);
                EndGame();
            };
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
    HiddenWord = TEXT("apexabc");
    WordLength = HiddenWord.Len();
    bGameOver = false;
    RemainLives = 5;
}

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("Game is over. Press enter to continue..."));
}