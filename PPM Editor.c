/*****************************************************
            Authors:  Moeed Ahmad (212834)
            Project: PPM Image processing

******************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
//#include <unistd.h>
#define rgb 3

/*Function Prototypes*/

int readHeader(void);                         //Reads the Header
void Editor(int);                             //
void flip_horizontal();                       //Flips the image horizontally
void greyscale ();                            //Converts the image to grey-scale
void multiple_effects();                      //Allows multiple effects to be implemented on the image
void negate_red();                            //Negates all the values of red in the image
void negate_blue();                           //negates blue value
void negate_green();                          //negates green values
void flatten_red();                           //Sets values of red color to 0
void flatten_blue();                          //Sets blues to 0
void flatten_green();                          //sets greens to 0
//Bonus task function declarations
void horizontal_blur();
void extreme_contrast();
void random_noise();


/*Declaration of Global Variables*/

int row, column;
int i,k, j, l;
short value[9999999], image[9999999];
char temp, finput[50],foutput[50];

/*Main function starts*/

int main(){
int choice, found;     //Declaration of local variables
    puts("\t\t\t\t\t+-------------------------------+\n\t\t\t\t\t|      PPM   IMAGE   EDITOR\t|\n\t\t\t\t\t+-------------------------------+\n");
    printf("Enter the name of Image file: ");        //Prompts the user to enter the name of the file
    gets(finput);                                    //Inouts the name of the file given by the user and stores it
    strcat(finput,".ppm");                           //Adds the ppm extension at the end of the name entered

    found=readHeader();
	if (found == -1) return 0;                          /*Checks whether the file exists*/
    else printf("%s HAS BEEN LOCATED.\n",finput);

    printf("\nEnter the name to use for the Output file: ");      //Prompts the user to enter the name of the output file
    fflush(stdin);
    gets(foutput);                                    //Inputs and stores the name entered by the user
    strcat(foutput,".ppm");                           //Adds the ppm extension to the output file's name

	/* OUTPUTS THE MENU FOR THE USER */

    puts("\nWhat would you like to do?\n1.Copy Image\t\t\t2.Negative Red Effect\t\t3.Negative Blue Effect\n4.Negative Green Effect\t\t5.Greyscale\t\t\t6.Flip Horizontal\n7.Flatten Red\t\t\t8.Flatten blue\t\t\t9.Flatten Green");
    puts("10.Add Random Noise\t\t11.Horizontal Blur\t\t12.Extreme Contrast.\n13.Apply Multiple Effects.\n");

    printf("Enter Your Choice: ");                      //Prompts the user to enter the choice
    scanf("%d",&choice);                               //Inputs the choice and stores it

    Editor(choice);                                   //Passes the value of choice to the "Editor" function

    printf("\n\n%s HAS BEEN CREATED.\n", foutput);


}
/* The Editor function begins here */

void Editor(int choice){
    FILE *read, *write, *fp;                            //Pointers declaration

    fp=fopen(foutput,"w");                             //Opens the file for writing
        fprintf(fp,"P3 %d %d 255 ", row, column);
    fclose(fp);                                        //Closes the file

    write=fopen(foutput,"a");
    read=fopen(finput,"r");

    k=0;
   while(!feof(read)&&k<(row*column*rgb)){          //Checks for the end of file
    fscanf(read,"%c", &temp);
    fscanf(read,"%d", &value[k]);
    k++;
    }


for (k=0;k<row*column*rgb;k++)
    image[k]=value[k+4];

/* Performs a switch on the choice */

switch(choice){

	/* Case statements begin here */

case 1:
for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 2:
    negate_red();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 3:
    negate_blue();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 4:
    negate_green();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 5:
    greyscale();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 6:
    flip_horizontal();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 7:
    flatten_red();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 8:
    flatten_blue();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 9:
    flatten_green();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 10:
    random_noise();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 11:
    horizontal_blur();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

case 12:
    extreme_contrast();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;
case 13:
    multiple_effects();
    for (k=0;k<row*column*rgb;k++)
    fprintf(write,"%d ",image[k]);
    break;

default:
    printf("Invalid Choice.");
    }
}

/* The readHeader function begins here */

int readHeader(void){
    FILE *read;                                     //Pointer declaration
    int info[20];                                   //Declaration of the array info

    read  = fopen(finput,"r");                     //Opens the file for reading
        if (read==NULL){printf("File not found."); return -1;}         //Checks whether the file exists
        else{
                while(i<4){
                fscanf(read,"%c", &temp);
                fscanf(read,"%d", &info[i++]);
                }
        row=info[1];
        column=info[2];
        fclose(read);
        }

}

/* The negate_red function begins here */

void negate_red(){
    int i;
    for(i=0;i<row*column*rgb;i=i+3)
    image[i]= image[i]<127 ? 255-image[i]: (image[i]-255<0 ? image[i]*-1:image[i]);
}

/* The negate_blue function begins here */

void negate_blue(){
    int i;
    for(i=1;i<row*column*rgb;i=i+3)
    image[i]= image[i]<127 ? 255-image[i]: (image[i]-255<0 ?image[i]*-1:image[i]);
}

/* The negate_green function begins here */

