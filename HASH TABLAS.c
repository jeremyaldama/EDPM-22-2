#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 50000 // Size of the Hash Table

unsigned long hash_function(char* str) {
    unsigned long i = 0;
    int j;
	for (j=0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}
// Define the Hash Table Item here
typedef struct{
    char* key;
    char* value;
} HT_item;

// Define the Hash Table here
typedef struct HashTable {
    // Contains an array of pointers
    // to items
    HT_item** items;
    int size;
    int count;
} HashTable;

HT_item* create_item(char* key, char* value) {
    // Creates a pointer to a new hash table item
    HT_item* item = (HT_item*)malloc (sizeof(HT_item));
    item->key = (char*) malloc (strlen(key) + 1);
    item->value = (char*) malloc (strlen(value) + 1);
    
    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

HashTable* create_table(int size) {
    // Creates a new HashTable
    HashTable* table = (HashTable*) malloc (sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (HT_item**) malloc (table->size*sizeof(HT_item*));
    int i;
    for (i=0; i<table->size; i++)
        table->items[i] = NULL;

    return table;
}

void free_item(HT_item* item) {
    // Frees an item
    free(item->key);
    free(item->value);
    free(item);
}

void free_table(HashTable* table) {
    // Frees the table
    int i;
    for (i=0; i<table->size; i++) {
        HT_item* item = table->items[i];
        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

void handle_collision(HashTable* table, unsigned long index, HT_item* item) {
}

void ht_insert(HashTable* table, char* key, char* value) {
    // Create the item
    HT_item* item = create_item(key, value);

    // Compute the index
    unsigned long index = hash_function(key);

    HT_item* current_item = table->items[index];
    
    if (current_item == NULL) {
        // Key does not exist.
        if (table->count == table->size) {
            // Hash Table Full
            printf("Insert Error: Hash Table is full\n");
            // Remove the create item
            free_item(item);
            return;
        }
        
        // Insert directly
        table->items[index] = item; 
        table->count++;
    }

    else {
            // Scenario 1: We only need to update value
            if (strcmp(current_item->key, key) == 0) {
                strcpy(table->items[index]->value, value);
                return;
            }
    
        else {
            // Scenario 2: Collision
            // We will handle case this a bit later
            handle_collision(table, index, item);
            return;
        }
    }
}

char* ht_search(HashTable* table, char* key) {
    // Searches the key in the hashtable
    // and returns NULL if it doesn't exist
    int index = hash_function(key);
    HT_item* item = table->items[index];

    // Ensure that we move to a non NULL item
    if (item != NULL) {
        if (strcmp(item->key, key) == 0)
            return item->value;
    }
    return NULL;
}

void print_search(HashTable* table, char* key) {
    char* val;
    if ((val = ht_search(table, key)) == NULL) {
        printf("Key:%s does not exist\n", key);
        return;
    }
    else {
        printf("Key:%s, Value:%s\n", key, val);
    }
}

void print_table(HashTable* table) {
    printf("\nHash Table\n-------------------\n");
    int i;
    for (i=0; i<table->size; i++) {
        if (table->items[i]) {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("-------------------\n\n");
}

int main() {
    HashTable* ht = create_table(CAPACITY);
    ht_insert(ht, "1", "First address");
    ht_insert(ht, "2", "Second address");
    print_search(ht, "1");
    print_search(ht, "2");
    print_search(ht, "3");
    print_table(ht);
    free_table(ht);
    return 0;
}
