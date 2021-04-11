#include <iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include <windows.h>
using namespace std;
//struct declaration
struct personalDetails{
	string fname;
	string lname;
};
struct payment{
	int company;
	string cardNum;
	string pin;
	char validate;
};
struct room{
	personalDetails name;
	payment validated;
	int rtype,nights;
	double pnight;
	int unitNumber;
};
//global
int size;
int company;
int cardNum;
int pin;
int i;//index
personalDetails custoName;

//function declaration
int mainChoice();
void roomDetails();
int getInput(room xunits[]);
void selectUnit(room xunits[]);
int paymentDetails();
int calcTotal(room xunits[]);
int processPayment(room xunits[],double *xt);
void saveDetails(room xunits[]);
int main(){
	system("color 0c");
	char *p1;
	p1 = new char;
	*p1 = mainChoice();
	
	
	if(*p1 == 'R' || *p1 == 'r'){
		room units[size];
		cout << "First Name: ";
		cin.ignore();
  	 	getline(cin,custoName.fname);
		cout << "Last Name: ";
   		getline(cin,custoName.lname);
		cout << "How many rooms would you like to reserve?: ";
		cin >> size;
		cout << "Loading";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		system("cls");
		roomDetails();
		getInput(units);	
	}else if(*p1 == 'E' || *p1 == 'e'){
		cout << "Goodbye!!!";
		Sleep(500);
	}
	cout << endl << endl;
	system("pause");
	delete p1;
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int mainChoice(){
	char xchoice;
	cout << "\n\tHotel Sogo\n\tEGI Rufino Plaza Condominium, Pasay\n\tTel:896270069\n\twww.hotelsogo.com.ph\n\n\n";
	cout << "(R) Reserve a room" << endl;
	cout << "(E) Exit" << endl << endl;
	cout << "Choose an option: ";
	cin >> xchoice;
	return xchoice;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void roomDetails(){
	cout << "ROOM DETAILS" << endl << endl;
	cout << "[1] Suite (1 to 2 persons) - $469.00 per night" << endl;
	cout << "[2] Deluxe Room (1 to 2 persons) - $424.00 per night" << endl;
	cout << "[3] Premium Room (1 to 2 persons) - $344.00 per night" << endl;
	cout << "[4] Premium Room (3 persons) - $388.00 per night" << endl;
	cout << "[5] Premium Room (4 persons) - $433.00 per night" << endl;
	cout << "[6] Standard Room (1 or 2 persons) - $317.00 per night" << endl;
	cout << "[7] Standard Room (3 persons) - $362.00 per night" << endl;
	cout << "[8] Standard Room (4 persons) - $406.00 per night" << endl;
	cout << "[9] Go Back" << endl << endl;
	cout << "WELCOME " << custoName.fname << "!" << endl << endl;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getInput(room xunits[]){
	//int rtype,nights;
	double *totalAmountPayable;
	
	totalAmountPayable = new double;
	for(i=0;i<size;i++){
	cout << "Room No.: " << i+1 << endl << endl;
	cout << "Choose type of room: ";
	cin >> xunits[i].rtype;
	switch(xunits[i].rtype){
		case 1:
			xunits[i].pnight = 469.00;
			break;
		case 2:
			xunits[i].pnight = 424.00;
			break;
		case 3:
			xunits[i].pnight = 344.00;
			break;
		case 4:
			xunits[i].pnight = 388.00;
			break;
		case 5:
			xunits[i].pnight = 433.00;
			break;
		case 6:
			xunits[i].pnight = 317.00;
			break;
		case 7:
			xunits[i].pnight = 362.00;
			break;
		case 8:
			xunits[i].pnight = 406.00;
			break;
		case 9:
			cout << "Loading";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			system("cls");
			main();
			break;
		default:
			cout << endl << "Invalid option" << endl << endl;
			Sleep(500);
			break;
	}
	if(xunits[i].rtype>0 && xunits[i].rtype < 10){
	
	cout << endl << endl;
	
	cout << "Enter number of nights of stay: ";
	cin >> xunits[i].nights;
	}
}
	*totalAmountPayable = calcTotal(xunits);
	
	cout << "\n\nCalculating";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << endl << endl;
	cout << fixed << setprecision(2);
	cout << "Total Amount Payable: $" << *totalAmountPayable << endl << endl;
	Sleep(500);
	system("pause");
	system("cls");
	selectUnit(xunits);
	processPayment(xunits,totalAmountPayable);
	
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void selectUnit(room xunits[]){
	int x=0;
	int unit;
	string firstName;
	string lastName;
	int nightStay;
	int target;
	ifstream Qin;
	Qin.open("records.txt");
	int unitSelect[8][10];
	for(i=0;i<8;i++){
		for(int j=0;j<10;j++){
			unitSelect[i][j] = (i+1)*10 + (j+1);
		}
	}
	
	for(i=0;i<8;i++){
		for(int j=0;j<10;j++){
			cout << unitSelect[i][j] << " ";
		}
		cout << endl << endl;
	}
	for(i=0;i<size;i++){
		cout << "Select unit for room " << i+1 << ": ";
		cin >> target;
		while(Qin >> unit >> firstName >> lastName >> nightStay){
			if(target == unit){
				cout << "\n\nRoom is not available. Please select another room." << endl;
				selectUnit(xunits);
			}		
		}
		Qin.close();
		xunits[i].unitNumber = target;
	
	
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int calcTotal(room xunits[]){
	double *xt;
	xt = new double;
	for(i=0;i<size;i++){
		*xt = *xt + (xunits[i].pnight * xunits[i].nights);
	}
	return *xt;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int processPayment(room xunits[], double *xt){
	payment method;
	cout << "PAYMENT SECTION" << endl << endl;
	cout << "(1) Master Card" << endl;
	cout << "(2) Visa" << endl;
	cout << "(3) Debit Card" << endl;
	cout << "(4) Cancel transaction" << endl << endl;
	cout << "Choose your card's company: ";
	cin >> method.company;
	
	if(method.company == 4){
		cout << "Transaction Cancelled." << endl;
	}else{	
	cout << "\n\nContacting your card's company";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << endl;
	cout << "Waiting for response";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "\nConnection successful.";
	
	cout << "\n\nEnter card number: ";
	cin.ignore();
	getline(cin,method.cardNum);
	cout << "\nEnter Security Code/PIN: ";
	getline(cin,method.pin);
	cout << "\n\nVerifying your card";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << endl << endl;
	
	if(method.cardNum.length() == 16 && method.pin.length() == 3){
		cout << "Verification Successful." << endl;
		cout << fixed << setprecision(2);
		cout << "You will be charged a total of $" << *xt << endl;
		cout << "Is all of the details correct? (Y/N): ";
		cin >> method.validate;
		method.validate = tolower(method.validate);
		system("cls");
		if(method.validate == 'y'){
			for(int i=0;i<=100;i++){
				cout << "Processing: " << i << "%";
				Sleep(200);
				system("cls");
			}
			cout << endl << endl;
			cout << "Sending transaction details to your card's company";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << "\n\nWaiting for response";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << "\n\nTransaction successful!!!" << endl << endl;
			saveDetails(xunits);
			cout << "All done!!! Just present 2 valid IDs upon checking in for identity verification." << endl << endl;	
		}else if(method.validate == 'n'){
			cout << "Transaction failed." << endl << endl;
		}else{
			cout << "Error: Invalid Input" << endl << endl;
		}
	}else{
          cout << "ERROR: Invalid Card." << endl << endl;
    }
}
		system("pause");
		cout << "\n\nRedirecting you back to the home page";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		system("cls");
		main();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void saveDetails(room xunits[]){
	ofstream hout;//output streaming
	
	//open the file
	hout.open("records.txt",ios::app);
	
	for(i=0;i<size;i++)
		hout << xunits[i].unitNumber << " " << custoName.fname << " " << custoName.lname << " " << xunits[i].nights << endl;
	
		
	
	cout << "Data has been saved." << endl << endl;
	hout.close();
}
