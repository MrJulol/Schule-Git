#include <stdio.h>
#include <stdlib.h>
#include <time.h>                                           //NULL for rand-Seed
#define fail -1                                             //To see if a function returns an error

int minmax(int ran[], int size);                            //to find min and max
int position(int checkforthis, int arraysize, int ran[]);   //to find 1st position of min and max
int howoften(int ran[], int arraysize, int checkforthis);   //to check how often min and max are in the array

int main(){
    srand((unsigned)time(NULL));
    int arraysize;
    int smallest;
    int biggest;
    int posmin,posmax;                                      //Position of Min and Max
    int maxran, minran;                                     //Limits for rand()
    int howoftenmin, howoftenmax;                           //counter for positions

    printf("\nHow many random numbers do you want?");
    scanf("%d", &arraysize);                                //How many numbers OR Arraysize
    printf("How big should the numbers be (max): ");
    scanf("%d", &maxran);                                   //The highest random number for % after rand()
    printf("How small should the number be (min): ");
    scanf("%d", &minran);                                   //The lowest random number for % after rand()
    int ran[arraysize];                                     //initialize Array the size of the wanted numbers

    for (int i = 0; i<=arraysize;i++){                      //fill array with random numbers
        ran[i] = (rand()%(maxran-minran+1)) +minran;        //range = minran-maxran
        //printf("%d\n", ran[i]);                           //To test if positions and counters are working
    }

    smallest = minmax(ran,arraysize);
    biggest = minmax(ran,arraysize);

    posmin = (position(smallest,arraysize,ran))+1;
    posmax = (position(biggest,arraysize,ran))+1;

    howoftenmin = howoften(ran,arraysize,smallest);
    howoftenmax = howoften(ran, arraysize,biggest);


    printf("\nSmallest number: %d\n",smallest);
    printf("Biggest number: %d\n\n",biggest);
    
    printf("1st Position of Smallest number: [%d]\n", posmin);
    printf("1st Position of Biggest number: [%d]\n\n", posmax);

    printf("The number %d is %dx among the numbers\n",smallest,howoftenmin);
    printf("The number %d is %dx among the numbers\n\n",biggest,howoftenmax);

    printf("\n");                                           //WHY? Cause MacOS wants a \n else it bugs
    return EXIT_SUCCESS;
}

int minmax(int ran[], int size){
    static int counter = 0;                                 //to return smallest 1x and biggest 1x
    int biggest = 0;
    int smallest = INT32_MAX;                               //Highest possible number (every number in the array has to be smaller)
    for(int i = 0;i <= size;i++){
		if(ran[i] >= biggest){
			biggest = ran[i];
		}
        if(ran[i]<= smallest){
            smallest = ran[i];
        }	
	}
    
    if(counter == 0){
        counter++;
        return smallest;
    }
    else{
        return biggest;
    }

    return fail; 
}

int position(int checkforthis, int arraysize, int ran[]){

    for(int i = 0; i<arraysize;i++){
        if(ran[i]== checkforthis){
            return i;
        }
    }

    return fail;
}

int howoften(int ran[], int arraysize, int checkforthis){
    int counter = 0;

    for(int i = 0; i<arraysize;i++){
        if(ran[i]==checkforthis){
            counter++;
        }
    }

    return counter;
}