#include <stdio.h>
#include <string.h>
 
struct KeyValue {
    const char* key;
    int value;
};
 
int main() {
    struct KeyValue obj[] = {{"apple", 10}, {"banana", 5}, {"cherry", 8}};

    int arrayLength = sizeof(obj) / sizeof(obj[0]);
    
    for (int i = 0; i < arrayLength; i++) {
        const char* key = obj[i].key;
        int value = obj[i].value;
        printf("Key: %s, Value: %d\n", key, value);
    }
}