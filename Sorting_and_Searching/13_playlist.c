#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000
#define TABLE_SIZE 1000003

typedef struct Node {
    long long key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node** table;
    int size;
} HashMap;

HashMap* create_hash_map(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->table = (Node**)calloc(size, sizeof(Node*));
    return map;
}

int hash(long long key, int size) {
    return key % size;
}

void insert(HashMap* map, long long key, int value) {
    int index = hash(key, map->size);
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = map->table[index];
    map->table[index] = new_node;
}

int get(HashMap* map, long long key) {
    int index = hash(key, map->size);
    Node* current = map->table[index];
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return 0;
}

void free_hash_map(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* current = map->table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map->table);
    free(map);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_N) {
        fprintf(stderr, "Invalid input for n\n");
        return 1;
    }
    
    HashMap* last_position = create_hash_map(TABLE_SIZE);
    
    int max_length = 0, start = 0;
    for (int end = 0; end < n; end++) {
        long long song_id;
        if (scanf("%lld", &song_id) != 1 || song_id < 1 || song_id > 1000000000) {
            fprintf(stderr, "Invalid input for song ID\n");
            free_hash_map(last_position);
            return 1;
        }
        
        int last_pos = get(last_position, song_id);
        if (last_pos > start) {
            start = last_pos;
        }
        insert(last_position, song_id, end + 1);
        max_length = max(max_length, end - start + 1);
    }

    printf("%d\n", max_length);
    free_hash_map(last_position);
    return 0;
}
