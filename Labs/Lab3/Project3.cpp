// String ADT Project3.cpp
// EE 312 Project 3 submission by
// Nathaniel Irwin
// nai293
// Slip days used: 0
// Spring 2021

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "UTString.h"

/*
 * Helper macro to find the signature of a UTString
 * Treat this like a function that takes a UTString*
 * Accesses a uint32_t from where the signature should be located
 */
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
 * adds null terminator and utstring signature to end of
 * meaningful length of ustring
 */
void capUTString(UTString* s){
    (s->string)[s->length] = '\0';
    /*(lenEnd)[4]= (SIGNATURE >> 24) & 0xff;
    (lenEnd)[3]= (SIGNATURE >> 16) & 0xff;
    (lenEnd)[2]= (SIGNATURE >> 8) & 0xff;
    (lenEnd)[1]= SIGNATURE & 0xff; //split 32 bit signature into 8 bit chars, stored little endian*/
    CHECK(s)= SIGNATURE;
}

/*
 * Checks if a UTString is valid or not.
 */
bool isOurs(const UTString* s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}

/*
 * Allocate a utstring on the heap.
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */
UTString* utstrdup(const char* src) {
    uint32_t len = 0;

    while(src[len]){
        len++;
    }

    UTString* str = (UTString*)malloc(sizeof(UTString));
    str->length = len;
    str->capacity = len;
    str->string = (char*)malloc(len*sizeof(char)+5);

    for(int i = 0; i < len; i++){
        (str->string)[i] = src[i];
    }

    capUTString(str);


    return str;
}

/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */
uint32_t utstrlen(const UTString* s) {
    assert(isOurs(s));
    return s->length;
}

/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s.
 * Update the length of s.
 * Return s with the above changes. */
UTString* utstrcat(UTString* s, const char* suffix) {
    assert(isOurs(s));
    int oldLen = s->length;
    uint32_t canAdd = s->capacity - oldLen;
    int i = 0;
    while(suffix[i] && i < canAdd){
        (s->string)[oldLen+i] = suffix[i];
        i++;
    }
    (s->length) += i;
    capUTString(s);
    return s;
}

/*
 * Copy src into dst.
 *  dst must be a valid UTString.
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst.
 * Return dst with the above changes.
 */
UTString* utstrcpy(UTString* dst, const char* src) {
    assert(isOurs(dst));
    int i = 0;
    while(src[i] && i < dst->capacity){
        (dst->string)[i] = src[i];
        i++;
    }
    dst->length = i;

    capUTString(dst);

    return dst;
}

/*
 * Free all memory associated with the given UTString.
 */
void utstrfree(UTString* self) {
    assert(isOurs(self));
    free(self->string);
    free(self);
}

/*
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity,
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata.
 * Return s with the above changes.
 */
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    assert(isOurs(s));
    if(s->capacity >= new_capacity) {
        return s;
    }
    else{
        (s->string) = (char*)realloc(s->string, new_capacity*sizeof(char)+5);
        s->capacity = new_capacity;
        return s;
    }
}

