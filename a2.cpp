#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
//compile using g++ -std=c++11 -pthread a2.cpp on Linux bash
//make sure that all_month.csv (the exact file included in the directory) is in the top of the directory
using namespace std;

struct thread_args{
	string arr[][22];
	int n;
	int start;

};


void bubbleSort(string arr[][22], int n, int start){
int i, j;
string temp[22];

  for(int i = 0; i < n-1; i++){
    for(int j = start; j < n-i-1; j++){
	char * num = const_cast<char*>(arr[j][1].c_str());
	char * num2 = const_cast<char*>(arr[j+1][1].c_str());
       	  if(strtof(num,0) > strtof(num2,0)){
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
/*
 //test to see if working sort
int p = 0;
for (p = start; p < n; p++)
{
 cout<<arr[p][1] << endl;
} 
*/
}

void *bubble_threads(void* ptr){

struct thread_args * args = (struct thread_args*) ptr;

int i, j;
string temp[22];

  for(int i = 0; i < (args->n)-1; i++){
    for(int j = args->start; j < (args->n)-i-1; j++){
	char * num = const_cast<char*>(args->arr[j][1].c_str());
	char * num2 = const_cast<char*>(args->arr[j+1][1].c_str());
       	  if(strtof(num,0) > strtof(num2,0)){
	     for(int k = 0; k < 22; k++){
	     temp[k] = args->arr[j][k];	
	     }
	     for(int k = 0; k < 22; k++){
		args->arr[j][k] = args->arr[j+1][k];
	     }
             for(int k = 0; k < 22; k++){
		args->arr[j+1][k] = temp[k];	
	     }
	
	  }	
   
	}
  }

/* //test to see if working sort
int p = 0;
for (p = args->start; p < args->n; p++)
{
 cout<<args->arr[p][1] << endl;
} */

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
	
	if(pid != 0){
	bubbleSort(arr,4911,4911);
	wait(NULL);
	 	
	}	
}


void fourProcess(string arr[][22]){

	pid_t pid;
	pid_t pid2;

	pid = fork();
	if(pid ==0)
	 bubbleSort(arr, 2455, 0);
	 
	pid2 = fork();
	if (pid2 == 0)
	 bubbleSort(arr, 2456, 2456);
	
	
	if(pid != 0){
	 bubbleSort(arr, 2455,  4911);	
	bubbleSort(arr, 2456, 7366);
	}	
		
}

void ten_fork(string arr[][22], int n){

	pid_t pid;
	
	if(n > 0)
	{
	   if((pid = fork()) < 0)
		{
			cout << "error";
		}
	   else if (pid == 0)
		{
		bubbleSort(arr,982, 0);
		bubbleSort(arr, 983, 983);
		bubbleSort(arr, 982, 1965);
		bubbleSort(arr, 982, 2947);
	        bubbleSort(arr,982,3929);
		bubbleSort(arr,983,4911);
		bubbleSort(arr,982,5894);	
		bubbleSort(arr,982,6876);
		bubbleSort(arr,982,7858);
		bubbleSort(arr,982,8840);
		}
	   else if(pid > 0)
		{
		  ten_fork(arr,n-1);
		}

	}
	
	
}


void threading(string arr[][22], int num_threads){
int i;
pthread_t threads[num_threads];
int rc;
struct thread_args args;
   for(i = 0; i < num_threads; i++){
	
         	if(num_threads == 2){
        	args.n = 9822 / num_threads;
	        }
         	else if(num_threads = 4){
			if(i == 0){
	
			}
			else if(i == 1){

			}
			else if(i == 2){

			}

			else{
			
			}
		}		
		else
		{
			if(i == 0){
			}
			else if(i == 1){
			}
			else if(i == 2){
			}
			else if(i == 3){
			}
			else if(i == 4){
			}
			else if(i == 5){
			}
			else if(i == 6){
			}
			else if(i == 7){
			}
			else if(i == 8){
			}
			else{
			}

		}


	args.start = args.n * i;

	if(i = 0){for(int j = 0; j < args.n; j++){
	   for(int k = 0; k < 22; k++){	
			args.arr[j][k] = arr[j][k]; 
		}
	}}
	else{for(int j = args.start; j < (args.n * i); j++){
	   for(int k = 0; k < 22; k++){	
			args.arr[j][k] = arr[j][k]; 
		}
	}}		
	rc =pthread_create(&threads[i],NULL,bubble_threads, (void*)&args);
    }

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
	char num;
	cout << "The last time listed is the total time. " << endl
	<< "Enter the amount you would like to sort on: " << endl;
	cout << "1. One process / 1 thread" << endl;
	cout << "2. Two processes" << endl;
	cout << "3. Four processes" << endl;
	cout << "4. Ten processes" << endl;
	cout << "5. 2 threads" << endl;
	cout << "6. 4 threads" << endl;
	cout << "7. 10 threads" << endl;
	cout << "8. Exit" << endl;
	cin >> num;

switch(num){

  case '1': 

	//time for one process
	time(&startTime);		
	bubbleSort(earthquakes,9822,0);
	time(&endTime);
	final = difftime(endTime,startTime); 
	cout << final << " seconds"; 
	break;
  case '2':
	
	time(&startTime);
	twoProcess(earthquakes);
	time(&endTime);
	final = difftime(endTime,startTime);
	cout << final << " seconds";
	break;
  case '3':
	time(&startTime);
	fourProcess(earthquakes);
	time(&endTime);
	final = difftime(endTime,startTime);
	cout << final << " seconds";
	break;
  case '4':

	time(&startTime);
	ten_fork(earthquakes, 10);
	time(&endTime);
	final = difftime(endTime,startTime);
	cout << final << " seconds";
  case '5':	
	time(&startTime);
	threading(earthquakes, 2);
	time(&endTime);
	final = difftime(endTime,startTime);
	cout << final << " seconds";	
	break;
  case '6':
	threading(earthquakes,4);
	break;
  case '7':
	threading(earthquakes,10);
  default:
	exit(0);

}

pthread_exit(NULL);	

return 0;
}
