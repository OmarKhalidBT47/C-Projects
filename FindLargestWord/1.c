#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>


int main(){
    printf("Enter the file name: ");
    char filename[100];
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r"); //open the file
    if (fp == NULL){
        printf("File not found"); //if the file is not found
        return 0;
    }
    // read the file size   
    fseek(fp, 0, SEEK_END); //seek to the end of the file
    int size = ftell(fp);   //get the size of the file 
    fseek(fp, 0, SEEK_SET); //seek to the beginning of the file
    // allocate memory to contain the whole file
    char *buffer = (char *) malloc (sizeof(char)*size); //allocate memory for the file
    if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);} //if the memory is not allocated
    // copy the file into the buffer
    fread (buffer,1,size,fp); //read the file
    fclose(fp); //close the file
    // make a copy of the buffer    
    char *buffer2 = (char *) malloc (sizeof(char)*size); //allocate memory for the copy
    if (buffer2 == NULL) {fputs ("Memory error",stderr); exit (2);} //if the memory is not allocated
    strcpy(buffer2, buffer); //copy the buffer to the copy

    // tokenize the buffer  
    char *token = strtok(buffer, " "); //
    int count = 0; //count the number of tokens
    while(token != NULL ){ //while the token is not null
        count++; //increase the count
        token = strtok(NULL, " "); //get the next token
    }
    // allocate memory for the words
    char **words = (char **) malloc (sizeof(char *)*count); //allocate memory for the words
    for (int i = 0; i < count; i++){ //loop through the words
        words[i] = (char *) malloc (sizeof(char)*100); //allocate memory for each word
    }
    if (words == NULL) {fputs ("Memory error",stderr); exit (2);}    //if the memory is not allocated
    // copy buffer2 to words
    token = strtok(buffer2, " "); //get the first token
    int i = 0;
    while(token != NULL ){ //while the token is not null
        strcpy(words[i], token); //copy the token to the words
        i++; //increase the index
        token = strtok(NULL, " "); //get the next token
    }
    // print the words
    for (int i = 0; i < count; i++){
        printf("%s ", words[i]); //
    }
    // print the words and their frequency
    for (i = 0; i < count; i++){
        int j; //index
        int freq = 1; //frequency of the word
        for (j = i+1; j < count; j++){
            if (strcmp(words[i], words[j]) == 0){ //if the words are the same
                freq++; //increase the frequency
                words[j] = ""; //set the word to null
            }
        }
        if (strcmp(words[i], "") != 0){
            printf("%s %d \n ", words[i], freq);
        }
    }
    // find the largest word
    int max = 0;
    char *largest = (char *) malloc (sizeof(char)*100);
    for (i = 0; i < count; i++){
        if (strlen(words[i]) > max){
            max = strlen(words[i]);
            strcpy(largest, words[i]);
        }
    }
    printf("The largest word is %s with length %d", largest, max);
    // free the memory
    free(buffer);
    free(buffer2);
    free(largest);
    for (int i = 0; i < count; i++){
        free(words[i]);
    }
    free(words);
    
    return 0;
    
}