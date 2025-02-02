#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float monthlyIncome;
    float savingAmount;
    float monthlyBudget;
    float budgetDiffrence;
    int numberOfExpenses;
    float valueOfExpense;

    cout << "Welcome to the budget calculator!\n\nPlease input your total montly income: $";
    cin >> monthlyIncome;
    cout << "Please enter how much you wish to save: $";
    cin >>savingAmount;

    //Error checking loop to prevent user from entering an amount greater than their montly income
    if(savingAmount > monthlyIncome){
        while(savingAmount > monthlyIncome){
            cout <<"The amount you wish to save is greater than your montly income, please try again:";
            cin >>savingAmount;
        }
    }

    //Evaluates the user monthly budget
    monthlyBudget = (monthlyIncome - savingAmount);
    cout << "Your montly budget is: $" << fixed << setprecision(2) << monthlyBudget << "\n" <<endl;

    //Assigns the values of monthlyBudget to budgetDiffrence to enable budget over or under calculation
    budgetDiffrence = monthlyBudget;

    //Get the user number of expenses
    cout << "How many expenses did you have this month: ";
    cin >> numberOfExpenses;

    //Prompts the user to enter a response for each number of expense
    for(int i = 1; i < numberOfExpenses + 1; i++){
        cout << "What is the value of monthly expense #" << i << ": ";
        cin >> setprecision(2) >> valueOfExpense;
        while(valueOfExpense <= 0.00){
            cout << "An expense must have a value greater than 0 for it to be an expense, please try again."<< endl;
            cout << "What is the value of monthly expense #" << i << ": ";
            cin >> valueOfExpense;
        }
        budgetDiffrence = budgetDiffrence - valueOfExpense;
    }

    //Tells the user whether they are over or under budget using the variable budgetDiffrence

    if(budgetDiffrence > 0){
        cout << "Congradulations, you are  $" << fixed << setprecision(2) << budgetDiffrence << " under your monthly budget of $" << monthlyBudget << endl;
    }
    else if(budgetDiffrence < 0){
        cout << "You were $" << fixed << setprecision(2) << -(budgetDiffrence) << " over budget this month" << endl;
    }

    return 0;
}
