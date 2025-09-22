#include<iostream>
//for getch()
#include<conio.h>
using namespace std;

const int MIN_BALANCE = 500;

class BankAccount{
	private:
		string name;
		int accountnumber;
		double balance;  
		
	public:
		// account creation
		void CreateAccount(string accName,int accNo,double initialDeposit){
			name = accName;
			accountnumber = accNo;
			if(initialDeposit < MIN_BALANCE){
				cout << "Initial deposit must be atleast " << MIN_BALANCE << endl;
				balance = MIN_BALANCE;
			}else{
				balance = initialDeposit;
			}
			cout << "Account created for " << name <<" who deposits " << balance <<" rupees.\n";
		}

		// Money depositing
		void depositMoney(double amount){
			if (amount > 0){
				balance += amount;
				cout << "You deposited " << amount << " amount. Now new balance is " << balance << endl; 
			}else{
				cout << "Invalid deposit amount....\n"; 
			}
		}

		// withdrawal rule (you can withdraw only 500 at a time)
		void Withdraw(double amount){
			if (amount != 500){
				cout <<"You can only withdraw 500 each time.\n";
			}else if (balance - amount < MIN_BALANCE){ 
				cout << "Withdrawal not allowed! Must keep at least " 
                << MIN_BALANCE << " in account.\n";
			}else{
				balance -= amount;
				cout << "Withdrawn 500. New balance: " << balance << endl;
			}
		}

		// show balance
		void ShowBalance(){
			cout << "Current balance: " << balance << endl;
		}
};

int main(){
	BankAccount acc;
	acc.CreateAccount("wajdan",1122,2000);
	
	cout << "========================================" << endl;
	cout << " 										 " << endl;
	cout << " 		      WELCOME TO	   		     " << endl;
	cout << "		BANKING MANAGMENT SYSTEM         " << endl;
	cout << " 										 " << endl;
	cout << "========================================" << endl;
	cout << " 										 " << endl;
	cout << " 										 " << endl;
	cout << " 										 " << endl;
	cout << "Press any key to enter.....\n"; 	
	getch();
	// for clear screen
	system("cls");

	int choice;
	do{
		cout << "BANk MENU...\n";
		cout << "1.Deposit \n2.Withdraw \n3.Show Balance \n4.Exit\n";
		cout <<"Enter choice : \n";
		cin >> choice;
	
		if(choice == 1){
			double amt;
			cout << "Enter deposit : \n";
			cin >> amt;
			acc.depositMoney(amt);	
		}else if(choice == 2){
			double amt;
			cout << "Enter withdrawal amount: \n";
			cin >> amt;
			acc.Withdraw(amt);
		}else if(choice == 3){
			acc.ShowBalance();
		}else if(choice == 4){
			cout << "Exiting program...\n";
		}else{
			cout << "Invalid Choice...\n"; ;
		}
	
	}while(choice != 4);

	return 0;
}

