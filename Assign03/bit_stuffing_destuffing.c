#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function to perform bit stuffing
void Stuffing(char* data) {
    int len = strlen(data);
    int count = 0;
    int i, j;

    for (i = 0, j = 0; i < len; i++, j++) {
        if (data[i] == '1') {
            count++;
            if (count == 5) {
                // Insert '0' after every 5 consecutive '1's
                data[j++] = '0';
                count = 0;
            }
        } else {
            count = 0;
        }
        data[j] = data[i];
    }
    data[j] = '\0';
}

// Function to perform bit destuffing
void Destuffing(char* data) {
    int len = strlen(data);
    int count = 0;
    int i, j;

    for (i = 0, j = 0; i < len; i++, j++) {
        if (data[i] == '1') {
            count++;
            if (count == 5 && data[i + 1] == '0') {
                // Skip the stuffed '0'
                i++;
                count = 0;
            }
        } else {
            count = 0;
        }
        data[j] = data[i];
    }
    data[j] = '\0';
}

int main() {
    char data[MAX_SIZE];

    printf("Enter the data to be stuffed: ");
    fgets(data, MAX_SIZE, stdin);

    // Perform bit stuffing
    Stuffing(data);
    printf("Stuffed data: %s\n", data);

    // Perform bit destuffing
    Destuffing(data);
    printf("Destuffed data: %s\n", data);

    return 0;
}
