#include <stdio.h>
#include <string.h>

#define MAX 100

char moods[MAX][20];
int count = 0;

void addMood() {
    if (count >= MAX) {
        printf("Mood storage is full.\n");
        return;
    }

    printf("Enter your mood (Happy, Sad, Excited, Calm, etc.): ");
    scanf("%s", moods[count]);

    count++;

    printf("Mood recorded successfully.\n");
}

void viewHistory() {
    if (count == 0) {
        printf("No moods recorded yet.\n");
        return;
    }

    printf("\n===== MOOD HISTORY =====\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, moods[i]);
    }
}

void viewStatistics() {
    int happy = 0, sad = 0, excited = 0, calm = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(moods[i], "Happy") == 0)
            happy++;
        else if (strcmp(moods[i], "Sad") == 0)
            sad++;
        else if (strcmp(moods[i], "Excited") == 0)
            excited++;
        else if (strcmp(moods[i], "Calm") == 0)
            calm++;
    }

    printf("\n===== MOOD STATISTICS =====\n");
    printf("Happy   : %d\n", happy);
    printf("Sad     : %d\n", sad);
    printf("Excited : %d\n", excited);
    printf("Calm    : %d\n", calm);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== MOOD TRACKER =====\n");
        printf("1. Add Mood\n");
        printf("2. View Mood History\n");
        printf("3. View Statistics\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMood();
                break;

            case 2:
                viewHistory();
                break;

            case 3:
                viewStatistics();
                break;

            case 4:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}