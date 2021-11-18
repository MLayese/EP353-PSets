#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sndfile.h> 

#define kBufferSize 1
#define kSampleRate 44100
#define kSec 1
#define kNumFrames (kSampleRate * kSec)
#define kNumChannels 2
#define kFormat (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define kAmp 1
#define kLineInter ((0 - kAmp) / (kNumFrames - 1))

int main(void)
{

    long long filesize;
    //Initialize SF_INFO with 0s (memset is in string.h library)

    SNDFILE *inFile = NULL, *outFile = NULL; //pointers to a sound files
    SF_INFO sfInfo; //hold an information about a sound file
    memset(&sfInfo, 0, sizeof(SF_INFO));

    //Open the original sound file as read mode
    inFile = sf_open("sine.wav", SFM_READ, &sfInfo);
    if(!inFile)
    {
        printf ("Error : could not open file : sine.wav\n");
        puts (sf_strerror (NULL));
        return 1;
    }

    //Check if the file format is in good shape
    if(!sf_format_check(&sfInfo))
    {	
        sf_close(inFile);
        printf("Invalid encoding\n");
        return 1;
    }

    filesize = sfInfo.frames;
    printf("%lld\n", filesize);

    //Write in the new .wav file using "Envelope.wav"
    outFile = sf_open("Envelope.wav", SFM_WRITE, &sfInfo);

    float *buffer = (float*) malloc(filesize * sizeof(float));
    float attackTime = (float) filesize * 0.1;
    for (int i = 0; i < attackTime; i++) {
      buffer[i] = buffer[i]*((float)i/attackTime); //simple interpolation
    }
    for (size_t i = attackTime; i < filesize; i++) {
      float envelope = 1.0 + ((float)i - attackTime) * (- 1.0/(filesize - attackTime)); //linear interpolation algorithm
      buffer[i] = buffer[i] * envelope;
    }
    sf_write_float(outFile, buffer, filesize);

  sf_close(inFile); //closing out the files we were using
	sf_close(outFile);



    //Close the open files
    sf_close(inFile);
    sf_close(outFile);
    free(buffer);

    return 0;
}

/*y0 is the starting value of the envelope.

y1 is the ending value of the envelope.

x is the current index of the buffer that we are applying to the envelope.

x0 is the starting index of the buffer.

x1 is the ending index of the buffer.*/