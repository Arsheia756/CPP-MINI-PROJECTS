#include<iostream>
#include<cmath>
using namespace std;

class BasicCalculator {
    public:
        double Add(double a, double b) {
            return a + b;
        }
        
        double Subtract(double a, double b) {
            return a - b;
        }
        
        double Multiply(double a, double b) {
            return a * b;
        }
        
        double Divide(double a, double b) {
            if(b != 0) {
                return a / b;
            } else {
                cout << "Error! Division by zero. " << endl;
                return 0;
            }
        }
};

class ScientificCalculator : public BasicCalculator {
    public:
        double power(double base, double exp) {
            return pow(base, exp);
        }
        
        double squareroot(double a) {
            return sqrt(a);
        }
        
        int factorial(int n) {
            int result = 1;
            for (int i = 1; i <= n; i++) {
                result *= i;
            }
            return result;
        }
        
        double sine(double a) {
            return sin(a);
        }
        
        double cosine(double a) {
            return cos(a);
        }
        
        double tangent(double a) {
            return tan(a);
        }
        
        double logarithm(double a) {
            if(a > 0) {
                return log(a);
            } else {
                cout << "Error! log can't be found of non positive number...." << endl;
                return 0;
            }
        }
};

int main() {
    ScientificCalculator sc;
    int choice;
    
    do {
        cout << "\n===== SCIENTIFIC CALCULATOR MENU =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Power\n";
        cout << "6. Square Root\n";
        cout << "7. Factorial\n";
        cout << "8. Sine\n";
        cout << "9. Cosine\n";
        cout << "10. Tangent\n";
        cout << "11. Logarithm\n";
        cout << "0. Exit\n";
        cout << "Choose an operation: ";
        cin >> choice;
        
        double a, b;
        int n;
        
        switch(choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << sc.Add(a, b) << endl;
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << sc.Subtract(a, b) << endl;
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << sc.Multiply(a, b) << endl;
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << sc.Divide(a, b) << endl;
                break;
            case 5:
                cout << "Enter base and exponent: ";
                cin >> a >> b;
                cout << "Result = " << sc.power(a, b) << endl;
                break;
            case 6:
                cout << "Enter number: ";
                cin >> a;
                cout << "Result = " << sc.squareroot(a) << endl;
                break;
            case 7:
                cout << "Enter a number: ";
                cin >> n;
                cout << "Result = " << sc.factorial(n) << endl;
                break;
            case 8:
                cout << "Enter angle in degrees: ";
                cin >> a;
                cout << "Result = " << sc.sine(a * M_PI / 180) << endl;
                break;
            case 9:
                cout << "Enter angle in degrees: ";
                cin >> a;
                cout << "Result = " << sc.cosine(a * M_PI / 180) << endl;
                break;
            case 10:
                cout << "Enter angle in degrees: ";
                cin >> a;
                cout << "Result = " << sc.tangent(a * M_PI / 180) << endl;
                break;
            case 11:
                cout << "Enter a number: ";
                cin >> a;
                cout << "Result = " << sc.logarithm(a) << endl;
                break;
            case 0:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 0);
    
    return 0;
}

