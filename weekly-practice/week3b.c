#include <stdio.h>
#include <string.h>

void reverberate(char *input, char *output) {
    int len = strlen(input);
    int out_index = 0;

    for (int i = 0; i < len; i++) {
        output[out_index++] = input[i];
        if (input[i] != ' ' && input[i] != ',' && input[i] != '?') {
            for (int j = i + 1; j < len && input[j] != ' ' && input[j] != ',' && input[j] != '?'; j++) {
                output[out_index++] = input[j];
            }
        }
        if (input[i] != ' ' && input[i] != ',' && input[i] != '?') {
            output[out_index++] = '-';
        }
    }
    output[out_index - 1] = '\0'; // Remove the last '-'
}

int main() {
    char input[] = "Hello, who is there?";
    char output[256]; // Large enough to hold the reverberated string

    reverberate(input, output);

    printf("Original: %s\n", input);
    printf("Reverberated: %s\n", output);

    return 0;
}
