//
//  main.c
//  wc
//
//  Created by Jiaxing Liu on 3/31/19.
//  Copyright © 2019 Jiaxing Liu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    // the goal is to build a word count program that works like the wc in Ubuntu
    // the output should have the form as count of newline, words, bytes, filename
    
    // parse the input args
    int input;
    const char* fileName;
    if (argc == 1) { // no input args, read stdin
        input = STDIN_FILENO;
        fileName = NULL;
    } else if (argc == 2) { // 1 input args as filename
        input = open(argv[1], O_RDONLY);
        fileName = argv[1];
        if (input < 0) {
            printf("Cannot open file %s\n", fileName);
            return input;
        }
    } else {
        printf("Usage: wc or wc FILENAME\n");
        return -1;
    }
    
    
    int byteCount = 0;
    int newlineCount = 0;
    int wordCount = 0;
    char buffer[1];
    char x;
    int isLastWhitespace = 1;
    int isCurrentWhitespace = 0;
    
    // read the data byte by byte
    while(read(input, buffer, 1)) {
        x = buffer[0];
        // increase byte count
        byteCount ++;
        
        // increase newline count
        if (x == '\n') newlineCount ++;
        
        // increase word count if this char is not a whitespace-like character and the previous is a whitespace-like character
        // check if curent char is whitespace
        if (x >= '!' && x <= '~') {
            isCurrentWhitespace = 0;
        } else {
            isCurrentWhitespace = 1;
        }
        if (isLastWhitespace && !isCurrentWhitespace) {
            wordCount += 1;
        }
        isLastWhitespace = isCurrentWhitespace;
        
    }
    
    // print the result
    if (fileName == NULL) {
        printf("%d %d %d\n", newlineCount, wordCount, byteCount);
    } else {
        printf("%d %d %d %s\n", newlineCount, wordCount, byteCount, fileName);
        close(input);
    }
    
    return 0;
    
}
