// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Welcome the player
    PrintLine(TEXT("Hi There! Welcome to Bull & Cows Game!"));
    PrintLine(TEXT("Please enter a four letter word:"));

    InitGame(); // Setting up game


    // Prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Check PlayerGuess
    if (HiddenWord == Input) {
        PrintLine(TEXT("Your guess is correct! Congratulation"));
    } else {
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

void UBullCowCartridge::InitGame() {
    HiddenWord = TEXT("apex");
    RemainLives = 5;
}