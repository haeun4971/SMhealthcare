//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;

typedef struct {
    char exercise_name[MAX_EXERCISE_NAME_LEN]; 
    int calories_burned_per_minute;          
} Exercises;  //Specifying a Structure by haeun

Exercise exercises[MAX_EXERCISES];  //Save exercise data by haeun
int exercise_count; //Declaration of Variables by haeun




/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (fscanf(file,"%s %d",exercises[exercise_count].exercise_name, &exercises[exercise_count].calories_burned_per_minute)!=EOF) {
    	
    	exercise_count++;  //by haeun

    	
        if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    
    
    for (i=0; i<exercise_count; i++){   //by haeun 
       printf("%d. %s (%d kcal/min)\n", i + 1, exercises[i].exercise_name, exercises[i].calories_burned_per_minute);
    }
    printf("%d. Exit\n", exercise_count + 1);  //by haeun




    // ToCode: to enter the exercise to be chosen with exit option
    
    printf("Choose an exercise (1-%d):", exercise_count + 1);  //by haeun
    scanf("%d", &choice); //by haeun


 
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    

}
