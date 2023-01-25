
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int arr[10]; //array of 10 integers
    int *ptr = arr; //pointer to the array
    srand(time(NULL)); //seed the random number generator
    for (int i = 0; i < 10; i++){ //loop through the array
        arr[i] = rand() % 10 + 1; //assign a random number between 1 and 10 to the array
    }
    printf("The array is: "); //print the array
    for (int i = 0; i < 10; i++){ //loop through the array
        printf("%d ", arr[i]); //print the array
    }
    printf("\n");
    printf("The pointer starts to points at cell0 which contains %d. ", *ptr); //print the value of the pointer
    printf("The user picks index "); //prompt the user
    int index;   //index of the array
    scanf("%d", &index); //get the index from the user
    int direction = rand() % 2; //get a random number between 0 and 1
    if (direction == 1){ //if the number is 1
        printf("The direction is forward. "); //print the direction
        ptr += index; //add the index to the pointer
    }
    else{
        printf("The direction is backward. "); //if the number is 0
        ptr -= index; //move the pointer to the index
    }
    if (ptr >= arr && ptr <= arr + 9){ //if the pointer is in the array
        printf("The user is lucky.\n "); //print the message
        printf("The pointer position is updated to point %d cells %s from its current position which means from cell0 move %d cells so it will point at cell %ld which contains the value %d so the user is lucky.\n", index, direction == 1 ? "forward" : "backward", index, ptr - arr, *ptr);    //print the pointer position     
    }
    else{
        printf("The user is unlucky. \n"); //if the pointer is not in the array
        printf("The pointer position is updated to point %d cells %s from its current position which will be %s %d cells before the array which means its outside the array boundary, so the user is unlucky.\n", index, direction == 1 ? "forward" : "backward", direction == 1 ? "forward" : "backward", index); //print the message
    }
    return 0;
}