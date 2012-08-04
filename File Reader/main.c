//
//  main.c
//  File Reader
//
//  Created by Darien So on 8/4/12.
//  Copyright (c) 2012 Nobody. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void PrintFileOutput(char *file);

int main(int argc, const char * argv[])
{
    PrintFileOutput("/Users/darienso/Desktop/test.txt");
    return 0;
}

void PrintFileOutput(char *file)
{
/*  MODEs
    ``r''   Open text file for reading.  The stream is positioned at the beginning of the file.
        
    ``r+''  Open for reading and writing.  The stream is positioned at the beginning of the file.
        
    ``w''   Truncate to zero length or create text file for writing.  The stream is positioned at the
        beginning of the file.
        
    ``w+''  Open for reading and writing.  The file is created if it does not exist, otherwise it is trun-
        cated.  The stream is positioned at the beginning of the file.
        
    ``a''   Open for writing.  The file is created if it does not exist.  The stream is positioned at the
        end of the file.  Subsequent writes to the file will always end up at the then current end of
        file, irrespective of any intervening fseek(3) or similar.
                        
    ``a+''  Open for reading and writing.  The file is created if it does not exist.  The stream is posi-
        tioned at the end of the file.  Subsequent writes to the file will always end up at the then
        current end of file, irrespective of any intervening fseek(3) or similar.
 */
    
    //create a buffer to hold the text
    char *textBuffer = calloc(100,sizeof(char));
    const char *mode = "r";
    
    FILE *theFile = fopen(file, mode);//get a file stream
    int bytesRead = 0;
    char *bufferPosition = textBuffer;
    int numberOfBytes = 0;
    while(!feof(theFile))
    {
        numberOfBytes = (int)fread(textBuffer, sizeof(char), 1, theFile);
        bytesRead += numberOfBytes;
        textBuffer++;
    }
    textBuffer = bufferPosition;

    //print out buffer
    for(int i=0;i<bytesRead;i++)
    {
        printf("%c",textBuffer[i]);
    }
    printf("\n\n");//print out newlines for better view in output window
    fclose(theFile);
}

