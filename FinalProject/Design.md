## Under The Hood 

---
### The Idea

I knew I wanted some sort of "on-the-fly" generator that could take a phrase and build off of that. 
How exactly I was going to do that was unknown to me until I started looking through aubio. 
Even though I didn't use it for this iteration of the project I drew upon a lot of its ideas - primarily onset and pitch detection. 
On other projects using aubio I noticed that it functioned as a dictionary to refernce certain pitches, frequencies, start/end times, etc. 
They'd then feed this data to their program via .txt file that would then be utilized in other various forms. Here's two examples using aubio that I based my project off of:

[Python Music Onset Beat Detection](https://www.youtube.com/watch?v=aMMI0nAKgI0)

[Processing Music on the Fly with Python](https://www.youtube.com/watch?v=at2NppqIZok)

Using the aforementioned links regarding aubio I figured out a process I'd need to implement my phrase generator. It goes as follow:

1. Have some reference file the computer can feed off of
2. Calculate the probability of where a chord/word is going based off of previous data
3. Randomly choose one option via probability distribution. 
4. Repeat steps 2 & 3 until *n* length 
5. Present final output in terminal 

---

### Execution

Now that the idea was set there were many attempts at executing *said idea*. 

My first idea was using aubio to identify pitch and onset. It'd feed data into a matrix and initiate a random walk to the values - much like the Midterm - and output 
a text file or .wav file with the new data. While the first versions of this worked, it did not always comply harmoniously with the music theory. Seeing as the program would read frequencies as integers and not actual 
note values the output would play out of tune. It's as if in one measure it's in 440Hz and then it's in 432Hz. There were also fallacies when inputting .txt files as the program would only generate new letters rather than words.
It couldn't distinguish between them. Seeing as this counter-intuitive and unproductive, I decided to change my approach to the project.

My second idea (and final) was using linear regression to determine the probability of what would happen. The computer would be constantly fed data and at a certain point would start creating its
own data. I implemented the MCMC (Markov Chain Monte Carlos) model for my regression analysis. The dependent variable (Y) - the new data - would function off of an unknown parameter (B) and the independent variables (X) - the previous data. 
There'd also be a variable implented for the randomness (e)
of the program. Here's the code I based my ```dictionary.c``` and ```ntarray.c``` off of:
```
import scipy.stats
# don't forget to generate the 500 random samples as in the previous post
sigma_e = 3.0

# Similar to last post, let's initially believe that a, b follow Normal distribution with mean 0.5 and stadndard deviation 0.5
# it returns the probability of seeing beta under this belief
def prior_probability(beta):
    a = beta[0]     # intercept
    b = beta[1]     # slope
    a_prior = scipy.stats.norm(0.5, 0.5).pdf(a)
    b_prior = scipy.stats.norm(0.5, 0.5).pdf(b)
    # log probability transforms multiplication to summation
    return np.log(a) + np.log(b)

# Given beta, the likehood of seeing x and y
def likelihood_probability(beta):
    a = beta[0]     # intercept
    b = beta[1]     # slope
    y_predict = a  + b * x
    single_likelihoods = scipy.stats.norm(y_predict, sigma_e).pdf(y)        # we know sigma_e is 3.0
    return np.sum(np.log(single_likelihoods))

# We don't need to know the denominator of support f(y)
# as it will be canceled out in the acceptance ratio
def posterior_probability(beta):
    return likelihood_probability(beta) + prior_probability(beta)

# jump from beta to new beta
# proposal function is Gaussian centered at beta
def proposal_function(beta):
    a = beta[0]
    b = beta[1]
    a_new = np.random.normal(a, 0.5)
    b_new = np.random.normal(b, 0.5)
    beta_new = [a_new, b_new]
    return beta_new

# run the Monte Carlo
beta_0 = [0.5, 0.5]        # start value
results = np.zeros([50000,2])            # record the results
results[0,0] = beta_0[0]
results[0, 1] = beta_0[1]
for step in range(1, 50000):               # loop 50,000 times
    print('step: {}'.format(step))

    beta_old = results[step-1, :]
    beta_proposal = proposal_function(beta_old)

    # Use np.exp to restore from log numbers
    prob = np.exp(posterior_probability(beta_proposal) - posterior_probability(beta_old))

    if np.random.uniform(0,1) < prob:
        results[step, :] = beta_proposal    # jump
    else:
        results[step, :] = beta_old         # stay

burn_in = 10000
beta_posterior = results[burn_in:, :]
print(beta_posterior.mean(axis=0))        # use average as point estimates

# present the results
fig = plt.figure()
ax1 = fig.add_subplot(121)
ax1.hist(beta_posterior[:,0], bins=20, color='blue')
ax1.axvline(beta_posterior.mean(axis=0)[0], color='red', linestyle='dashed', linewidth=2)
ax1.title.set_text('Posterior -- Intercept')
ax2 = fig.add_subplot(122)
ax2.hist(beta_posterior[:,1], bins=20, color='blue')
ax2.axvline(beta_posterior.mean(axis=0)[1], color='red', linestyle='dashed', linewidth=2)
ax2.title.set_text('Posterior -- Slope')
plt.show() 
```
How this worked for my program was as follows:

1. Take a corpus of data from an input file ```paraphrace.c```
2. Make a hashmap or dictionary with all the chords/words ```dictionary.c```
3. Analyze each individual data point as a string in an array ```ntarray.c```
4. Determine probablity of new words based off of independent variables (the previous words) ```dictionary.c```
5. Produce the dependent variable ```main.c```
6. Repeat until ```wordcount``` is reached ```main.c```

At first I ran everything in one file but saw that the program would constantly crash. It wasn't long but in terms of lines of codes
but I realized I was asking the computer to make an array for the probability of one data point to go to another or recurse on itself. That's already more than twice the
data being processed and analyzed than was being put in. I seperated everything into a individual functions that I'd just call upon in the main. Wow. Look at me using modular programming.

Anywho, this iteration is optimized to input .txt files. For this I used NLP (natural language processing) to get my output. One of the previous saves had it running .wav files but there were too many issues.
There was too much delay in the output (up to six hours), I'd often run out of RAM, and it'd crash my MAC. I'm sure that even if I properly allocated
memory space there'd still be mishaps in terms of processing time - it just takes too long. I opted for something that worked properly and just changed variables to recognize words rather than MIDI.
I also removed the ```portMIDI``` and ```libsndfile``` from the program as to not take up excessive space.

At the end of it all, I had four programs and four libraries to call on. It's too much of a hassle to compile each one so I decided to make a Makefile 
get everything set up. I rightfully called it "Apollo" after the God of Music and Poetry.
Here's the rest of the sources I used on this project.

[MCMC Linear Regression](https://letianzj.github.io/mcmc-linear-regression.html)

[Regression Analysis](https://en.wikipedia.org/wiki/Regression_analysis)

[Markov Chain for Musicians](https://towardsdatascience.com/markov-chain-for-music-generation-932ea8a88305)

[Music-Generator](https://github.com/andrewpak582/music-generator)

[Happy-Birthday-Markov](https://github.com/ekand/musical-curiosities/tree/main/happy-birthday-markov)

[Markov Chains](https://www.youtube.com/watch?v=eGFJ8vugIWA)

[NLP](https://www.youtube.com/watch?v=MGVdu39gT6k)