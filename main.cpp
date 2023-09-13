#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для хранения информации о кандидате
struct Candidate {
    string name;
    int votes;

    Candidate(string n) {
        name = n;
        votes = 0;
    }
};

// Функция для проведения голосования
void conductElection(vector<Candidate>& candidates) {
    cout << "Голосование за выбор старосты!" << endl;

    // Вывод списка кандидатов
    cout << "Кандидаты:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }

    // Цикл голосования
    while (true) {
        cout << "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование): ";
        int choice;
        cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            cout << "Недопустимый выбор!" << endl;
            continue;
        }
        else if (choice == 0) {
            break;
        }

        char sure;
        cout << " Вы уверены Y/N?: ";
        cin >> sure;

        if (sure != 'Y' && sure != 'N') {
            cout << "Недопустимый выбор!" << endl;
        }
        else if (sure == 'N') {
            continue;
        }

        else if (sure == 'Y') {
            // Увеличение количества голосов кандидата
            candidates[choice - 1].votes++;
        }



    }

    // Сортировка кандидатов по убыванию голосов
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
        });

    // Вывод результатов голосования
    cout << "Результаты голосования:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " голосов" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Ввод количества кандидатов
    int numCandidates;
    cout << "Введите количество кандидатов: ";
    cin >> numCandidates;

    // Ввод имён кандидатов
    vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        string name;
        cout << "Введите имя кандидата #" << i + 1 << ": ";
        cin >> name;
        candidates.push_back(Candidate(name));
    }

    // Проведение голосования
    conductElection(candidates);

    return 0;
}