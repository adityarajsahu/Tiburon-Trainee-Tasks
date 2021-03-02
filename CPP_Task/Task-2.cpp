#include<bits/stdc++.h>

using namespace std;

class Calculator
{
    private:
        double operand1, operand2;
        char operation;

    public:
        int calculate(double operand1, double operand2, char operation);
        void history(queue<double> q, double result);
};

int Calculator::calculate(double number1, double number2, char op)
{
    double result;
    operand1 = number1;
    operand2 = number2;
    operation = op;

    if(operation == 'a')
    {
        result = operand1 + operand2;
    }
    else if(operation == 's')
    {
        result = operand1 - operand2;
    }
    else if(operation == 'm')
    {
        result = operand1 * operand2;
    }
    else if(operation == 'd')
    {
        if(operand2 == 0)
        {
            result = 0;
            cout << "A number cannot be divided by zero.";
        }
        else
        {
            result = operand1 / operand2;
        }
    }
    else
    {
        result = 0;
        cout << "Invalid operation.";
    }
    return result;
}

void Calculator::history(queue<double> q, double result)
{
    if(q.size() == 10)
    {
        q.pop();
    }
    q.push(result);
}

int main()
{
    Calculator obj;
    double num1, num2, result;
    char op;
    queue<double> Q;

    cout << "Enter the first operand : ";
    cin >> num1;
    cout << '\n';

    cout << "Enter the second operand : ";
    cin >> num2;
    cout << "\n";

    cout << "Enter the operation to be done (a - addition, s - subtraction, m - multiplication, d - division) : ";
    cin >> op;
    cout << "\n";

    result = obj.calculate(num1, num2, op);
    obj.history(Q, result);

    return 0;
}