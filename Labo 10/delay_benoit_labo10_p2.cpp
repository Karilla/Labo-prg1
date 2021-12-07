#include <iostream>

using namespace std;

int main()
{
    int choice1, choice2, choice3;
    cout << "Veuillez entrer 3 entiers" << endl;
    cin >> choice1 >> choice2 >> choice3;

    int min;
    if(choice1 <= choice2 && choice1 <= choice3)
    {
        min = choice1;
    }
    else if(choice2 <= choice1 && choice2 <= choice3)
    {
        min = choice2;
    }
    else if(choice3 <= choice1 && choice3 <= choice2)
    {
        min = choice3;
    }

    cout << "La plus petite valeur est " << min << endl;
}