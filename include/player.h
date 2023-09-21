#ifndef INC_26_4_1_PLAYER_H
#define INC_26_4_1_PLAYER_H

#include <iostream>
#include <vector>
#include "track.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

// ������� ��� ������� Player
enum class Action { none, stop, pause, play };

class Player {
    // ��������� ������������� ������
    vector<Track*> tracks;
    // ������� ���� (-1, ���� ������� �������� ��� �� �������������)
    int current;
    // ������ �������� ����� [none|stop|pause|play]
    Action status;

    // ����������� ������ ������� Track
    void playTrack();

    // ������������� ��� ������ �� ����� ������.
    void doAction(Action);
public:
    explicit Player();

    // ��������� ����� ���������� ����� �������
    void addTracks(vector<Track*> &);

    // ������� ������������ ������
    void doPlay(int index = -1);

    // ������� ������������ ��������� ������
    void doNext();

    void doPause();

    void doStop();

    void doExit();

    // ������� ���������� � ���� ������ � player
    void display();

    // ���������� true, ���� player.tracks > 0
    bool hasTracks();
};

#endif //INC_26_4_1_PLAYER_H
