<!-- Uses markdown syntax for neat display at github. This is the most important thing to your user. Be not afraid that
	you are too long-winded. If you tell someone what the Battacharyya distance is, they probably will appreciate
	that even if they already know. Be also clear about its complexity, say if it is exponential in time or the 
	number of pixels for example. 

	Tips on syntax:
	
	Use pictures:
	  ![picture](https://raw.github.com/git_username/git_repos/master/module_name/some_doc_folder/picture.jpg)

	Use math notation (http://stackoverflow.com/questions/11256433):
	- Experiment on http://latex.codecogs.com/gif.latex?c=\sqrt{E/m} to check your equation
	- Encode the math part c=\sqrt{E/m} on http://www.url-encode-decode.com/urlencode
	- And write it in markdown syntax as:
	   ![equation](http://latex.codecogs.com/gif.latex?c%3D%5Csqrt%7BE%2Fm%7D)
-->

# NaiveBayesModule

## What does it do?

The NaiveBayesModule uses the naive Bayes probability model. It assumes supervised data in the form of a label and a
series of values. Each of these values correspond to a variable. During training a series of samples lead to a sample
average and sample variance for each label.

The conditional probability p(f0|c) is given by a Gaussian function: 

    p(f0|c)=1/sqrt(2*M_PI*c_s) exp( -1 (f0 - c_m)(f0 - c_m)) / 2*c_s*c_s)

Considering conditional independence given a label, the test will be:

    p(f0|c)*p(f1|c)*...

Here `f0` is feature 0, `f1` is feature 1 etc. 

Currently a uniform prior is used, the posterior is hence:

    p(c=c0|f0,...,fk) = p(c0) * p(f0|c) * ... * p(fk|c)

And `p(c0)` is just one divided by the number of possible class labels and not empirically estimated.

## How fast is it?

The NaiveBayesModule is not meant to be extremely fast. In the code there are comments sprinkled that allow faster
implementations. Especially when the data dimension becomes large, the multiplication for the posterior can better
be done by a summation in log-space.

Other things are already relative efficiently. For example, the mean and variance are calculated online according to 
one of the Knuth algorithms.

## How good is this tested?

This module does work perfectly with the example at 
[Wikipedia](https://en.wikipedia.org/wiki/Naive_Bayes_classifier#Document_Classification). That example is encapsulated
in a specific DatasetModule that you can find at this 
[github repository](https://github.com/mrquincle/aim_modules/tree/master/DatasetModule) as well.

## How to install?

Follow the instructions on [AIM website](http://dobots.github.com/aim/). 

## Where can I read more?

* [AIM website](http://dobots.github.com/aim/) 

## Copyrights
The copyrights of this module (2014) belong to:

- Author: Anne C. van Rossum
- Distributed Organisms B.V.

