// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hi There! Welcome to Bull & Cows Game!"));
    PrintLine(TEXT("Please enter a four letter word:"));
    HiddenWord = TEXT("apex");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if (HiddenWord == Input) {
        PrintLine(TEXT("Your guess is correct! Congratulation"));
    } else {
        PrintLine(TEXT("Sorry that was wrong :( Please try again"));
    }
}