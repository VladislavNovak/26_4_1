#ifndef INC_26_4_1_PLAYER_H
#define INC_26_4_1_PLAYER_H

#include <iostream>
#include <vector>
#include "track.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

// Команды для объекта Player
enum class Action { none, stop, pause, play };

class Player {
    // Коллекция проигрываемых треков
    vector<Track*> tracks;
    // Текущий трек (-1, если никаких операций ещё не производилось)
    int current;
    // Статус текущего трека [none|stop|pause|play]
    Action status;

    // Проигрывает запись объекта Track
    void playTrack();

    // Останавливает или ставит на паузу запись.
    void doAction(Action);
public:
    explicit Player();

    // Добавляет любое количество новых записей
    void addTracks(vector<Track*> &);

    // Команда проигрывания записи
    void doPlay(int index = -1);

    // Команда проигрывания следующей записи
    void doNext();

    void doPause();

    void doStop();

    void doExit();

    // Выводит информацию о всех треках в player
    void display();

    // Возвращает true, если player.tracks > 0
    bool hasTracks();
};

#endif //INC_26_4_1_PLAYER_H
