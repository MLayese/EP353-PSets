#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sndfile.h>

#define kSampleRate 44100
#define kSec 1
#define kNumFrames (kSampleRate * kSec)
#define kNumChannels 2
#define kFormat (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define Interpolate ((float)i/attackTime)

int main(void) {
    SNDFILE *inFile = NULL, *outFile = NULL;
    SF_INFO sfInfo;
    long long kfilesize; //Double and float didn't work well so I used long long
    float *buffer = (float*) malloc(kfilesize * sizeof(float)); 
    
    memset(&sfInfo, 0, sizeof(SF_INFO));

    inFile = sf_open("sine.wav", SFM_READ, &sfInfo); opening the original file
    if(!inFile)
    {
        printf ("Error : could not open file : sine.wav\n");
        puts (sf_strerror (NULL));
        return 1;
    }

    if(!sf_format_check(&sfInfo))
    {
        sf_close(inFile);
		printf("Invalid encoding\n");
		return 1;
    }

kfilesize = sfInfo.frames;

  outFile = sf_open("envelope.wav", SFM_WRITE, &sfInfo); 

  if(!outFile)
    {
        printf ("Error : could not open file : envelope.wav\n"); //If it didn't open 
        puts (sf_strerror(NULL));
        return 1;
    }

    sf_read_float(inFile, buffer, kfilesize);

float attackTime = (float) kfilesize * 0.1; //I tried #define and putting this at the top...each time it wouldn't produce a sound
    for (int i = 0; i < attackTime; i++) 
    {
      buffer[i] = buffer[i]* Interpolate; //interpolation
    }
    for (size_t i = attackTime; i < kfilesize; i++) 
    {
        float envelope = 1.0 + ((float)i - attackTime) * (- 1.0/(kfilesize - attackTime)); //using the algo
        // At first I had the variables flipped but after flipping the parts around it worked
        buffer[i] = buffer[i] * envelope;
    }
    sf_write_float(outFile, buffer, kfilesize);

    sf_close(inFile); 
    sf_close(outFile);

  return 0;
}