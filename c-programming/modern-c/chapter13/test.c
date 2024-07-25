#include <stdio.h>

int main() {
    // Declare an array of strings
    char *s[3];

    // Assign values to the array elements
    s[0] = "Apple";
    s[1] = "Banana";
    s[2] = "Orange";
    
    // Print each string in the array
    for (int i = 0; i < 3; i++) {
        printf("%s ", s[i]);
    }
    
    char *s2[]  = {
        "one", "two", "three"
    };

    char *planets[] = {"Mercury", "Venus", "Earth","Mars", "Jupiter", "Saturn","Uranus", "Neptune", "Pluto"};
    for (int i = 0; i < 9; i++) {
        printf("%s ", planets[i]);
    }
    return 0;
}