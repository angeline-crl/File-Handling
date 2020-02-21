//code by angeline-crl
#include <fstream>
#include <iostream>
using namespace std;

int choice;
int k=0;

//structure to define player
struct player{
	char nick[50][50];	
	int age[50];
	int s1[50], s2[50];
	int ave[50];
}p;

void display();
void addrec();
void showave();
void max();
void min();
void reset();

int main(){

while(1){
	cout << " ------------------------------"
		 << "\n            M E N U"
		 << "\n ------------------------------"
		 << "\n\n [1] Add Record"
		 << "\n [2] View Players Records"
		 << "\n [3] Compute for the Average"
		 << "\n [4] Show the player(s) "
		 << "\n     who has the MAX Average."
		 << "\n [5] Show the player(s) "
		 << "\n     who has the MIN Average."
		 << "\n\n [0] Exit"
		 << "\n\n Enter # of Choice: "
		 << "\n     >> ";
	cin >> choice;

	switch(choice){
		case 1:
			//limit to 5 players
			if(k<5){
			addrec();
			reset();
			}
			
			else if(k>=5){
				cout << "\n   *[ OOPS ] Cannot Add more than 5 Players.";
				reset();
			}
			break;
		
		case 2:
			display();
			reset();
			break;
		
		case 3:
			showave();
			reset();
			break;
			
		case 4:
			max();
			reset();
			break;
		
		case 5:
			min();
			reset();
			break;
		
		case 0:
			exit(0);
			break;
			
		default:
			cout << "\n   *[ OOPS ] Invalid Choice. Please Try Again.";
			reset();
			break;
	}
}
	return 0;
}

//function to view all player records in txt file
void display(){
	int i;
	ofstream outFile;
	outFile.open("players.txt");
	
	outFile << " ------------------------------"
		 << "\n          PLAYER RECORD"
		 << "\n ------------------------------";
	
	outFile << "\n\n";
	if(k!=0){
		for(i=0; i<k ; i++){
			outFile << " Player " << i+1 << " :\t" << p.nick[i] << endl;
			outFile << " Age: \t\t" << p.age[i] << endl;
			outFile << " Score #1: \t" << p.s1[i] << endl;
			outFile << " Score #2: \t" << p.s2[i] << endl;
			outFile << endl;
		}
	system("notepad players.txt");
	}
	//if no records are added
	else{
		cout << "\n   *[ OOPS ] No Player Record Found";
		outFile << "\n [ No Player Record Found ]";
	}
	
	outFile.close();
}

//function to add player record
void addrec(){
	int i;
	system("cls");
	cout << " ------------------------------"
		 << "\n           ADD RECORD"
		 << "\n ------------------------------";
	
	cout << "\n\n [ Player " << k+1 << " ]";
	
	//loop to store player's info
	//only stores one player when add record is selected
	for(i=k; i<k+1; i++){
		cout << "\n\n > Nickname: \t\t";
		cin >> p.nick[i];
		
		cout << " > Age: \t\t";
		cin >> p.age[i];
		
		cout << " > Best Score 1: \t";
		cin >> p.s1[i];
		
		cout << " > Best Score 2: \t";
		cin >> p.s2[i];
	}
		
	//loop to compute average then store to array
	for(i=k; i<k+1; i++){
		p.ave[i] = (p.s1[i] + p.s2[i])/2;
	}
	k++;
	cout << "\n   *[ SUCCESS ] Player " << k << " added to Records";
}

//function to print average of all players
void showave(){
	int i;
	ofstream outFile;
	outFile.open("average.txt");
	
	outFile << " ------------------------------"
		 << "\n          PLAYER AVERAGE"
		 << "\n ------------------------------";
		 
	outFile << "\n\n";
	if(k!=0){
		for(i=0; i<k ; i++){
			outFile << " P#" << i+1 << "'s Average: " << p.ave[i] << " (" << p.nick[i] << ")";
			outFile << endl;
		}
	system("notepad average.txt");
	}
	//if no players added:
	else{
		cout << "\n   *[ OOPS ] No Player Record Found";
		outFile << "\n [ No Player Record Found ]";
	}
	outFile.close();
}

//function to find maximum average among players
void max(){
	int i;
	int max = p.ave[0];
	
	ofstream outFile;
	outFile.open("average.txt");
	
	//loop to go thru array
	for(i=0; i<k; i++){
		if(max < p.ave[i]){
			max = p.ave[i];
		}
	}
	
	outFile << " ----------------------------------------"
		<< "\n         PLAYER/S with Max. AVERAGE"
		<< "\n ----------------------------------------";
	
	outFile << "\n\n";
	if(k!=0){
		outFile << " Maximum Average: " << max;
		
		outFile << "\n\n Players with Max. Average: \n";
		for(i=0; i<k; i++){
			if(max==p.ave[i]){
				outFile << " > " << p.nick[i] << endl;
			}
		}
	system("notepad average.txt");
	}
	else{
		cout << "\n   *[ OOPS ] No Player Record Found";
		outFile << "\n [ No Player Record Found ]";
	}
	
	outFile.close();
}

void min(){
	int i;
	int min = p.ave[0];
	
	ofstream outFile;
	outFile.open("average.txt");
	
	//loop to go thru array
	for(i=0; i<k; i++){
		if(min > p.ave[i]){
			min = p.ave[i];
		}
	}
	
	outFile << " ----------------------------------------"
		<< "\n         PLAYER/S with Min. AVERAGE"
		<< "\n ----------------------------------------";
	
	outFile << "\n\n";
	if(k!=0){
		outFile << " Minimum Average: " << min;
		
		outFile << "\n\n Players with Min. Average: \n";
		for(i=0; i<k; i++){
			if(min==p.ave[i]){
				outFile << " > " << p.nick[i] << endl;
			}
		}
	system("notepad average.txt");
	}
	else{
		cout << "\n   *[ OOPS ] No Player Record Found";
		outFile << "\n [ No Player Record Found ]";
	}
	
	outFile.close();
}

//function to return to menu loop (clear screen)
void reset(){
	cout << "\n\n Press Any Key to Return to Menu "
		 << "\n     >>";
	system("pause>0");
	system("cls");
}
