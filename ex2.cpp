#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <vector>
#include <ctime>

using namespace std;

#define resourceTypeQuan 4 //no of resources
#define processQuan  5 //no of processes

pthread_mutex_t mutex; 
int init[resourceTypeQuan] = {36,45,54,45};
vector <int> availResourceVector; //A vector
vector<vector<int>> allocMatrix; //Curent
vector<vector<int>> maxMatrix; //ALL
vector<vector<int>> needMatrix; //Reqeusted
int i=0,j=0;

//function declaration
int requestResource(int processID,int requestVector[]);
int releaseResource(int processID,int releaseVector[]);
int ifGreaterThanNeed(int processID,int requestVector[]);
int ifEnoughToRelease(int processId, int releaseVector[]);
int ifInSafeMode();
int ifEnoughToAlloc(int []);
void printMaxMatrix();
void printNeedMatrix();
void printAllocMatrix();
void printAvailable();
void printReqOrRelVector(int vec[]);
void *customer(void* customerID);

int main(){
    
    vector<int> v1;
    int temp[resourceTypeQuan] = {36,45,54,45};
    int x;
    srand(time(NULL));
    //initialize maxMatrix
    for (i = 0; i < processQuan; ++i){
        //srand((unsigned int)time(NULL));
        //srand(time(NULL));
        v1.clear(); //eprosthesa mono tto dame
		for (j = 0; j < resourceTypeQuan; ++j){
            switch(j){
                case 0: 
                    //maxMatrix[i][j] = rand() % 36 +1;
                    x=(rand() % 36) +1;
                    v1.push_back(x);
                    break;
                case 2:
                    //maxMatrix[i][j] = rand() % 54 +1;
                    x=(rand() % 54) +1;
                    v1.push_back(x);
                    break;
                default:
                    //maxMatrix[i][j] = rand() % 45 +1;
                    x=(rand() % 45) +1;
                    v1.push_back(x);
                    break;
            }
		}
        maxMatrix.push_back(v1);
	}
    /*
    //initialize allocMatric
    for (i = 0; i < processQuan; ++i){
		for (j = 0; j < resourceTypeQuan; ++j){
			switch(j){
                case 0: 
                    allocMatrix[i][j] = rand() % 36 +1;
                    if((temp[j] - allocMatrix[i][j]) <= 0)
                        allocMatrix[i][j] = 0;
                    temp[j] -= allocMatrix[i][j];
                    break;
                case 2:
                    allocMatrix[i][j] = rand() % 54 +1;
                    if((temp[j] - allocMatrix[i][j]) <= 0)
                        allocMatrix[i][j] = 0;
                    temp[j] -= allocMatrix[i][j];
                    break;
                default:
                    allocMatrix[i][j] = rand() % 45 +1;
                    if((temp[j] - allocMatrix[i][j]) <= 0)
                        allocMatrix[i][j] = 0;
                    temp[j] -= allocMatrix[i][j];
                    break;
            }
            
		}
	}


    //initialize needMatrix
	for (i = 0; i < processQuan; ++i){
		for (j = 0; j < resourceTypeQuan; ++j){
			needMatrix[i][j] = maxMatrix[i][j] - allocMatrix[i][j];
		}
	}

    //initialize availResourceVector
    for (i = 0; i < resourceTypeQuan; ++i){
	    availResourceVector[i] = temp[i];
	}*/

    printf("Initial Max Matrix:\n");
    printMaxMatrix();
    /*printf("Initial Available Vector:\n");
	printAvailable();
	printf("Initial Allocation Matrix:\n");
	printAllocMatrix();
	printf("Initial Need Matrix:\n");
	printNeedMatrix();*/

    return 0;
}

void printMaxMatrix(){
    for (i = 0; i < processQuan; ++i){
		printf("{ ");
		for (j = 0; j < resourceTypeQuan; ++j){
			printf("%d, ", maxMatrix[i][j]);
		}
		printf("}\n");
	}
	return;
}

void printNeedMatrix(){//print need matrix
	for (i = 0; i < processQuan; ++i){
		printf("{ ");
		for (j = 0; j < resourceTypeQuan; ++j){
			printf("%d, ", needMatrix[i][j]);
		}
		printf("}\n");
	}
	return;
}

void printAllocMatrix(){//print Allocation Matrix
	for (i = 0; i < processQuan; ++i){
		printf("{ ");
		for (j = 0; j < resourceTypeQuan; ++j){
			printf("%d, ", allocMatrix[i][j]);
		}
		printf("}\n");
	}
	return;
}

void printAvailable(){//print number of available resources
	for (i = 0; i < resourceTypeQuan; ++i){
		printf("%d, ",availResourceVector[i]);
	}
	printf("\n");
	return;
}