#include <iostream>
#include <string>

using namespace std;

class FT
{
private:
    string username;
    int stepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
    FT(string uName, int stepG)
    {
        username = uName;
        stepGoal = stepG;
        stepsTaken = 0;
        caloriesBurned = 0;
    }

    void steps(int stepsSoFar)
    {
        if (stepsTaken >= stepGoal)
        {
            cout << "You've reached your step goal for today!\n";
        }
        if (stepsSoFar > 0)
        {
            stepsTaken += stepsSoFar;
            caloriesBurned += stepsSoFar * 0.04;
        }
        cout << "You are " << stepGoal - stepsTaken << " steps away from your goal!\n";
    }

    void progress()
    {
        cout << "User: " << username << "\n";
        cout << "Steps Taken: " << stepsTaken << "\n";
        cout << "Calories Burned: " << caloriesBurned << "\n";
        if (stepsTaken >= stepGoal)
        {
            cout << "Goal achieved!\n";
        }
        else
        {
            cout << "Keep going!\n";
        }
    }
};

int main()
{
    string name;
    int goal, steps;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter daily step goal: ";
    cin >> goal;

    FT user(name, goal);

    int choice;
    do
    {
        cout << "\n1. Log Steps\n2. View Progress\n3. Exit\nChoose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter steps: ";
            cin >> steps;
            user.steps(steps);
            break;
        case 2:
            user.progress();
            break;
        case 3:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
