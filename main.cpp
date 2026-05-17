#include <iostream>
#include <vector>

using namespace std;

class Student {
    public:
    string name;
    string surname;
    vector<int> grades;

    void addName()
    {
        cout << "Wpisz imie studenta:" << endl;
        cin >> name;
    }
    void addSurname()
    {
        cout << "Wpisz nazwisko studenta:" << endl;
        cin >> surname;
    }

    void addGrade()
    {
        int zmienna = 0, grade = 0;
        cout << "Dodaj oceny:" << endl;

        while(zmienna != 2)
        {
            cin >> grade;
            while(grade != 1 && grade != 2 && grade != 3 && grade != 4 && grade != 5 && grade != 6) // Zabezpieczenie przed wpisaniem glupot
            {
                cout << "Podales zla ocene, podaj dobra ocene" << endl;
                cin >> grade;
            }
            grades.push_back(grade);
            cout << "1. Dodaj dalej / 2. Koniec dodawania" << endl;
            cin >> zmienna;
        }
    }
    double average()
    {
        if(grades.size() == 0)
        {
            return 0;
        }
        double sum = 0;
        for (int g : grades) sum += g;
        return sum / grades.size();
    }
    void print()
    {
        cout << "Imie stdenta: " << name << endl;
        cout << "Nzawisko stdenta: " << surname << endl;
        cout << "Srednia: " << average() << endl;

        cout << "Oceny studenta: " << endl;
        for(int i = 0; i < grades.size(); i++)
        {
            cout << grades[i] << " ";
        }
        cout << "" << endl;
    }
};

int main()
{
    vector<Student> students;
    int wybor = 0;

    while(wybor != 3)
    {
        cout << "1. Dodaj studenta" << endl;
        cout << "2. Pokaz liste sutendow" << endl;
        cout << "3. Wyjdz z programu" << endl;

        cin >> wybor;

        while(wybor != 1 && wybor != 2 && wybor != 3) // Zabezpieczenie
        {
            cout << "Nie ma takiego wyboru, wybierz jeszcze raz" << endl;
            cin >> wybor;
        }

        switch(wybor)
        {
            case 1:{
                Student s;        // <- TWORZYSZ NOWEGO studenta
                s.addName();
                s.addSurname();
                s.addGrade();
                students.push_back(s);
            break;
            }

            case 2:{
                bool flaga = 0;
                cout << "Lista studentow: " << endl;

                while(students.size() == 0 && flaga == 0)
                {
                    cout << "Brak dodanych studentow" << endl;
                    flaga = 1;
                }

                for(int i = 0; i < students.size(); i++)
                {
                    students[i].print();
                }
            break;
            }

            default:{
                break;
            }
        }
    }
}













