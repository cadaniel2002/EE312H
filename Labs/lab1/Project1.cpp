// SuperStrings <Project1.cpp>
// EE 312 Project <1> submission by
// <Christian Daniel>
// <cad4254>
// Slip days used: <0>
// Spring 2021

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types


/*      ----------------------------------------------------------------------------------------------------------------------------------------------

        The method doesSuperStringContainString determines with 1 string and 1 superstring if they meet the requirements to be matched.
        For each letter in the target String, the superstring is searched until that letter is found,
        then the next letter of the target string is found, and the superstring is searched from where the last search left off.
        If any of the letters are not found in the string in the proper order, a false (0) is returned, otherwise a true (1) is returned.

*/



int doesSuperStringContainString(char *pTargetWord, int wordLength, char *pSuperStrings){

        char *pSuperStringTemp = pSuperStrings;
        while(*pSuperStringTemp != '\0'){
                for(int i = 0; i < wordLength; i++){
                        while(*pSuperStringTemp != *(pTargetWord+i) && *pSuperStringTemp != '\n' && *pSuperStringTemp != '\0' && *pSuperStringTemp != ' ')
                        {
                        pSuperStringTemp++;
                        }
                        if(*pSuperStringTemp != *(pTargetWord+i)){
                                return 0;
                        }
                        pSuperStringTemp++;
                }
                return 1;        
        }
        return 1;
}

/*      ----------------------------------------------------------------------------------------------------------------------------------------------

        The method findSuperStrings finds all the superstrings that correspond to the current word pointed at in the targets[] array
        The method loops until whitespace has is at the pointer location, indicating the end of the target word
        The method submits the target word along with each superstring word into the doesSuperStringContainString() method, to determine if they are a match
        if they are a match, the superstring is printed and the pointer for superstrings is incremented to the start of the next superstring to loop until
        the end of the superstrings list is reached at '\0'
        

*/

void findSuperStrings(char *pTargetWord, int wordLength, char *pSuperStrings){

        while(*pSuperStrings != '\0'){
                if(doesSuperStringContainString(pTargetWord, wordLength, pSuperStrings)){
                        while(*pSuperStrings != '\n' && *pSuperStrings != '\0' && *pSuperStrings != ' '){
                                printf("%c",*pSuperStrings);
                                pSuperStrings++;
                        }
                        printf("\n");
                        
                }
                else{
                        while(*pSuperStrings != '\n' && *pSuperStrings != '\0' && *pSuperStrings != ' '){
                                pSuperStrings++;                
                        }
                        
                }
                if(*pSuperStrings != '\0') { pSuperStrings++;}
        }
}


/*      ----------------------------------------------------------------------------------------------------------------------------------------------      

        The method printSuperStrings method creates a pointer to the start of the targets string
        and inputs the position of the current target word along with the calculated length into the findSuperStrings method
        in order to find all of the superstrings of the current word
        Next, the program increments the pointer to point at the next target word, and returns to the start of the loop 
*/


void printSuperStrings(char targets [], char candidates []) {

        char *pTargetWord = targets;

        while(*pTargetWord != '\0'){

                char *pTempTarget = pTargetWord;
                int targetStringLength = 0;
                
                while(*pTempTarget != ' ' && *pTempTarget != '\0' && *pTempTarget != '\n') {
                        targetStringLength++, pTempTarget++;
                }
                
                findSuperStrings(pTargetWord, targetStringLength, candidates);
                if(*pTempTarget != '\0'){
                        pTargetWord = pTempTarget + 1;
                }
                else{
                        break;
                }
        }
}



