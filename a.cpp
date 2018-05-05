//  Katherine Younke
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int process();
int bubblesort(int start, int size, int print);

struct worldCities{
    char country[50];
    char city[50];
    char accentcity[50];
    int region;
    int population;
    double lat;
    double longt;
    
};

struct worldCities x[3173958];


int main(int argc, const char * argv[]) {
    printf("Reading File...\n");
    FILE *fptr;
    char s[1000];
    fptr=fopen("Users/Jenny/Desktop/HW2/HW2/worldcitiespop.txt", "r");
    if(!fptr) {
        printf("No File Available\n");
        return 1;
    }
    
    int count = 0;
   // int line = 0;
   // int place = 0;
    int array = 0;
    int cont = 0;
    int city = 0;
    int acc = 0;
    char reg[4];
    int region = 0;
   // char pop[10];
    int popu = 0;
    char lati[20];
    int latid = 0;
    char lon[20];
    int longi = 0;
    int i;
    
    while (fgets(s,1000,fptr)!=NULL) {
        for (i = 0; i < strlen(s);i++) {
            if(s[i] == ',') {
                count++;
            }
            if(count == 0) {
                x[array].country[count]=s[i];
                count++;
            }
            if(count == 1) {
                if(s[i] != ',') {
                    x[array].city[city] = s[i];
                    city++;
                }
            }
            if(count == 2) {
                if(s[i] != ',') {
                    x[array].accentcity[acc]=s[i];
                    acc++;
                }
            }
            if(count == 3) {
                if(s[i] != ',') {
                    reg[region]=s[i];
                    region++;
                }
            }
            if(count == 5) {
                if(s[i] != ',') {
                    lati[latid]=s[i];
                    latid++;
                }
            }
            if(count == 6) {
                if(s[i] != ',') {
                    lon[longi]=s[i];
                    longi++;
                }
            }
        }
        double lon1 = atof(lon);
        double lat1 = atof(lati);
        int reg1 = atof(reg);
        x[array].region = reg1;
        x[array].lat = lat1;
        x[array].longt = lon1;
        array++;
        
        acc= 0;
        cont = 0;
        region= 0;
        latid = 0;
        popu = 0;
        city = 0;
        count = 0;
        longi = 0;
    }
    printf("File Read \n");
    
    //int first = bubblesort(1,100,0);
    
    int choice = 0;
    int num;
    printf("Select 2, 4, 0r 10 number to processes to run: \n");
    scanf("%d", &choice);
    while(choice > 10 || choice < 2) {
        printf("Incorrect input. Choose 2, 4 or 10");
        scanf("%d", &choice);
    }
    if(choice == 2) {
        num = process(1, 100, 200);
    }
    if(choice == 4) {
        num = process(1, 100, 200);
        if(num == 1)
            num = process(100, 200, 300);
    }
    if(choice == 10) {
        num = process(1, 100, 200);
        if (num == 1){
            num = process(100, 200, 300);
            if(num == 1){
                num = process(200, 300, 400);
                if(num == 1)
                    num = process(300, 400, 500);
            }
        }
    }
    fclose(fptr);
    return 0;
}

int bubblesort(int start, int size, int print) {
    int i;
    int j;
    clock_t time;
    struct worldCities tmp;
    time=clock();
    
    for(i=start; i <size; i++) {
        for(j=start;j<size-1;j++) {
            if(x[j].longt > x[i].longt) {
                tmp=x[j];
                x[j]=x[i];
                x[i]=tmp;
            }
        }
    }
    if(print == 1) {
        printf("\n");
        for(int y=start; y< size; y++)
            printf("%s %s %s %i %f %f\n", x[y].country, x[y].city, x[y].accentcity,x[y].region, x[y].lat, x[y].longt);
    }
    printf("\nTime to do bubble sort is %f seconds\n", ((float)time)/CLOCKS_PER_SEC);
    return 0;
}

int process(int size1, int size2, int size3) {
    int ko;
    pid_t pid = fork();
    if(pid >=0) {
        if(pid == 0) {
            ko = bubblesort(size1, size2, 1);
            return 1;
        }
        else {
            wait(NULL);
            ko = bubblesort(size2, size3, 1);
            return 0;
        }
    }
    else {
        printf("\nFork Failed\n");
    }
    return 0;
}



