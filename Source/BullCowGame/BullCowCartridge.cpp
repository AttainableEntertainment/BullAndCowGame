// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    //loads word file 
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/HiddenWordList.txt");
    FFileHelper::LoadFileToStringArray(Words, *WordListPath);
    InitGameSettings();
    PrintLine(TEXT("The hidden word is: %s"), *HiddenWord); //debug line

}
void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ProcessGuess(Input);
}
void UBullCowCartridge::InitGameSettings()
{
    HiddenWord = TEXT("highs");
    Lives = HiddenWord.Len();
    bIsGameOver = false;
    //Welcome message
    PrintLine(TEXT("Welcome to the bull and cow game"));
    PrintLine(FString::Printf(TEXT("Guess a %i letter word"), HiddenWord.Len()));
    PrintLine(FString::Printf(TEXT("Number of lives: %i"), Lives));
    PrintLine(TEXT("Please guess the word.."));
}
void UBullCowCartridge::EndGame()
{
    bIsGameOver = true;
    PrintLine(TEXT("Press Enter to continue..."));
}
void UBullCowCartridge::ProcessGuess(FString guess)
{
    if (bIsGameOver)
    {
        ClearScreen();
        InitGameSettings();
        return;
    }
    if (HiddenWord == guess) 
    {
        PrintLine(TEXT("The word is correct!!"));
        EndGame();
        return;
    }
    if (guess.Len() != HiddenWord.Len())
    {
        PrintLine(FString::Printf(TEXT("The length of the word is: %i try again"), HiddenWord.Len()));
        return;
    }
    if(!IsIsogram(guess))
    {
      PrintLine(TEXT("The word %s has repeating letters. \nTry again."), *guess); 
      return;
    }
    if(Lives<1)
    {
        PrintLine(TEXT("You have run out of lives"));
        EndGame();
        return;
    }
    PrintLine(TEXT("The word is wrong"));
    PrintLine(TEXT("You have %i lives remaining"), --Lives);
}
 bool UBullCowCartridge::IsIsogram(FString word) const
{
     for (int32 Index = 0; Index < word.Len(); Index++)
     {
         for (int32 Counter = Index + 1; Counter < word.Len(); Counter++)
         {
             if (word[Index] == word[Counter]) {
                 return false;
             }
         }
     }
     return true;
 /*for length of word 
 loop through chars 
 if word has more then 1 char the same */  
}