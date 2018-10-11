#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

void drawGallows(int wrongGuesses);

int main(){
    const int maxWrongGuesses = 8;
    int wrongGuesses = 0;
    char guess;
    char whatNext;
    std::vector<std::string> listOfWords;
    listOfWords.push_back("MITOCHONDRIA");
    listOfWords.push_back("CHOINKA");
    listOfWords.push_back("BOROWIK");
    listOfWords.push_back("AUSTRALIA");
    listOfWords.push_back("MANDARYNKA");



    std::cout<<"Witaj w Wisielcu. Odgadnij zakodowane slowo. Mozesz popelnic 8 bledow.\n";

    do {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::shuffle(listOfWords.begin(),listOfWords.end(),e);
        std::string wordToGuess = listOfWords[0];
        std::string wordUpdate(wordToGuess.size(),'-');
        std::string lettersTried = " ";
        do {

            std::cout << "Slowo do odgadniecia: " << wordUpdate << "\n";
            std::cout << "Podaj litere: \n";
            std::cin >> guess;
            guess = toupper(guess);
            while (lettersTried.find(guess) != std::string::npos) {
                std::cout << "Juz probowales tej litery.\n";
                std::cout << "Podaj litere:\n";
                std::cin >> guess;
                guess = toupper(guess);
            }
            lettersTried += guess;
            if (wordToGuess.find(guess) != std::string::npos) {
                std::cout << "Ta litera znajduje sie w slowie,\n";
                for (int i = 0; i < wordToGuess.length(); ++i) {
                    if (wordToGuess[i] == guess)
                        wordUpdate[i] = guess;
                }
            } else {
                std::cout << "Tej litery nie ma w slowie\n";
                ++wrongGuesses;
            }


            std::cout << "Mozesz popelnic jeszcze " << (maxWrongGuesses - wrongGuesses) << " bledow.\n";
            std::cout << "Litery uzyte do tej pory: " << lettersTried << "\n";
            drawGallows(wrongGuesses);

        } while (wrongGuesses < maxWrongGuesses && wordUpdate != wordToGuess);

        if (wrongGuesses == maxWrongGuesses)
            std::cout << "Przegrales\n";
        else
            std::cout << "Gratulacje! Odgadles slowo!\n";
        std::cout << "Slowo ktore bylo do odgadniecia to: " << wordToGuess<<"\n";
        std::cout<<"Co chcesz zrobic?\n";
        std::cout<<"Grac dalej - wybierz Y\n";
        std::cout<<"Wyjsc - wybierz N\n";
        std::cin>>whatNext;
        whatNext = toupper(whatNext);
        wrongGuesses = 0;
    }while(whatNext == 'Y');

        std::cout<<"Dziekuje za gre!\n";
}

void drawGallows(int wrongGuesses){
    switch(wrongGuesses){
        case 1:
            std::cout<<"|\n";
            std::cout<<"|\n";
            std::cout<<"|\n";
            std::cout<<"|\n";
            break;
        case 2:
            std::cout<<"|------ \n";
            std::cout<<"|       \n";
            std::cout<<"|       \n";
            std::cout<<"|       \n";
            break;
        case 3:
            std::cout<<"|------ \n";
            std::cout<<"|   O    \n";
            std::cout<<"|       \n";
            std::cout<<"|       \n";
            break;
        case 4:
            std::cout<<"|------ \n";
            std::cout<<"|   O    \n";
            std::cout<<"|   |    \n";
            std::cout<<"|       \n";
            break;
        case 5:
            std::cout<<"|------ \n";
            std::cout<<"|   O    \n";
            std::cout<<"|  /|    \n";
            std::cout<<"|       \n";
            break;
        case 6:
            std::cout<<"|------ \n";
            std::cout<<"|   O    \n";
            std::cout<<"|  /|\\  \n";
            std::cout<<"|       \n";
            break;
        case 7:
            std::cout<<"|------  \n";
            std::cout<<"|   O    \n";
            std::cout<<"|  /|\\   \n";
            std::cout<<"|  /     \n";
            break;
        case 8:
            std::cout<<"|------  \n";
            std::cout<<"|   O    \n";
            std::cout<<"|  /|\\   \n";
            std::cout<<"|  / \\   \n";
            break;

        default:
            break;
    }
}