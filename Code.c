#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  
typedef struct {
    char name[50];
    int status; 
} IoTDevice;

void processAICommand(char* command, IoTDevice* device) {
    for (int i = 0; command[i]; i++) {
        command[i] = toupper(command[i]);
    }
    if (strcmp(command, "ON") == 0) {
        device->status = 1;
        printf("%s is now ON.\n", device->name);
    } 
    else if (strcmp(command, "OFF") == 0) {
        device->status = 0;
        printf("%s is now OFF.\n", device->name);
    }
    else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    IoTDevice devices[5] = {
        {"Smart Light", 0},
        {"Smart Thermostat", 0},
        {"Smart Door Lock", 0},
        {"Smart Speaker", 0},
        {"Smart Camera", 0}
    };
    char device_name[50];
    char command[10];
    printf("Available devices:\n");
    for (int i = 0; i < 5; i++) {
        printf("- %s\n", devices[i].name);
    }
    printf("\nEnter device name (e.g., 'Smart Light'):\n");
    fgets(device_name, sizeof(device_name), stdin);
    device_name[strcspn(device_name, "\n")] = 0;  
    for (int i = 0; device_name[i]; i++) {
        device_name[i] = toupper(device_name[i]);
    }
    printf("Enter command (ON / OFF):\n");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0;  
    IoTDevice* selected_device = NULL;
    for (int i = 0; i < 5; i++) {
        char device_upper[50];
        strcpy(device_upper, devices[i].name);
        for (int j = 0; device_upper[j]; j++) {
            device_upper[j] = toupper(device_upper[j]);
        }

        if (strcmp(device_name, device_upper) == 0) {
            selected_device = &devices[i];
            break;
        }
    }
    if (selected_device != NULL) {
        processAICommand(command, selected_device);
    } else {
        printf("Device not found!\n");
    }
    return 0;
}
