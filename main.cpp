/*Design a project to represent a bank account and its relevant operations, where following details
can be maintained:
1. Depositor name,
2. account number(you may define any starting number),
3. type of account,
4. balance amount in the account.
5. Any other attribute required you may add it by your own 
Also, the following set of operations/actions should be provided:
1. Add new customers to the bank who become an account holder.
2. Display a list of all the account holders of the bank along with their account numbers and
balance.
3. Delete the information related to the account holder from the customer data file
4. Update the balance after customer has performed a deposit or withdraw transaction
5. display the account number of the last entry
6. check whether an account exists or not
7. retrieve the name of the account holder
8. retrieve the address of the account holder
9. retrieve the balance of the account holder
10. returns the record number from the customer file when an employee of the bank enters
the account number related to an account holder(Transaction details along with the
account information)
11. displays all the information related to an account holder from the customer file on the
basis of specified account number.
12. Calculate the interest to date on the deposit if a particular customer has not withdrawn
for more than a month*/
//Author:Vaibhavi Bulbule
//Date:10/10/21
#include <iostream>
#include<string.h>
using namespace std;
//creating a class named bank 
class bank
{
  public:
  int accNo;
  double accBal;
  char depName[20];
  char accType[7];
  char address[30];
  
  //function to get the details of the customer
  void get(char *n,int aNum,char *acc_type,double bal,char *addr){
   
    strcpy(depName,n);
    strcpy(accType,acc_type);
    accNo=aNum;
    accBal=bal;
    strcpy(address,addr);
  }

//function to withdraw the amount
double withdraw(){
  double amt,amount;
  cout<<"Enter the amount to be withdraw\n";
  cin>>amt;
  if(amt>accBal)
    cout<<"\nInsufficient Amount";
  else
     amount=accBal-amt;
    accBal= amount;
     cout<<"Account Balance-> "<<accBal<<"\n";
     cout<<"\n";
    return accBal;
  
}

//Function to deposit the amount
double deposit(){
  double amt;
  cout<<"Enter the amount to be deposit:\n";
  cin>>amt;
  double amount=accBal+amt;
  accBal=amount;
  cout<<"Account Balance-> "<<accBal<<"\n";
  cout<<"\n";
  return accBal;
}

//Function to display the details of the account holder
void display(){
  cout<<"Account Number->"<<accNo<<endl;
  cout<<"Name of the depositor->"<<depName<<endl;
  cout<<"Account Type->"<<accType<<endl;
   cout<<"Balance->"<<accBal<<endl;
   cout<<"Address->"<<address;
   cout<<"\n";
}
};

//Project starts executing from the main function
int main() {

//creating the object named customer of the bank
bank customer;

//Initialing variables using struct
 struct bank1{
 int acNo;
 char name[20], accTyp[7],adr[30];
 double acbal;
 }b[10];
 int num;

 //Adding new customers to the bank
  cout<<"Enter number of new customers to be added to the bank\n";
  cin>>num;
  for(int i=0;i<num;i++){
  cout<<"Enter "<<i+1<<" customer details:\n";
  cout<<"\nEnter your Accout No :";
  cin>>b[i].acNo;
  cout<<"\nEnter your Full Name :";
  cin>>b[i].name;
  cout<<"\nEnter your Account Type :";
  cin>>b[i].accTyp;
  cout<<"\nEnter your Balance :";
  cin>>b[i].acbal;
  cout<<"\nEnter the address :";
  cin>>b[i].adr;
  cout<<"\n\n";
  
  customer.get(b[i].name, b[i].acNo, b[i].accTyp, b[i].acbal, b[i].adr);
  }
  //Displaying a list of all the account holders
  cout<<"\n\nList of all account holders of the bank";
  for(int i=0;i<num;i++){
    cout<<"Account Number->"<<b[i].acNo<<endl;
    cout<<"Name of the depositor->"<<b[i].name<<endl;
    cout<<"Account Type->"<<b[i].accTyp<<endl;
    cout<<"Balance->"<<b[i].acbal<<endl;
    cout<<"Address->"<<b[i].adr<<endl;
    cout<<"\n\n";
  }

  //update the balance after customer has performed a transaction
  int aNo;
  cout<<"Enter the customers account number whose balance needs to be updated\n";
  cin>>aNo;
  for(int i=0;i<num;i++){
    if(b[i].acNo==aNo){
      int choose;
      cout<<"\nChoose any operation to perform.\n1.Deposit\t2.Withdraw\t3.display"<<endl;
      cin>>choose;
  
      switch(choose)
      {
   
      case 1:customer.deposit();
        break;
      case 2:customer.withdraw();
        break;
      case 3:customer.display();
        break;
    }
    }
  }
  //Displaying the account number of the last entry
  cout<<"Account number of the last entry : "<<b[num-1].acNo;

  //Checking whether an account exists or no
  
  cout<<"\nEnter the account number to check whether it exists or no\n";
  cin>>aNo;
  for(int i=0;i<num;i++){
    if(b[i].acNo==aNo){
      cout<<"\nAccount exists\n";
    }
    else{
      cout<<"\nAccount does not exists";
    }
  }

  //Retrieve the name of the account holder
  cout<<"\nEnter the account number to retrieve the name of the account holder\n";
  cin>>aNo;
  for(int i=0;i<num;i++){
    if(b[i].acNo==aNo){
      cout<<"\nAccount holder name : "<<b[i].name;
    }
  }

  //Retrieve the balance of the account holder
  cout<<"\nEnter the account number to retrieve the balance of the account holder\n";
  cin>>aNo;
  for(int i=0;i<num;i++){
    if(b[i].acNo==aNo){
      cout<<"\nAccount holder balance : "<<b[i].acbal;
    }
  }

  //Retrieve the address of the account holder
  cout<<"\nEnter the account number to retrieve the address of the account holder\n";
  cin>>aNo;
  for(int i=0;i<num;i++){
    if(b[i].acNo==aNo){
      cout<<"\nAccount holder address : "<<b[i].adr;
    }
  }

  //Displaying all the information related to account holder on the basis of account number
  cout<<"\nEnter the account number to display all the information \n";
  cin>>aNo;
  for(int i=0;i<num;i++){
    if(b[i].acNo==aNo){
      customer.display();
    }
  }
  return 0;

}