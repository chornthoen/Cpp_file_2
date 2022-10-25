
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    //ex1. input username and write into text file if a user input stop then a program stop input..

    string username;
    ofstream fileInput;
    char *fileIn="username.txt";
    fileInput.open(fileIn, ios::out);
    while (1){
        cout << "Enter username: ";
        getline(cin, username);
        if (username == "stop"){
            cout<<"The program is stop."<<endl;
            break;
        }
        fileInput << username<<endl;
        cout<<username<<" adding "<<endl;
    }
    fileInput.close();

    //ex2. read a username one by one from file....

    ifstream fileRead;
    char *file = "username.txt";
    fileRead.open(file, ios::in);
    string line;
    cout<<"Read from file: "<<file<<endl;
    while (getline(fileRead, line)){
        cout << line << endl;
    }
    fileRead.close();
    //ex3 using searching a username in file

    string search;
    cout<<"Enter username for searching: ";
    getline(cin, search);
    fileRead.open(file, ios::in);
    while (getline(fileRead, line)){
        if (line == search){
            cout<<"Found is username : "<<search<<" of "<<file<<endl;
            break;
        }

    }
    fileRead.close();

    //ex4. appending some username into file and read username ,and count number of username in file

    fileInput.open(fileIn, ios::app);
    cout<<"Enter username for appending: "<<endl;
    while (1){
        cout << "Enter username: ";
        getline(cin, username);
        if (username == "stop"){
            cout<<"The program is stop."<<endl;
            break;
        }
        fileInput << username<<endl;
        cout<<username<<" adding "<<endl;
    }
    fileInput.close();

    fileRead.open(file, ios::in);
    int count=0;
    cout<<"Read from file: "<<file<<endl;
    while (getline(fileRead, line)){
        count++;
        cout <<"username : "<<line << endl;
    }
    cout<<"Number of username in file is "<<count<<endl;
    fileRead.close();

    //ex5. delete a username from file

    string deleteUsername;
    cout<<"Enter username for deleting: ";
    getline(cin, deleteUsername);
    fileRead.open(file, ios::in);
    ofstream fileTemp;
    char *fileOld="temp.txt";
    fileTemp.open(fileOld, ios::out);
    while (getline(fileRead, line)){
        if (line != deleteUsername){
            fileTemp << line<<endl;
        }
    }
    fileRead.close();
    fileTemp.close();

    remove(file);
    rename(fileOld, file);
    cout<<"Delete username "<<deleteUsername<<" from file "<<file<<endl;


    fileRead.open(file, ios::in);
    cout<<"Read from file: "<<file<<endl;

    while (getline(fileRead, line)){
        cout <<"username : "<<line << endl;
    }
    fileRead.close();

    return 0;
}


