#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;


void bubbleSort(string arr[][22], int n, int start){
int i, j;
string temp[22];

  for(int i = start; i < n; i++){
    for(int j = 1; j < n-1-i; j++){
       	  if(arr[j][1] > arr[j+1][1]){
	     for(int k = 0; k < 22; k++){
	     temp[k] = arr[j][k];	
	     }
	     for(int k = 0; k < 22; k++){
		arr[j][k] = arr[j+1][k];
	     }
             for(int k = 0; k < 22; k++){
		arr[j+1][k] = temp[k];	
	     }
	
	  }	
   
	}
  }

}

void twoProcess(string arr[][22]){

	pid_t pid;
	pid = fork();

	if(pid >= 0){
		if(pid == 0){
		//this is the one it's actually doing
		bubbleSort(arr,4911,0);
	
		}
	}
	//this part is not getting sorted for some reason
	bubbleSort(arr,4911,4911);	
}

int main() 
{

	
   	 time_t startTime;
	time_t final;
	time_t endTime;
	
	

	ifstream inFile;
	inFile.open("all_month.csv");
	if(!inFile){
	cerr << "Unable to open the file.";
	}

	string buffer;
	char * buffer2;
	int i=0;
	int num_quakes;
	string arr[22];
	string earthquakes[9882][22];
	char * cstr;
	char * current;
	while(!inFile.eof()){	
		getline(inFile, buffer);
		cstr = NULL;
		current = NULL;
		char * cstr = const_cast<char*>(buffer.c_str());
		int j = 0;
		current = strtok(cstr,",");
	     while(current != NULL){
		arr[j] = current;
		current = strtok(NULL, ",");
		j++;
	   	  }
	//copy each string in arr to an element in earthquakes[i][----]
	for(int k = 0; k < 22; k++){
	earthquakes[i][k] = arr[k];	
	}
	i++;
	}

	/*//time for one process
	time(&startTime);		
	bubbleSort(earthquakes,9822,0);
	time(&endTime);
	final = difftime(endTime,startTime); 
	cout << final << " seconds"; */

	twoProcess(earthquakes);

return 0;
}
