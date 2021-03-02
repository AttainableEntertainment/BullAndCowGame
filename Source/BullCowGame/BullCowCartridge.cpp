// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

   

    PrintLine(TEXT("Welcome to the bull and cow game"));
    PrintLine(TEXT("Guess a 4 letter word"));
    

    InitGameSettings();


    /**
    * game loop
    * 
    * start game 
    * set hidden word 
    * set number of lives
    * prompt for guess 
    * if correct player wins 
    * if not lives--prompt for guess 
    * if lives == 0 player loses
    * 
    * */
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
   
   

    if (HiddenWord == Input) {
        PrintLine(TEXT("The word is correct!!"));
    }
    else {
        if (Input.Len() == HiddenWord.Len()) {
            PrintLine(TEXT("The word is wrong"));
        }
        else {
            PrintLine(TEXT("The length of guess is wrong"));
        }
        
    }
    //validate input
    //check isIsogram 
    //isNumberOfCharactere correct
    //set lives--;
    //if lives == 0 player loses



}
void UBullCowCartridge::InitGameSettings()
{
    HiddenWord = TEXT("high");
    Lives = 4;
}