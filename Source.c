#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions that can be asked
#define MAX_QUESTIONS 5

// Define a structure to hold the information for each question
typedef struct {
    char* question;
    char* options[4];
    int answer;
} Question;

// Function to create a new question and return a pointer to it
Question* create_question(char* question, char* option1, char* option2, char* option3, char* option4, int answer) {
    Question* new_question = (Question*)malloc(sizeof(Question));
    new_question->question = question;
    new_question->options[0] = option1;
    new_question->options[1] = option2;
    new_question->options[2] = option3;
    new_question->options[3] = option4;
    new_question->answer = answer;
    return new_question;
}

// Function to ask a question and return the user's answer
int ask_question(Question* question) {
    int answer;
    printf("%s\n", question->question);
    printf("1. %s\n", question->options[0]);
    printf("2. %s\n", question->options[1]);
    printf("3. %s\n", question->options[2]);
    printf("4. %s\n", question->options[3]);

    // Use scanf_s instead of scanf to avoid buffer overflows
    scanf_s("%d", &answer, sizeof(answer));

    return answer;
}


int main() {
    // Create an array of questions
    Question* questions[MAX_QUESTIONS];
    questions[0] = create_question("What is the capital of France?", "Paris", "Madrid", "Rome", "London", 1);
    questions[1] = create_question("What is the tallest mountain in the world?", "Mount Kilimanjaro", "Mount Everest", "Mount McKinley", "Mount Fuji", 2);
    questions[2] = create_question("What is the largest country in the world?", "China", "Russia", "India", "United States", 2);
    questions[3] = create_question("What is the smallest country in the world?", "Vatican City", "Monaco", "San Marino", "Liechtenstein", 1);
    questions[4] = create_question("What is the currency of Japan?", "Yuan", "Euro", "Dollar", "Yen", 4);

    // Ask each question and keep track of the user's score
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int answer = ask_question(questions[i]);
        if (answer == questions[i]->answer) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect. The correct answer is %d\n", questions[i]->answer);
        }
    }

    // Print the user's final score
    printf("You got %d out of %d questions correct!\n", score, MAX_QUESTIONS);

    // Free the memory used by the questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        free(questions[i]);
    }

    return 0;
}
