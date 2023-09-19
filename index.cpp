#include <iostream>
#include <string>
class Game {
public:
  Game() {
    currentRoom = startRoom;
  }

  void moveNorth() {
    if (currentRoom->getNorth() != nullptr) {
      currentRoom = currentRoom->getNorth();
    } else {
      std::cout << "You can't go north from here." << std::endl;
    }
  }

  void moveSouth() {
    if (currentRoom->getSouth() != nullptr) {
      currentRoom = currentRoom->getSouth();
    } else {
      std::cout << "You can't go south from here." << std::endl;
    }
  }

  void printCurrentRoom() {
    std::cout << currentRoom->getName() << std::endl;
    std::cout << currentRoom->getDescription() << std::endl;
  }

private:
  Room* currentRoom;
  Room* startRoom;
};
Room startRoom("Start Room", "You are standing in a room. There is a door to the north and a door to the south.");
Room northRoom("North Room", "You are in a north room. There is a door to the south and a door to the east.");
Room southRoom("South Room", "You are in a south room. There is a door to the north and a door to the west.");

Game game;
game.startRoom = &startRoom;

while (true) {
  game.printCurrentRoom();

  std::string input;
  std::cout << "What do you want to do? (north/south/quit): ";
  std::cin >> input;

  if (input == "north") {
    game.moveNorth();
  } else if (input == "south") {
    game.moveSouth();
  } else if (input == "quit") {
    break;
  } else {
    std::cout << "Invalid command." << std::endl;
  }
}
