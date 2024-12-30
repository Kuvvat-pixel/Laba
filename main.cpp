#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <fstream>
#include "player.h"
using namespace std;
void inputPlayers(vector<Player> &players) {
    int n;
    cout << "Введите количество игроков: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Player player;
        cout << "\nИгрок " << i + 1 << ":\n";
        cout << "Фамилия: ";
        cin >> player.surname;
        cout << "Имя: ";
        cin >> player.name;
        cout << "Страна: ";
        cin >> player.country;
        cout << "Команда: ";
        cin >> player.team;
        cout << "Игровой номер: ";
        cin >> player.number;
        cout << "Возраст: ";
        cin >> player.age;
        cout << "Рост: ";
        cin >> player.height;
        cout << "Вес: ";
        cin >> player.weight;
        cout << "Введите количество сыгранных матчей: ";
        cin >> player.additionalInfo.matchesPlayed;
        players.push_back(player);
    }
}
void displayPlayers(const vector<Player> &players) {
    cout << "\nСписок игроков:\n";
    cout << setw(10) << " Фамилия " << setw(10) << " Имя " << setw(15) << " Страна "
         << setw(15) << " Команда " << setw(10) << " Номер " << setw(10) << " Возраст "
         << setw(10) << "Рост" << setw(10) << "Вес" << setw(15) << "Матчи\n";
    for (const auto &player : players) {
        cout << setw(10) << player.surname << setw(10) << player.name
             << setw(15) << player.country << setw(15) << player.team
             << setw(10) << player.number << setw(10) << player.age
             << setw(10) << player.height << setw(10) << player.weight
             << setw(15) << player.additionalInfo.matchesPlayed << endl;
    }
}
void shellSort(vector<Player> &players) {
    int n = players.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            Player temp = players[i];
            int j;
            for (j = i; j >= gap && players[j - gap].age < temp.age; j -= gap) {
                players[j] = players[j - gap];
            }
            players[j] = temp;
        }
    }
}

void findPlayersOver20(const vector<Player> &players) {
    cout << "\nИгроки старше 20 лет:\n";
    for (const auto &player : players) {
        if (player.age > 20) {
            cout << "Фамилия: " << player.surname << ", Возраст: " << player.age << endl;
        }
    }
}

void saveToFile(const vector<Player> &players, const string &filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла для записи.\n";
        return;
    }
    for (const auto &player : players) {
        file.write(reinterpret_cast<const char *>(&player), sizeof(Player));
    }
    file.close();
    cout << "Данные сохранены в файл " << filename << endl;
}
void loadFromFile(vector<Player> &players, const string &filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла для чтения.\n";
        return;
    }
    Player player;
    while (file.read(reinterpret_cast<char *>(&player), sizeof(Player))) {
        players.push_back(player);
    }
    file.close();
    cout << "Данные загружены из файла " << filename << endl;
}

int main() {
    vector<Player> players;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Ввести игроков\n";
        cout << "2. Показать игроков\n";
        cout << "3. Найти игроков старше 20 лет\n";
        cout << "4. Отсортировать игроков по возрасту (убывание)\n";
        cout << "5. Сохранить в файл\n";
        cout << "6. Загрузить из файла\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
            case 1:
                inputPlayers(players);
                break;
            case 2:
                displayPlayers(players);
                break;
            case 3:
                findPlayersOver20(players);
                break;
            case 4:
                shellSort(players);
                cout << "Игроки отсортированы по возрасту (убывание).\n";
                break;
            case 5:
                saveToFile(players, "players.bin");
                break;
            case 6:
                loadFromFile(players, "players.bin");
                break;
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
    return 0;
}