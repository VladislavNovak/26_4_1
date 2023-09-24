#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include "utilities.h"
#include "player.h"
#include "track.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    bool isPlayerMenuProcess = true;
    vector<string> playerMenu = { "add", "play", "pause", "stop", "next", "info", "exit" };

    std::srand(std::time(nullptr)); // NOLINT(cert-msc51-cpp)

    Player player{};

    while(isPlayerMenuProcess) {
        std::cout << "--- Main menu ---" << std::endl;
        int command = selectMenuItem(playerMenu);

        if (playerMenu[command] == "add") {
            std::cout << "Enter the number of tracks to create (1 or more):";
            int count = putInput(1);
            vector<string> menu = { "auto", "manually" };
            std::cout << "--- Track creation menu ---" << std::endl;
            int select = selectMenuItem(menu);

            vector<Track*> list;
            list.reserve(count);
            for (int i = 0; i < count; ++i) {
                list.emplace_back(new Track(menu[select] == "auto"));
            }

            std::cout << count << " tracks added to the player" << std::endl;
            player.addTracks(list);
        }
        else if (playerMenu[command] == "play") {
            player.doPlay();
        }
        else if (playerMenu[command] == "pause") {
            player.doPause();
        }
        else if (playerMenu[command] == "stop") {
            player.doStop();
        }
        else if (playerMenu[command] == "next") {
            player.doNext();
        }
        else if (playerMenu[command] == "info") {
            player.display();
        }
        else if (playerMenu[command] == "exit") {
            player.doExit();
            isPlayerMenuProcess = false;
        }
    }

    return 0;
}
