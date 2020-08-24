// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/HiddenWordList.txt");
    FFileHelper::LoadFileToStringArray(Words, *WordListPath);

    Isograms = GetValidWords(Words);

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
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame() {
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
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

void UBullCowCartridge::ProcessGuess(const FString& Guess) {
    if (HiddenWord == Guess) {
        PrintLine(TEXT("Your guess is correct! Congratulation"));
        EndGame();

        return;
    }

    // Check the length of player's guess
    if (WordLength != Guess.Len()) {
        PrintLine(TEXT("The length of your word is not %i"), WordLength);

        return;
    }

    // Check if is Isogram
    if (!IsIsogram(Guess)) {
        PrintLine(TEXT("No repeating chars!\n"));
        
        return;
    }
    

    // Remove life
    PrintLine(TEXT("Lost a life!"));
    --RemainLives;

    // Check if lives > 0
    if (RemainLives <= 0) {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!\n"));
        PrintLine(TEXT("The hidden word is %s\n"), *HiddenWord);
        EndGame();

        return;
    }

    // Show Player Bulls and Cows
    FBullCowCount Count = GetBullCows(Guess);

    PrintLine(TEXT("You have %i Bulls and %i Cows.\n"), Count.Bulls, Count.Cows);

    PrintLine(TEXT("Guess again, you have %i lives left\n"), RemainLives);
}

bool UBullCowCartridge::IsIsogram(const FString& data) const {
    // A navie approache to check if data is isogram
    for (int32 i = 0; i < data.Len() - 1; ++i) {
        for (int j = i + 1; j < data.Len(); ++j) {
            if (data[i] == data[j]) {
                return false;
            }
        }
    }
    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const {
    TArray<FString> ValidWords;

    for (const FString word : WordList) {
        if (word.Len() >= 4 && word.Len() <= 8 && IsIsogram(word)) {
            ValidWords.Emplace(word);
        }
    }

    return ValidWords;
}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const {
    FBullCowCount Count;
    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++) {
        if (Guess[GuessIndex] == HiddenWord[GuessIndex]) {
            Count.Bulls++;
            continue;
        }

        for (int32 HiddenWordIndex = 0; HiddenWordIndex < Guess.Len(); HiddenWordIndex++) {
            if (Guess[GuessIndex] == HiddenWord[HiddenWordIndex]) {
                Count.Cows++;
                break;
            }
        }
    }

    return Count;
}