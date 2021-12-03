#             Final Project Proposal

### Likely Title of the project
* Apollo.ai? Maybe after the Greek God of Music - it's all I can think of right now.

### Project proposal
* My project would be creating an algo that procedurally generates music based off of what it hears. Specifically just based off a solo instrument (I'm thinking piano)

### The Deets 
* This'll be similar to the project I've been showing you these past couple of weeks (except now it'll be on C instead of Python). What the software will do is analyze a piece of music, take the essential parts of it (ie timbre, notes, note length, velocity, etc.) and improv based off that. This should be easier because it'll just focus on one instrument. You'll be able to run it in the terminal shell or (the easiest outcome I feel) something more collaborative like Google Colab. 

### Projected Outcome
* I've changed the scope of this project to be smaller in scale primarily focusing on just analyzing piano orchestration.
* Good Outcome:
    * compiles
    * recognizes solo instrumentation
    * able to take music and play back a phrase. It doesn't have to be a good phrase, just has to be something.
    
* Better Outcome:
    * All of **Good Outcome**
    * It'll play something and sound *somewhat* decent

* Best Outcome:
    * All of **Better Outcome**
    * The AI can generate actual phrases and not just a haphazard structure. 
    * The phrases themselves will have actual dynamics and musicality 
    * The audio quality won't be terrible

### The Next Steps
* To effectively execute this I'll have to make a program that can distinguish, analyze music and store them as values it can call upon later. Next it'd have to make a phrase based off the one it just heard. Obvioulsy, the more data it has to work with the better chance it has to come up with something somewhat decent.  I'll need to read up on some machine learning, AI-produced music algorithims, and reference aubio. I'll probably start small like have it go through one phrase and be able to change the notes.

