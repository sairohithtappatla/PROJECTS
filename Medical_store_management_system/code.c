#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine store[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Medicine store is full!\n");
        return;
    }
    Medicine new_medicine;
    new_medicine.id = medicine_count + 1;
    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);
    
    store[medicine_count] = new_medicine;
    medicine_count++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicine_count == 0) {
        printf("No medicines available!\n");
        return;
    }
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", store[i].id, store[i].name, store[i].quantity, store[i].price);
    }
}

void updateMedicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    if (id <= 0 || id > medicine_count) {
        printf("Invalid medicine ID!\n");
        return;
    }
    Medicine *med = &store[id - 1];
    printf("Enter new name: ");
    scanf("%s", med->name);
    printf("Enter new quantity: ");
    scanf("%d", &med->quantity);
    printf("Enter new price: ");
    scanf("%f", &med->price);
    printf("Medicine updated successfully!\n");
}

void deleteMedicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);
    if (id <= 0 || id > medicine_count) {
        printf("Invalid medicine ID!\n");
        return;
    }
    for (int i = id - 1; i < medicine_count - 1; i++) {
        store[i] = store[i + 1];
    }
    medicine_count--;
    printf("Medicine deleted successfully!\n");
}

void searchMedicine() {
    char name[MAX_NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            printf("ID: %d\n", store[i].id);
            printf("Name: %s\n", store[i].name);
            printf("Quantity: %d\n", store[i].quantity);
            printf("Price: %.2f\n", store[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Search Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                searchMedicine();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
