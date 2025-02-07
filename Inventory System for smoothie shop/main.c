
/* COP 3502C Assignment 1
This program is written by: Juan E. Leon */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *in;

typedef struct item {
    int itemID;
    int numParts;
} item;

typedef struct recipe {
    int numItems;
    item* itemList;
    int totalParts;
} recipe;

// Pre-condition:
//reference to a variable to store number of ingredients.

// Post-condition:

/*Reads in numIngredients and that number of strings from the inputs, allocates an array of
strings to store the input, and sizes each
individual string dynamically to be the
proper size (string length plus 1), and returns a pointer to the array.*/


char** readIngredients(int *numIngredients){

    char buffer[21];


    fscanf(in, "%d", numIngredients);
    // printf("%d\n", *numIngredients); //testing

    char** ingredientNames;
    ingredientNames = malloc(*numIngredients * sizeof(char*));

    for (int i = 0; i < *numIngredients; i++){
        fscanf(in, "%s", buffer);
        ingredientNames[i] = malloc((strlen(buffer)+1) * sizeof(char));
        strcpy(ingredientNames[i], buffer);
        //printf("%s\n",ingredientNames[i] );// testing
    }
    return ingredientNames;
}

// Pre-condition:
//does not take any parameter
// Post-condition:

/* Reads in details of a recipe such as numItems, Dynamically allocates space for a single recipe, dynamically allocates an array of item of the proper size, updates the
numItems field of the struct, fills the array of items appropriately based on the input and returns a pointer to the struct dynamically allocated.*/
recipe* readRecipe(){
    recipe* recipe;
    int num_of_ingr, curr_ingr, amount;

    fscanf(in, "%d", &num_of_ingr);
    //printf("%d\n", num_of_ingr); //  testing

    recipe = malloc(sizeof(recipe));
    recipe->numItems = num_of_ingr;

    for (int i = 0; i < num_of_ingr; i++){
        recipe->itemList = malloc(num_of_ingr * sizeof(item));
    }
    recipe->totalParts = 0;
    for (int i = 0; i < num_of_ingr; i++){
        fscanf(in, "%d", &curr_ingr);
        recipe->itemList[i].itemID = curr_ingr;
        fscanf(in, "%d", &amount);
        recipe->itemList[i].numParts = amount;
        //printf("%d %d\n",recipe->itemList[i].itemID, recipe->itemList[i].numParts); // testing
        recipe->totalParts += amount;
    }
    return recipe;
}

// Pre-condition: reference to a variable to store number of recipes.
// Post-condition: Read number of recipes. Dynamically allocates an array of pointers to recipes of size numRecipes, reads numRecipes
// number of recipes from standard input, creates
// structs to store each recipe and has the
// pointers point to each struct, in the order
// the information was read in. (Should call
// readRecipe in a loop.)

recipe** readAllRecipes(int *numRecipes){
    fscanf(in, "%d", numRecipes); // Number of recipes.
    //printf("%d\n", *numRecipes); //testing

    recipe** smoothieList = malloc(*numRecipes * sizeof(recipe*));

    for (int i = 0; i < *numRecipes; i++){
        smoothieList[i] = readRecipe();
    }
    return smoothieList;
}

// Pre-condition: 0 < numSmoothies <= 100000, recipeList is
// pointing to the list of all smoothie recipes and
// numIngredients equals the number of total ingredients (you have  // already read it in the first line of the input).
// Post-condition: Reads in information from input file
// about numSmoothies number of smoothie orders and dynamically
// allocates an array of doubles of size numIngredients such
// that index i stores the # of pounds of ingredient i
// needed to fulfill all smoothie orders and returns a pointer
//    to the array.
double* calculateOrder(int ingredientCount, int numSmoothies, recipe** recipeList){
    double* amtOfEachItem;
    int stores, recipeIndex, amt;
    amtOfEachItem = malloc(ingredientCount * sizeof(double));

    fscanf(in, "%d", &stores);
    for (int i = 0; i < stores; i++){
        fscanf(in, "%d", &numSmoothies);
        for (int j = 0; j < numSmoothies; j++){
            fscanf(in, "%d", &recipeIndex);
            fscanf(in, "%d", &amt);
            amtOfEachItem[recipeIndex] = amt;
        }
        for (int i = 0; i < ingredientCount; i++)
            printf("%lf", amtOfEachItem[i]);
    }


}
// Pre- Conditions:
/* ingredientNames store the names of each
ingredient and orderList stores the amount
 to order for each ingredient, and both arrays
are of size numIngredients.*/

// Post-condition:
/*Prints out a list, in ingredient order, of each
ingredient, a space and the amount of that
ingredient to order rounded to 6 decimal
places. One ingredient per line. */

void printOrder(char** ingredientNames, double* orderList, int numIngredients){

}
// Pre-conditions: ingredientList is an array of char* of size numIngredients with each char* dynamically allocated.
// Post-condition: all the memory pointed to by ingredientList is // freed.
void freeIngredients(char** ingredientList, int numIngredients);

// Pre-conditions: allRecipes is an array of recipe* of size numRecipes with each recipe* dynamically allocated to point to a single recipe.
// Post-condition: all the memory pointed to by allRecipes is // freed
void freeRecipes(recipe** allRecipes, int numRecipes){

}


// Suggested but optional function:
// void processOutput(char** ingredientList, int ingredientCount, recipe** allRecipes, int recipeCount);


int main(void) {
    in = fopen ("sample_in1.txt", "r");
    recipe** smoothieList;
    double* amtOfEachItem;
    int s, n;

    char** NameofIngredients = readIngredients(&n);

    //recipe* recipe_1 = readRecipe();
    smoothieList = readAllRecipes(&s);
    /*for (int i = 0; i < s; i++){ // testing
      printf("%d\n", smoothieList[i]->totalParts);
    }*/
    calculateOrder(n, s, smoothieList);

    return 0;
}