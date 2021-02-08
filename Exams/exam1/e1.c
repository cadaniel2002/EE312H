
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define LEN 100

int main(void) {
    
    int ilen;
    
    while(1){   // program will run until entered ilen is invalid


        printf("Number of elements:\n");
        scanf("%d", &ilen);

        if(ilen < 1){   // checks if the input is valid and returns 1 if it is not
            return 1;   
        }

        int numbers[ilen];              // defines int and char arrays of the same length
        char letters[ilen];

        printf("Enter elements of the array:\n");
        for(int i = 0; i < ilen; i++){  // using scanf to move the inputted characters into an array of integers
            scanf("%d",  &numbers[i]);  // while also printing the integers
            printf("%d ", numbers[i]);
        }
        printf("\n");

        for(int i = 0; i < ilen; i++){          // loop setting each place in the character array to the lowercase version of the ascii code it represents
            letters[i] = tolower(numbers[i]);   // while also printing the characters
            printf("%c ", letters[i]);
        }
        printf("\n");

        for(int i = 0; i < ilen; i++){  //goes through each letter to compare against all of the other letters

            for(int j = i + 1; j < ilen; j++){  // goes through each letter after letter[i] to compare to letter[i]

                if(letters[i] == letters[j]){   // executes if the letters at j and i are the same

                    for(int k = j; k < ilen - 1; k++){  // this for loops moves back all of the letters in the array after the duplicate
                        letters[k] = letters[k+1];
                    }

                    i--;                    // decrements i in case there are multiple duplicates of the same character
                    ilen--;                 // decrements the amount of the array that we are checking as we just deleted a character
                    letters[ilen] = '\0';   // adds a null to the end of the array to mark that a character has been deleted
                }
            }
        }

        for(int i = 0; i < ilen; i++){  // prints the remaining characters left in the array
            printf("%c ", letters[i]);
        }
        printf("\n");

    }
    return 0;
}
