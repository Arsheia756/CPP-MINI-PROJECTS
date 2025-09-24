#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib> 
#include<ctime>
using namespace std;

struct Question {
    string question;
    string options[4];
    int correct; // variable for the corect options
};

int main() {
    cout <<"================================================\n";
    cout <<"===												\n";
    cout <<"===												\n";
    cout <<"===												\n";
    cout <<"===												\n";
    cout <<"===       WELCOME TO THE RANDOM QUIZ GAME       \n";
    cout <<"===												\n";
    cout <<"===												\n";
    cout <<"===												\n";
    cout <<"===												\n";
    cout <<"================================================\n\n\n\n";

    cout << "Press any key to enter...";
    getch();
    system("cls");

    // 20 Capital City MCQs
    Question quiz[20] =
    {
        {"What is the capital of Pakistan?",
            {"Karachi", "Islamabad", "Lahore", "Quetta"},
            2
        },
        {"What is the capital of China?",
            {"Shanghai", "Beijing", "Nanyang", "Shenzhen"},
            2
        },
        {"What is the capital of Turkey?",
            {"Ankara", "Cappadocia", "Istanbul", "Izmir"},
            1
        },
        {"What is the capital of India?",
            {"Mumbai", "New Delhi", "Chennai", "Kolkata"},
            2
        },
        {"What is the capital of Afghanistan?",
            {"Kandahar", "Kabul", "Herat", "Mazar-i-Sharif"},
            2
        },
        {"What is the capital of Saudi Arabia?",
            {"Jeddah", "Riyadh", "Dammam", "Mecca"},
            2
        },
        {"What is the capital of Japan?",
            {"Osaka", "Tokyo", "Kyoto", "Nagoya"},
            2
        },
        {"What is the capital of the United States?",
            {"New York", "Washington, D.C.", "Los Angeles", "Chicago"},
            2
        },
        {"What is the capital of the United Kingdom?",
            {"Manchester", "Birmingham", "London", "Liverpool"},
            3
        },
        {"What is the capital of Canada?",
            {"Toronto", "Vancouver", "Ottawa", "Montreal"},
            3
        },
        {"What is the capital of Australia?",
            {"Sydney", "Canberra", "Melbourne", "Perth"},
            2
        },
        {"What is the capital of Germany?",
            {"Berlin", "Munich", "Frankfurt", "Hamburg"},
            1
        },
        {"What is the capital of France?",
            {"Paris", "Lyon", "Marseille", "Nice"},
            1
        },
        {"What is the capital of Italy?",
            {"Milan", "Rome", "Florence", "Venice"},
            2
        },
        {"What is the capital of Russia?",
            {"St. Petersburg", "Moscow", "Kazan", "Novosibirsk"},
            2
        },
        {"What is the capital of Egypt?",
            {"Cairo", "Alexandria", "Giza", "Luxor"},
            1
        },
        {"What is the capital of South Africa?",
            {"Pretoria", "Cape Town", "Johannesburg", "Durban"},
            1
        },
        {"What is the capital of Brazil?",
            {"Rio de Janeiro", "Brasília", "São Paulo", "Salvador"},
            2
        },
        {"What is the capital of Argentina?",
            {"Buenos Aires", "Cordoba", "Rosario", "Mendoza"},
            1
        },
        {"What is the capital of Indonesia?",
            {"Jakarta", "Bali", "Surabaya", "Bandung"},
            1
        }
    };

    int score = 0;
    int totalmarks = 50;

    srand(time(0));

    // An array of indexes (0 to 19)
    int order[20];
    for (int i = 0; i < 20; i++) {
        order[i] = i;
    }

    // Shuffle the order
    for (int i = 0; i < 20; i++) {
        int r = rand() % 20;
        swap(order[i], order[r]);
    }

    // Ask for only 5 random questions
    for (int k = 0; k < 5; k++) {
    	// for picking random question
        int i = order[k]; 
        cout << "\n" << quiz[i].question << endl;
        for (int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << quiz[i].options[j] << endl;
        }

        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == quiz[i].correct) {
            cout << "Correct! ??\n\n";
            score += 10;
        } else {
            cout << "Wrong ? The correct answer was: "
                 << quiz[i].options[quiz[i].correct - 1] << "\n\n";
        }
    }

    cout << "Press enter to find the result....";
    getch();
    system("cls");

    cout <<"================================================\n";
    cout <<"===												\n";
    cout <<"===												\n";
    cout <<"===												\n";
    cout <<"												\n";
    cout << "Quiz finished! Your total score is " << score << "/" << totalmarks << endl;
    cout <<"												\n";
    cout <<"===												\n";
    cout <<"===												\n";
    cout <<"===												\n";
    cout <<"================================================\n\n\n\n";
    
   

    return 0;
}

