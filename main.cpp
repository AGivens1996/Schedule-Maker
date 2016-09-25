#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	//variable declarations
	const int nameCharLim = 30;
	char teamName[nameCharLim] = {};
	const char emptyName[nameCharLim] = {};
	char unavailable[50] = {};
	const char empty[50] = {};
	int age = 0;
	int iter = 0;
	int tries = 0;
	string name, sport, league, nightNull, answer, dummy;
	bool correct = false;
	bool check = false;
	
	cout << "Welcome to the schedule maker.\n"
		 << "------------------------------\n";
	do{
		tries += 1;
		cout << "\nPlease enter your team name: ";
		if(tries > 1)
			getline(cin, dummy);
		getline(cin, name, '\n');
		strcpy(teamName, name.c_str());
		// Sport selection loop
		do{
			cout << "\nPlease select your sport"
				 << "\n------------------------\n"
				 << "1) Baseball\n"
				 << "2) Softball\n"
				 << "3) Soccer\n"
				 << "Enter the number associated with your sport: ";
			cin >> sport;
			if(sport == "Baseball" || sport == "baseball" || sport == "1"){
				sport = "Baseball";
			} else if(sport == "Softball" || sport == "softball" || sport == "2"){
				sport = "Softball";
			} else if(sport == "Soccer" || sport == "soccer" || sport == "3"){
				sport = "Soccer";
			} else{
				cout << "I'm sorry the sport you've chosen is invalid.\n";
			}
		} while(sport != "Baseball" && sport != "Softball" && sport != "Soccer");
	
		//Enter age group loop
		do{
			cout << "\nPlease enter your age group: ";
			cin >> age;
			if(age < 6 || age > 12)
				cout << "I'm sorry the age you entered is invalid.\n";
		} while(age < 6 || age > 12);
		
		// league selection loop
		if(sport == "Baseball"){
			if(age < 9){
				league = "Coach Pitch";
				getline(cin, dummy);
			}else if(age == 9){
				iter = 0;
				do{
					iter += 1;
					cout << "\nPlease select your league:\n"
						 << "1) Coach Pitch\n"
						 << "2) Modified Player Pitch\n"
						 << "3) Player Pitch\n"
						 << "4) Competitive Player Pitch\n"
						 << "Please enter the number associated with your league: ";
					if(iter == 1)
						getline(cin, dummy);
					getline(cin, league, '\n');
					if(league == "1" || league == "Coach Pitch" || league == "Coach pitch" || league == "coach pitch"){
						league = "Coach Pitch";
					} else if(league == "2" || league == "Modified Player Pitch" || league == "Modified Player pitch" || league == "Modified player pitch" || league == "modified player pitch"){
						league = "Modified Player Pitch";
					} else if(league == "3" || league == "Player Pitch" || league == "Player pitch" || league == "player pitch"){
						league = "Player Pitch";
					} else if(league == "4" || league == "Competitive Player Pitch" || league == "Competitive Player pitch" || league == "Competitive player pitch" || league == "competitive player pitch"){
						league = "Competitive Player Pitch";
					} else{
						cout << "I'm sorry the league you've chosen is invalid.\n\n";
					}
				} while(league != "Coach Pitch" && league != "Modified Player Pitch" && league != "Player Pitch" && league != "Competitive Player Pitch");
				iter = 0;
			} else{
				iter = 0;
				do{
					iter += 1;
					cout << "\nPlease select your league:\n"
						 << "1) Player Pitch\n"
						 << "2) Competitive Player Pitch\n"
						 << "Please enter the number associated with your league: ";
					if(iter == 1)
						getline(cin, dummy);
					getline(cin, league, '\n');
					if(league == "1" || league == "Player Pitch" || league == "Player pitch" || league == "player pitch"){
						league = "Player Pitch";
					} else if(league == "2" || league == "Competitive Player Pitch" || league == "Competitive Player pitch" || league == "Competitive player pitch" || league == "competitive player pitch"){
						league = "Competitive Player Pitch";
					} else{
						cout << "I'm sorry the league you've chosen is invalid.\n\n";
					}
				} while(league != "Player Pitch" && league != "Competitive Player Pitch");
				iter = 0;
			}
		}
		if(sport == "Softball"){
			
		} 
		
		// unavailable nights
		cout << "\nWhich nights are you unable to play? (separate each night with a semicolon; ex, 'Monday; Thursday')\n";
		getline(cin, nightNull, '\n');
		strcpy(unavailable, nightNull.c_str());
		
		cout << "\nPlease confirm that all the information is correct:\n"
			 << "\tTeam Name: ";
		for(int i = 0; i < nameCharLim; i++){
			if(teamName[i] != '\n'){
				cout << teamName[i];
			}else
				i = nameCharLim;
		}
		cout << "\n\tAge: " << age 
			 << "\n\tSport: " << sport
			 << "\n\tLeague: " << league
			 << "\n\tUnavailable Night(s): ";
		for(int i = 0; i < 50; i++){
			if(unavailable[i] != '\n'){
				cout << unavailable[i];
			}else
				i = 50;
		}
		
		cout << "\n\nIs the above information correct? ";
		cin >> answer;
		do{
			if(answer == "Y" || answer == "y" || answer == "Yes" || answer == "yes" || answer == "YES"){
				correct = true;
				check = true;
			}
			else if(answer == "N" || answer == "n" || answer == "No" || answer == "no" || answer == "NO"){
				correct = false;
				check = true;
				for(int i = 0; i < nameCharLim; i++){
					teamName[i] = emptyName[i];
				}
				for(int i = 0; i < 50; i++){
					unavailable[i] = empty[i];
				}
			}
			else
				check = false;
		} while(!check);
	} while(!correct);
	return 0;
}
