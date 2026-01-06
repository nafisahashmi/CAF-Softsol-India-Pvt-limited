#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FIXED_NAME "CAF SoftSol India Pvt Ltd."

void makeLower(char lower[], const char original[]) {
    int i = 0;
    while (original[i] != '\0') {
        lower[i] = tolower(original[i]);
        i++;
    }
    lower[i] = '\0';
}


const char* normalizeCompany(const char *name) {
    if (name == NULL) {
        return NULL;
    }
     if (strlen(name) == 0) {
        return "";
    }
    char lowerName[200];
    makeLower(lowerName, name);

    if (strstr(lowerName, "caf") &&
        (strstr(lowerName, "soft") || strstr(lowerName, "solution"))) {
        return FIXED_NAME;
    }

    return name;
}
int main() {

    const char *inputs[] = {
        "CAF softsol",
        "CAF solution",
        "CAF softSolution India Pvt Limited",
        "",
        NULL,
        "Other Company"
    };

    for (int i = 0; i < 6; i++) {
        const char *result = normalizeCompany(inputs[i]);

        if (result == NULL)
            printf("Input: NULL → Output: NULL\n");
        else
            printf("Input: '%s' → Output: '%s'\n", inputs[i], result);
    }

    return 0;
}