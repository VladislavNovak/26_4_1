#include <iostream>
#include <vector>
#include <cassert>
#include "utilities.h"
#include "player.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

void Player::playTrack() {
    assert(current >= 0);
    status = Action::play;
    tracks[current]->About();
}

Player::Player() {
    current = -1;
    status = Action::none;
}

void Player::addTracks(vector<Track*> &list) {
    copy(list.begin(), list.end(), std::back_inserter(tracks));

    if (status == Action::none) {
        current = (current == -1) ? 0 : current;
    }
}

void Player::doPlay(int index) {
    if (hasTracks()) {
        // Если пока ничего не играло
        if (status == Action::none) {
            current = (index == -1) ? 0 : index;
            playTrack();
        }
            // Если уже играет
        else if (status == Action::play) {
            // При выборе текущего
            if (index == -1 || index == current) {
                std::cout << "The track is already playing!" << std::endl;
            }
                // При указании нового
            else {
                current = index;
                playTrack();
            }
        }
            // Если текущий на паузе
        else if (status == Action::pause) {
            // При выборе текущего
            if (index == -1 || index == current) {
                std::cout << "The track will continue to play!" << std::endl;
                playTrack();
            }
                // При указании нового
            else {
                current = index;
                playTrack();
            }
        }
            // Если текущий остановлен
        else if (status == Action::stop) {
            // При выборе текущего
            if (index == -1 || index == current) {
                std::cout << "The track will start from the beginning!" << std::endl;
                playTrack();
            }
                // При указании нового
            else {
                current = index;
                playTrack();
            }
        }
    }

}

void Player::doNext() {
    if (hasTracks()) {
        if (tracks.empty()) {
            std::cout << "Warning. The player has no recordings. Need to download!" << std::endl;
            return;
        }

        int index = (tracks.size() == 1) ? 0 : getRandomIntInRange(0, (int)tracks.size() - 1);

        doPlay(index);
    }
}

void Player::doAction(Action action) {
    if (hasTracks()) {
        if (action == Action::stop) {
            if (status == Action::none) std::cout << "No track has been played before!" << endl;
            else if (status == Action::stop) cout << "Track has already stopped" << endl;
            else if (status == Action::pause || status == Action::play) {
                cout << "Track stopped" << endl;
                status = Action::stop;
            }
        }
            // В случае action == Action::pause
        else {
            if (status == Action::none) std::cout << "No track has been played before!" << endl;
            else if (status == Action::stop) cout << "Track has already stopped" << endl;
            else if (status == Action::pause) cout << "Track has already paused" << endl;
            else if (status == Action::play) {
                cout << "Track paused" << endl;
                status = Action::pause;
            }
        }
    }
}

void Player::doPause() { doAction(Action::pause);}

void Player::doStop() { doAction(Action::stop); }

void Player::doExit() {
    current = -1;
    status = Action::none;

    // Удаляем каждый элемент и очищаем вектор, чтобы никто не мог повторно удалить указатели
    for (auto &track : tracks) delete track;
    tracks.clear();
}

void Player::display() {
    if (hasTracks()) {
        for (auto &track : tracks) {
            track->About();
        }
    }
}

bool Player::hasTracks() {
    if (tracks.empty()) {
        std::cout << "Warning. The player has no recordings. Need to download!" << std::endl;
        return false;
    }

    return true;
}
