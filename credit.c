// Anirban Bala Pranto
// 31 March 2019
// Problem Set 1
#include<math.h>
#include<cs50.h>
#include<stdio.h>
 
int main()
{
    long i,j,size,digit,mult,k,even,digiteven;
    long number = get_long("Number:"); //takes the actual number
    long no = number;
    int pos;
    int result=0,digitnew;
    int left =0;
    int add;
    mult = 0;
    size=0; 
    //This counts the number of digits in input
    while(no != 0){
        no = no/10;
        size++;
    }
    // mother loop
    for(i=0;i<size;i++){
        // takes the value of every other number starting from right
        if(i%2!=0){
                long x=pow(10,i);
                digit=(number/x)%10;
                mult = digit*2; //multiplies them by 2
                pos= mult;
                int sizemult=0;
                while(pos != 0){ //finds the number of digits in each product
                    pos = pos/10;
                    sizemult++;
                }
                //separates the digits of the product and add them
                for(j=0;j<sizemult;j++){
                    long y=pow(10,j);
                    digitnew=(mult/y)%10;
                    result = digitnew + result;
                }
                                
        }
    }
    //adds the numbers which were not multiplied
    for(k=0;k<size;k++){
        if(k%2==0){
                    even=pow(10,k);
                    digiteven=(number/even)%10;
                    left = digiteven+left;
                    
        }
    }
    //adds the multiplied digits with unmultiplied digits
    add= left+result;
    //Validates if it's a credit card or not
    if(add%10!=0){
        printf("INVALID\n");
    }
    //Validates if it's American Express or not
    long z= pow(10,size-2);
    long amex = (number / z);
    if (size == 15){
        if (amex != 34 && amex != 37){
            printf("INVALID\n");
        }
        else{
            printf("AMEX\n");
        }

    }
    //Validates a 16 digit number if it's Mastercard or visa or invalid
    long w= pow(10,size-1);
    long master = (number/z);
    long visa = (number/w)%10;
    if (size == 16 || size==13){
        if (master != 51 && master != 52 && master != 53 && master != 54 && master != 55 && visa !=4){
            printf("INVALID\n");
        }
        else if(visa==4){
            printf("VISA\n");
        }
        else{
            printf("MASTERCARD\n");
        }

    }
    if(size<13){
        printf("INVALID\n");
    }
    
}


    