void negate_green(){
    int i;
    for(i=2;i<row*column*rgb;i=i+3)
    image[i]= image[i]<127 ? 255-image[i]: (image[i]-255<0 ? image[i]*-1:image[i]);
}

/* The greyscal function begins here */

void greyscale (){
int average;
for (k=0;k<row*column*rgb;k=k+3){
average=(image[k]+image[k+1]+image[k+2])/rgb;
image[k]=average;
image[k+1]=average;
image[k+2]=average;
    }
}

/* The flip_horizontal function begins here */

void flip_horizontal(){
long i, j, k;
short n, temp1,temp2,temp3;

j = (row * rgb)-1;
k = j/2;
i = 0;
n=0;

while(i < row * column * rgb ){
	                                     //Nested while loop
while( i < j){

    temp1=image[i];
    temp2=image[i+1];
    temp3=image[i+2];

    image[i]=image[j-2];
    image[i+1]=image[j-1];
    image[i+2]=image[j];

    image[j-2]=temp1;
    image[j-1]=temp2;
    image[j]=temp3;

    i= i+rgb;
    j= j-rgb;

}
i = i + k + 1;
j = i + (row*rgb)-1;
}
}

/* The flatten_red function begins here */

void flatten_red(){
    int i;
    for(i=0;i<row*column*rgb;i=i+3)
    image[i]= 0;
 }

void flatten_blue(){
    int i;
    for(i=1;i<row*column*rgb;i=i+3)
    image[i]= 0;

}

void flatten_green(){
    int i;
    for(i=2;i<row*column*rgb;i=i+3)
    image[i]= 0;

}

/* The multiple_effects function begins here */

void multiple_effects(){
char a[11];
 system("@cls||clear");
puts("\nEnter 'y' to apply the effect and 'n' to not apply it.\n");
printf("Would you like to apply a Negative Red Effect?(y/n): ");
fflush(stdin);scanf("%c", & a[0]);
printf("Would you like to apply a Negative Blue Effect?(y/n): ");
fflush(stdin);scanf("%c", & a[1]);
printf("Would you like to apply a Negative Green Effect?(y/n): ");
fflush(stdin);scanf("%c", & a[2]);
printf("Would you like to Greyscale?(y/n): ");
fflush(stdin);scanf("%c", & a[3]);
printf("Would you like to Flip Horizontally?(y/n): ");
fflush(stdin);scanf("%c", & a[4]);
printf("Would you like to Flatten Red?(y/n): ");
fflush(stdin);scanf("%c", & a[5]);
printf("Would you like to Flatten blue?(y/n): ");
fflush(stdin);scanf("%c", & a[6]);
printf("Would you like to Flatten Green?(y/n): ");
fflush(stdin);scanf("%c", & a[7]);
printf("Would you like to Add Random Noise?(y/n): ");
fflush(stdin);scanf("%c", & a[8]);
printf("Would you like to add Horizontal Blur?(y/n): ");
fflush(stdin);scanf("%c", & a[9]);
printf("Would you like to Apply extreme contrast?(y/n): ");
fflush(stdin);scanf("%c", & a[10]);
_strlwr(a);

/* Selection statements begin here */

if (a[0]=='y')
    negate_red();
if (a[1]=='y')
    negate_blue();
if (a[2]=='y')
    negate_green();
if (a[3]=='y')
    greyscale();
if (a[4]=='y')
   flip_horizontal();
if (a[5]=='y')
    flatten_red();
if (a[6]=='y')
    flatten_blue();
if (a[7]=='y')
    flatten_green();
if (a[8]=='y')
    random_noise();
if (a[9]=='y')
    horizontal_blur();
if (a[10]=='y')
    extreme_contrast();
}

/****** BONUS TASKS *********/

void horizontal_blur(){
    int i, red_average, blue_average, green_average;
    for(i=0;i<row*column*rgb;i=i+9){
    red_average = (image[i]+image[i+3]+image[i+6])/3;
    image[i]= red_average;
    image[i+3]= red_average;
    image[i+6]= red_average;
    }

      for(i=1;i<row*column*rgb;i=i+9){
    blue_average = (image[i]+image[i+3]+image[i+6])/3;
    image[i]= blue_average;
    image[i+3]= blue_average;
    image[i+6]= blue_average;
    }

      for(i=2;i<row*column*rgb;i=i+9){
    green_average = (image[i]+image[i+3]+image[i+6])/3;
    image[i]= green_average;
    image[i+3]= green_average;
    image[i+6]= green_average;
    }
}

void extreme_contrast(){
    int i;
    for(i=1;i<row*column*rgb;i++)
    image[i]= image[i]<127 ? 0: 255;
}

void random_noise(){
    enum addsub {add, substract};
    short range, random;
    enum addsub x;
    long i;

    srand(time(NULL));
    range= rand()% 255;
    random= rand() % range;
    printf("%d\t",random);
    x = rand() % 2;
    printf("%d\t",x);
    if(x = add){
     for( i=1 ; i < row*column*rgb ; i++ )
        image[i]= image[i] + random < 255 ? image[i] + random : 255;
    }
    else{
        for( i=1 ; i < row*column*rgb ; i++ )
            image[i]= image[i] - random > 0 ? image[i] - random : 0;
    }
}
