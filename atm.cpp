#include <iostream>
#include <string>
using namespace std;

/*MINI PROJECT ATM...!
-> CHECK BALANCE
-> CASH WITHDRAW 
-> USER DETAILS
-> UPDATE MOBILE NO
*/

class atm {                         //class atm
    private:                        //private access specifier
        long int account_no;       //private data members

        string name;
        int pin;
        double balance;
        string mobile_no;

    public:
    	
        // Set data into private members
        void setdata(long int account_no_a, string name_a, int pin_a, double balance_a, string mobile_no_a)
		 {
		 	//assigning the formal arguments to the private data members
            account_no = account_no_a;
            name = name_a;
            pin = pin_a;
            balance = balance_a;
            mobile_no = mobile_no_a;
        }

        // Getters
        	// GetAccountNo function is returning the user account  no
        long int getaccountno()
		 { 
		 return account_no;
		  }
		  
		  // get name function is returning the user name
        string getname()
		 { 
		 return name;
		  }
		  
		  // get pin function is returning the user pin
        int getpin() 
		{
		 return pin; 
		 }
		 
		 // get balance is returning the user bank balance

        double getbalance() 
		{
		 return balance;
		  }
		  
		  	// get mobile no is returning the user mobile no
        string getmobileno() 
		{
		 return mobile_no;
		  }

           void allow()
           {
           	
           	 int choice = 0, enterpin; //enter pin and enteraccountno
			//
		 //----> user authentacitation
             long int enteraccountno;
   
           	
           	 do      //we are able to run our code multiple of time and relate this with real world atm machine
	{
        system("cls");
        
        cout << "<---_--->^<--WELCOME TO MUZAMIL ATM-->^<---_--->\n";
        cout << "Enter your account number: ";
        cin >> enteraccountno;     // asking user to enter account number
   // if account no does not match show in valid messege 
   
   if(enteraccountno != getaccountno())
   {
   	cout << endl << " invalid account no...oops*_";
   	 cin.get(); cin.get();
   	 continue ;
   	 
   }
   
        cout << "\nEnter PIN: ";  // asking user to enter pin  
        cin >> enterpin; 
		
           // check wether enter values matches with user details
	 
        if ((enteraccountno == getaccountno()) && (enterpin == getpin())) {
            do {
                int amount = 0;
                 string oldmobileno, newmobileno;

                system("cls");
                
                	// user interface 
                cout << "<--- Welcome to Muzamil ATM --->\n";
                cout << "1. Check Balance\n";
                cout << "2. Cash Withdraw\n";
                cout << "3. Show User Details\n";
                cout << "4. Update Mobile Number\n";
                cout << "5. Exit\n";
                
                cin >> choice;        //taking user choice

                switch (choice) {
                    case 1:
                        cout << "Your bank balance is: " << getbalance() << endl;
                        
                        // get balance is ---> printing the users bank balance
                        cin.get(); cin.get();
                        break;

                    case 2:          //if user press 2
                        cout << "Enter the amount: ";
                        cin >> amount;        // passing the withdraw amount
                        
                        cashwithdraw(amount); // calling cash withdraw function
                        cin.get(); cin.get();
                        break;

                    case 3:            //if user press 3
                        cout << "User Details:\n";
                        cout << "Account No: " << getaccountno() << endl;
                        cout << "Name: " << getname() << endl;
                        cout << "Balance: " << getbalance() << endl;
                        cout << "Mobile No: " << getmobileno() << endl;
                        cin.get(); cin.get();
                        // getting and printing user details 
                        break;

                    case 4:           // if user press 4
			
                        cout << "Enter old mobile number: ";
                        cin >> oldmobileno;   // take old mobile no
                        
                        cout << "Enter new mobile number: ";
                        cin >> newmobileno;    //take new mobile no

                        setmobile(oldmobileno, newmobileno);//now set new mobile no
                        cin.get(); cin.get();
                        break;

                    case 5:  // if user press 5
                        exit(0);   // exit application



                    default:         //handle invalid inputs
                        cout << "Enter valid option.\n";
                        cin.get(); cin.get();//to pause screen untill user press no
                        break;
                }
            } while (1); // menu // condition will always true and loop is cappable of running infinite items...
        } else {
            cout << "\nInvalid Account Number or PIN.\n";
            cin.get(); cin.get();
        }

    } while (1);

		   }
        // Set new mobile number if old matches
         // set mobile function is updating the user mobile no
        void setmobile(string mob_prev, string mob_new)
		 {
            if (mob_prev == mobile_no)   // it will check the old mobile no
            
			 {
                mobile_no = mob_new; // and update with new,if old matches
                cout << "\nSuccessfully updated the mobile number.\n";
            } 
			
			else       // does not update if old mobile no does not matches
			
			{
                cout << "\nIncorrect old mobile number.\n";
            }
        }

        // Cash withdrawal
        void cashwithdraw(int amount_a) 
		{
            if (amount_a > 0 && amount_a < balance) // check entered amount validity

			
			{
                balance -= amount_a;    //balance = balance - amount_a
                cout << "\nPlease collect your cash.\n";
                cout << "Available balance: " << balance << endl;
        	
		
      char recipt_choice;
        // asking the user to take recipt or not
		cout << endl << " do u want a recipt ? ( y / n) : ";
		
		cin >> recipt_choice;
		if( recipt_choice == 'Y' || recipt_choice == 'y')
		{
			system( " cls ");//clear the screen and simulate a new recipt print out
		//	printrecipt ( amount_a );// print the recipt if the user says yes
			cout << endl << " printing recipt--->";
		 } 
		 else if( recipt_choice == 'n'|| recipt_choice == 'N')
    	{
		 	
		 cout << endl << " NO I DONT WANT...! ";
		 }
		  
			else {
                cout << "\nInvalid input or insufficient balance sorry..<->\n";
            }
        }
    }
      
};

int main() {
    // create user object
    atm user1;
    //set user details ( into objects )     ( setting default data )
    user1.setdata(1062, "Muzamil", 1111, 50000.90, "0987654321");
    user1.allow();
	//  return 0;
}
