// CALORIE CALCULATOR

#include <stdio.h>

float calculate_bmr(char gender, float weight, float height, int age) {
    if (gender == 'M' || gender == 'm') {
        return 10 * weight + 6.25 * height - 5 * age + 5;
    } else {
        return 10 * weight + 6.25 * height - 5 * age - 161;
    }
}

int main() {
    char name[50], gender;
    int choice, workout_level, age;
    float weight, height, bmr, calorie_intake;
    float protein_calories, fat_calories, carbs_calories;
    float protein_grams, fat_grams, carbs_grams;
    float recommended_workout_hours;
    int height_choice, feet, inches;

    printf("Welcome to the world of fitness!\n\n");
    printf("I'm your personal fitness buddy, who will guide you throughout your journey.\n");

    printf("Before moving ahead, first let me know your name: ");
    scanf("%s", name);
    printf("\nHey %s, that's a nice name you got, Buddy!\n", name);

    printf("What's your age in years: ");
    scanf("%d", &age);

    printf("\nSo what's your plan?\n");
    printf("1. Want to lose weight\n");
    printf("2. Gain weight\n");
    printf("3. Maintain current weight\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    printf("\nWhat's your gender? (M/F): ");
    scanf(" %c", &gender);

    printf("What's your weight in kg: ");
    scanf("%f", &weight);

    printf("\nHow would you like to enter your height?\n");
    printf("1. Centimeters\n");
    printf("2. Feet and Inches\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &height_choice);

    if (height_choice == 1) {
        printf("What's your height in cm: ");
        scanf("%f", &height);
    } else if (height_choice == 2) {
        printf("Enter your height:\n");
        printf("Feet: ");
        scanf("%d", &feet);
        printf("Inches: ");
        scanf("%d", &inches);
        // Convert feet and inches to centimeters (1 foot = 30.48 cm, 1 inch = 2.54 cm)
        height = (feet * 30.48) + (inches * 2.54);
    } else {
        printf("Invalid height choice!\n");
        return 1;
    }

    printf("\nWhat's your workout status weekly?\n");
    printf("1. No workout\n");
    printf("2. Little bit workout\n");
    printf("3. Intermediate workout\n");
    printf("4. A lot of workout\n");
    printf("Enter your workout level (1-4): ");
    scanf("%d", &workout_level);

    bmr = calculate_bmr(gender, weight, height, age);

    switch(workout_level) {
        case 1:
            calorie_intake = bmr * 1.2;  
            recommended_workout_hours = 2.0; 
            break;
        case 2:
            calorie_intake = bmr * 1.375; 
            recommended_workout_hours = 3.0; 
            break;
        case 3:
            calorie_intake = bmr * 1.55;  
            recommended_workout_hours = 5.0; 
            break;
        case 4:
            calorie_intake = bmr * 1.725; 
            recommended_workout_hours = 7.0; 
            break;
        default:
            printf("Invalid workout level input!\n");
            return 1;
    }

    if (choice == 1) {
        calorie_intake -= 200;
        printf("\nYou want to lose weight, so we subtract 200 calories.\n");
    } else if (choice == 2) {
        calorie_intake += 200;
        printf("\nYou want to gain weight, so we add 200 calories.\n");
    } else if (choice == 3) {
        printf("\nYou want to maintain your current weight, so we keep the exact calorie requirement.\n");
    } else {
        printf("\nInvalid plan choice!\n");
        return 1;
    }

    protein_calories = 0.25 * calorie_intake;
    fat_calories = 0.25 * calorie_intake;
    carbs_calories = 0.50 * calorie_intake;

    protein_grams = protein_calories / 4;
    fat_grams = fat_calories / 9;
    carbs_grams = carbs_calories / 4;

    printf("Based on your answers, your daily calorie intake should be around %.2f calories.\n", calorie_intake);
    printf("\nHere is the breakdown of your macros:\n");
    printf("Protein: %.2f grams\n", protein_grams);
    printf("Fat: %.2f grams\n", fat_grams);
    printf("Carbohydrates: %.2f grams\n", carbs_grams);

    printf("\nTo achieve your goal, you should aim for %.1f to %.1f hours of workout per week.\n", recommended_workout_hours, recommended_workout_hours + 1);

    printf("\nThanks for having a conversation with me, see you next time!\n");
    printf("\nThis project was made by Ranjeet Singh.\n");

    return 0;
}
