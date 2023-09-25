/*  Samantha Sutter
*   ITDEV-185
*   Assignment 4
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h> 

class Reel {
private:
    
    static const std::string faces[];
    int position;
    std::string selectedField;

public:
    // Instantiating reel
    Reel() {
        position = 0;
        selectedField = "";
    }
    // Get the face of selected position
    std::string getFace() {
        return faces[position];
    }

    // Getting current position of reel
    int getPosition() {
        return position;
    }

    // Spinning reel to get random faces
    void spin() {
        position = rand() % 20;
        selectedField = faces[position];
    }
};
// All the possible choices a user could spin
const std::string Reel::faces[] = { "lemon", "cherry", "banana", "seven", "diamond", "bell", "heart", "star",
                                    "strawberry", "grape", "bell", "horseshoe", "heart", "pear", "orange",
                                    "10", "king", "queen", "jack", "joker" };

class SlotMachine {
private:
    Reel reels[3];

public:
    bool play() {
        // Spin the reels 3 times
        for (int i = 0; i < 3; ++i) {
            reels[i].spin();
        }
        // Display spin results
        std::cout << "Spun: " << reels[0].getFace() << " " << reels[1].getFace() << " " << reels[2].getFace() << std::endl;

        //Checking to see if reels have same face
        if (reels[0].getFace() == reels[1].getFace() && reels[1].getFace() == reels[2].getFace()) {
            std::cout << "You won!" << std::endl;
            return true;
        }
        // Returning false if user lost
        else {
            std::cout << "You lost!" << std::endl;
            return false;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    SlotMachine slotMachine;
    int playCount = 0;

    //Intro
    std::cout << "Welcome to the Slot Machine Game! Press any key to roll, or 'q' to quit." << std::endl;

    while (true) {
        if (_kbhit()) { // Check if a key is pressed
            char key = _getch(); // Get user key entry

            if (key == 'q' || key == 'Q') {
                std::cout << "You quit the game." << std::endl;
                break; // Quit the game
            }

            // Display for user winning and show roll count
            if (slotMachine.play()) {
                std::cout << "You won the game after " << playCount + 1 << " rolls! Woo! Felt like lifetime huh?!" << std::endl;
                break;
            }
            // Adding total to play count
            playCount++;
            // Asking user to enter key to continue or not
            std::cout << "Press any key to roll again, or 'q' to quit." << std::endl;
        }
    }

    return 0;
}

