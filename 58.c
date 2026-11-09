#include <stdio.h>
#include <string.h>

void display_info() {
    printf("\n=== Orchitis Educational Assessment Tool ===\n");
    printf("Orchitis is the inflammation of one or both testicles.\n");
    printf("It is usually caused by a bacterial or viral infection.\n\n");
}

int ask_question(const char *question) {
    char response[10];
    printf("%s (yes/no): ", question);
    scanf("%9s", response);
    if (strcmp(response, "yes") == 0 || strcmp(response, "YES") == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int score = 0;
    int has_severe_pain = 0;

    display_info();

    printf("Please answer the following questions honestly.\n\n");

    if (ask_question("1. Do you have pain in one or both testicles?")) {
        score += 2;
    }
    if (ask_question("2. Is there visible swelling or redness in the scrotum?")) {
        score += 2;
    }
    if (ask_question("3. Do you currently have a fever or chills?")) {
        score += 1;
    }
    if (ask_question("4. Do you feel nauseous or have you vomited recently?")) {
        score += 1;
    }
    if (ask_question("5. Did you recently have the mumps virus?")) {
        score += 3;
    }
    if (ask_question("6. Is the pain sudden and extremely severe?")) {
        has_severe_pain = 1;
    }

    printf("\n--- Assessment Results ---\n");
    if (has_severe_pain) {
        printf("CRITICAL: Sudden, severe testicular pain is a medical emergency.\n");
        printf("It could indicate Testicular Torsion. Seek ER care immediately!\n");
    } else if (score >= 4) {
        printf("Warning: Your symptoms align closely with Orchitis or Epididymitis.\n");
        printf("Please consult a healthcare professional for proper evaluation.\n");
    } else if (score > 0) {
        printf("Mild symptoms detected. Monitor closely and rest.\n");
        printf("See a doctor if the pain persists or worsens.\n");
    } else {
        printf("No strong indicators of orchitis detected based on your answers.\n");
    }

    return 0;
}

