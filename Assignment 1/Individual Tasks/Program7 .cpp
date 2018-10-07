// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 2 - Problem 7
// Program: Marathon
// Author:  Belal Hamdy Ezzat
// Date:    10 August 2018
// Version: 1.0
// Student Name : Belal Hamdy Ezzat
// Student ID : 20170077
// Student Group : G_3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2e2+5;
const double tDist = 13.1, EPS = 1e-9 ;
double sensors[N] = {0,1,7,13.1} ; // the first sensor is always fixed at 0
const int sensorsN = 3;
struct Racer
{
    bool cheat ;
    int id ;
    int time[sensorsN+5];
    double split[sensorsN+5];
    long long totalT = 0 ;
};
struct LogLine
{
    int senID, racerID, rH, rM, rS ;
    char delimiter;
};

istream& operator>> (istream& in, LogLine& line);
ostream& operator<< (ostream& in, LogLine& line);

int toSec (int h, int m, int s)
{
    return (h*60*60 + m * 60 + s);
}

int findId (int id, Racer arr[], int siz)
{
    for (int i = 0 ; i<siz ; ++i)
    {
        if (arr[i].id == id ) return i ;
    }
    return -1 ;
}

int main()
{
    startProg:
    char rep = '0';
    LogLine logs[N] ; //file data
    int readIdx=0;
    Racer marathon[N] ; // racers
    int idx = 0,sensorsidx = -1, rnk = 1;
    int sH, sM, sS, senID, racerID, startT, rT;// start hour , start minute , start second , sensor number , racer number , racing start time , racer time
    int currID ;//current racer id
    double timeDiff, disDiff; //time difference , distance difference
    string fileName;
    ifstream logFile;
    do
    {
        cout << "Enter the name of the log file without extensions (\".txt\") : ";
        getline(cin,fileName);
        fileName+=".txt";
        logFile.open(fileName, ios :: in);
        if (logFile) break;
//      cin.ignore(INT_MAX,'\n');
        cout << "\nError in opening File please make sure that the file exist or you entered the name correctly and try again.\n\n";
    }
    while (!logFile);
    cout << "\nFile opened successfully ^_^ .\n\n\n";
    logFile >> sH >> sM >> sS;
    startT = toSec(sH, sM, sS);
    while (!logFile.eof())
    {
        logFile>>logs[readIdx++];
    }
    logFile.close();
    sort(logs, logs+(readIdx-1), [](LogLine a, LogLine b)  //EOF gives the last input of 0 so i need to ignore it
    {
        return a.senID < b.senID;
    }); // sorting the logs according to sensors
    for (int i = 0 ; i<N ; ++i)
    {
        // don't fill the 0 index because i assumed that there is a sensor at the start and all of them cut it at 0 sec
        marathon[i].time[0] = 0 ;
        memset ((marathon[i].time)+1, -1, sizeof (marathon[i].time));   // makes the time equals negative value to know if the sensor is cut by the racer or not
    }
    for (int i = 0 ; i<readIdx-1 ; ++i)
    {
        senID = logs[i].senID, racerID = logs[i].racerID ;
        ++senID; //make the ID 1-based
        sensorsidx = max(sensorsidx, senID);
        rT = toSec(logs[i].rH, logs[i].rM, logs[i].rS) - startT;
        currID = findId (racerID, marathon, idx);
        if (! ~currID) // if the racer does not exist increase the array size and put this id in the array
        {
            currID = idx++;
            marathon[currID].id = racerID;
            marathon[currID].cheat = 0 ;
        }
        Racer& currRacer = marathon[currID]; // making a reference on the player to make it easy to deal with it
        currRacer.time[senID] = rT;
        currRacer.totalT += rT;
        disDiff = sensors[senID] - sensors[senID-1];
        timeDiff = currRacer.time[senID] - currRacer.time[senID-1];
        timeDiff = timeDiff/60.0 ; //changes from seconds to minutes
        if (abs (disDiff) <= EPS) currRacer.split[senID] = 0 ; // avoid 0 division
        else if (currRacer.time[senID-1] < 0 ) currRacer.cheat = 1 ;
        else if (!currRacer.cheat) currRacer.split[senID] = abs(timeDiff / disDiff);
    }
    sort(marathon, marathon+idx, [](Racer a, Racer b)
    {
        return a.totalT < b.totalT;
    }); // sorting the racers according to their total time
    for (int i = 0 ; i<idx ; ++i)
    {
        Racer& curr = marathon[i]; // making a reference on the player to make it easy to deal with it
        if (curr.cheat)
        {
            cout << "Player number : " << rnk << "\t ID : " << curr.id << "\t He is a cheater!!!\n\n"; //dont increase the rank as he is a cheater
            continue;
        }
        cout << "Player number : " << rnk++ << "\t ID : " << curr.id << "\t His total time : " << curr.totalT/60.0 << "  Minutes" << endl << "His split rates (min/mile) : " <<endl ;
        for (int j = 1 ; j<=sensorsidx ; ++j )
        {
            cout <<setw(33) <<setprecision(5)<< curr.split[j] <<"  min/mile."<<endl;
        }
        cout <<"\nHis total average is : " << setw(10) << (curr.totalT/60.0)/tDist<< "  min/mile." <<endl << endl;
    }
    cout << "Please enter 0 to exit and any another letter or number to repeat... ";
    cin >> rep;
    cin.ignore(INT_MAX,'\n');
    if (rep-'0') goto startProg ;
    return 0;
}
istream& operator>> (istream& in, LogLine& line)
{
    in>> line.senID >> line.delimiter >>line.racerID >> line.delimiter >> line.rH >> line.rM >> line.rS ;
    return in ;
}
ostream& operator<< (ostream& in, LogLine& line)
{
    in<< line.senID << "  " << line.delimiter<< "  " <<line.racerID<< "  " << line.delimiter<< "  " << line.rH<< "  " << line.rM << "  "<< line.rS <<endl;
    return in ;
}
