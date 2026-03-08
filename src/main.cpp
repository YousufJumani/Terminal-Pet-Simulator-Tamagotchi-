#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

class Pet {
private:
    std::string name_;
    int health_ = 100;
    int hunger_ = 30;
    int energy_ = 70;
    int boredom_ = 20;

    static int clamp(int value) {
        return std::max(0, std::min(100, value));
    }

public:
    explicit Pet(std::string name) : name_(std::move(name)) {}

    void tick() {
        hunger_ = clamp(hunger_ + 8);
        boredom_ = clamp(boredom_ + 6);
        energy_ = clamp(energy_ - 5);

        if (hunger_ > 80) health_ = clamp(health_ - 10);
        if (boredom_ > 80) health_ = clamp(health_ - 6);
        if (energy_ < 20) health_ = clamp(health_ - 4);
    }

    void feed() {
        hunger_ = clamp(hunger_ - 25);
        health_ = clamp(health_ + 5);
    }

    void play() {
        boredom_ = clamp(boredom_ - 30);
        energy_ = clamp(energy_ - 12);
        hunger_ = clamp(hunger_ + 6);
    }

    void rest() {
        energy_ = clamp(energy_ + 30);
        boredom_ = clamp(boredom_ + 5);
    }

    bool isAlive() const {
        return health_ > 0 && hunger_ < 100;
    }

    void printStatus() const {
        std::cout << "\n== " << name_ << " STATUS ==\n";
        std::cout << "Health : " << health_ << "\n";
        std::cout << "Hunger : " << hunger_ << "\n";
        std::cout << "Energy : " << energy_ << "\n";
        std::cout << "Bored  : " << boredom_ << "\n";
    }
};

static std::string toLower(std::string value) {
    for (char &c : value) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return value;
}

int main() {
    std::cout << "Welcome to Tamagotchi Terminal Pet Simulator\n";
    std::cout << "Name your pet: ";
    std::string name;
    std::getline(std::cin, name);
    if (name.empty()) name = "Pixel";

    Pet pet(name);
    int turn = 1;

    while (pet.isAlive()) {
        pet.printStatus();
        std::cout << "\nTurn " << turn << " commands: feed | play | rest | wait | quit\n";
        std::cout << "Enter command: ";

        std::string command;
        std::getline(std::cin, command);
        command = toLower(command);

        try {
            if (command == "feed") {
                pet.feed();
            } else if (command == "play") {
                pet.play();
            } else if (command == "rest") {
                pet.rest();
            } else if (command == "wait") {
                std::cout << "You wait. Time passes...\n";
            } else if (command == "quit") {
                std::cout << "You left the game. Bye!\n";
                return 0;
            } else {
                throw std::invalid_argument("Invalid command. Use feed, play, rest, wait, or quit.");
            }
        } catch (const std::invalid_argument &e) {
            std::cout << e.what() << "\n";
            continue;
        }

        pet.tick();
        ++turn;
    }

    std::cout << "\nYour pet could not survive. Simulation ended.\n";
    return 0;
}
