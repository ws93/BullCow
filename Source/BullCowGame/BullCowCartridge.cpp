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
    ClearScreen();

    // Check PlayerGuess
    if (HiddenWord == Input) {
        PrintLine(TEXT("Your guess is correct! Congratulation"));
    } else {
        // Check the length of player's guess
        if (WordLength != Input.Len()) {
            // PrintLine(TEXT("The HiddenWord is 4 char long, try again!"));
            PrintLine(TEXT("The length of your word is not %i"), WordLength);
        };

        PrintLine(TEXT("Sorry that was wrong :( Please try again"));
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
    RemainLives = 5;
}