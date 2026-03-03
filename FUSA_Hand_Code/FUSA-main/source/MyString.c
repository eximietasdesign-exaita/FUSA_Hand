#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MyString.h"
#define SIZE 20

// Global variables
static char g_inputString1[SIZE], g_inputString2[SIZE];
static char *g_resultString;
static bool g_compareResult;

// Function declarations (internal static functions)
static int calculateStringLength(const char *f_inputString);
static bool compareStrings(const char *f_firstString, const char *f_secondString);
static char* convertCase(char *f_inputString);
static char* convertToLowercase(char *f_inputString);
static char* convertToUppercase(char *f_inputString);
static char* concatenateStrings(const char *f_firstString, const char *f_secondString);
static void copyMemory(void *f_destination, const void *f_source, int f_numBytes);

// Definition of CallingAllfunctionsToMakeStaic function (non-static)
void CallingAllfunctionsToMakeStaic() {
    // Dummy user input (can use scanf in real case)
    g_resultString = convertCase(g_inputString1);
    g_resultString = convertToLowercase(g_inputString1);
    g_resultString = convertToUppercase(g_inputString1);
    g_resultString = concatenateStrings(g_inputString1, g_inputString2);
    copyMemory(g_inputString1, g_inputString2, sizeof(g_inputString2));
    g_compareResult = compareStrings(g_inputString1, g_inputString2);
}

// Static function implementations

// Function to calculate the length of a string
static int calculateStringLength(const char *f_inputString) {
    int l_length = 0;
    while (f_inputString[l_length] != '\0') {
        l_length++;
    }
    return l_length;
}

// Function to compare two strings for equality
static bool compareStrings(const char *f_firstString, const char *f_secondString) {
    int index;
    int l_firstLength = calculateStringLength(f_firstString);
    int l_secondLength = calculateStringLength(f_secondString);
    if (l_firstLength != l_secondLength) return false;

    for (index = 0; f_firstString[index] != '\0'; index++) {
        if (f_firstString[index] != f_secondString[index]) return false;
    }
    return true;
}

// Function to convert case of characters
static char* convertCase(char *f_inputString) {
    int index = 0;
    while (f_inputString[index] != '\0') {
        if (f_inputString[index] >= 'a' && f_inputString[index] <= 'z') {
            f_inputString[index] = f_inputString[index] - 32;
        } else if (f_inputString[index] >= 'A' && f_inputString[index] <= 'Z') {
            f_inputString[index] = f_inputString[index] + 32;
        }
        index++;
    }
    return f_inputString;
}

// Function to convert all uppercase letters in a string to lowercase
static char* convertToLowercase(char *f_inputString) {
    int index = 0;
    while (f_inputString[index] != '\0') {
        if (f_inputString[index] >= 'A' && f_inputString[index] <= 'Z') {
            f_inputString[index] = f_inputString[index] + 32;
        }
        index++;
    }
    return f_inputString;
}

// Function to convert all lowercase letters in a string to uppercase
static char* convertToUppercase(char *f_inputString) {
    int index = 0;
    while (f_inputString[index] != '\0') {
        if (f_inputString[index] >= 'a' && f_inputString[index] <= 'z') {
            f_inputString[index] = f_inputString[index] - 32;
        }
        index++;
    }
    return f_inputString;
}

// Function to concatenate two strings
static char* concatenateStrings(const char *f_firstString, const char *f_secondString) {
    int l_lengthFirst = calculateStringLength(f_firstString);
    int l_lengthSecond = calculateStringLength(f_secondString);
    char *l_resultString = (char *)malloc((l_lengthFirst + l_lengthSecond + 1) * sizeof(char));

    for (int i = 0; i < l_lengthFirst; i++) {
        l_resultString[i] = f_firstString[i];
    }
    for (int j = 0; j < l_lengthSecond; j++) {
        l_resultString[l_lengthFirst + j] = f_secondString[j];
    }
    l_resultString[l_lengthFirst + l_lengthSecond] = '\0';
    return l_resultString;
}

// Function to copy memory from source to destination
static void copyMemory(void *f_destination, const void *f_source, int f_numBytes) {
    char *l_dest = (char *)f_destination;
    const char *l_src = (const char *)f_source;
    for (int i = 0; i < f_numBytes; i++) {
        l_dest[i] = l_src[i];
    }
}
