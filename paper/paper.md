---
title: 'DNAtools: Tools for Analysing Forensic Genetic DNA Data'
tags:
  - short tandem repeat markers
  - forensic genetics
  - autosomal markers
  - population genetics
  - weight of evidence
authors:
 - name: Torben Tvedebrink
   orcid: 0000-0002-9292-8476
   affiliation: 1
 - name: Mikkel Meyer Andersen
   orcid: 0000-0002-0234-0266
   affiliation: 1
 - name: James Michael Curran
   orcid: 0000-0003-3323-6733
   affiliation: 2
affiliations:
 - name: Department of Mathematical Sciences, Aalborg University, Denmark
   index: 1
 - name: Department of Statistics, University of Auckland, New Zealand
   index: 2
date: 10 Dec 2019
bibliography: paper.bib
---

# Summary

DNA evidence is the pre-eminent tool in the modern forensic scientists toolbox. It is widely accepted by the public as well as in the scientific and legal communities, and it has been instrumental in determining both the innocence and guilt of individuals involved in the legal process. Despite this widespread acceptance there is unease regarding the statistical measures used to evaluate DNA evidence amongst some of members of all these communities. 

The prevailing technology in forensic genetics is that of capillary electrophoresis [@butler2010], which measures the lengths of so-called *short tandem repeat* regions on the DNA (STR markers). With increasing number of STR markers, the random match probabilities are in the order of $10^{-20}$, which some people regard the random match probabilities associated with DNA evidence as just too small or basically unsupportable. The random match probabilities express the probability that a randomly chosen individual has *a specific* DNA profile, given we know that at least one other (usually a person of interest) has this profile [@DJBwoe2]. 

The fact that there exists near matches in a database of DNA profiles have caused some concern in the community and among end-users [@troyer2001] (see also the webpage "[Arizona DNA Database Matches](http://dna-view.com/ArizonaMatch.htm)" by Charles Brenner). However, making all pairwise comparisons and counting their coinciding alleles do not relate to a specific DNA profile [@weir2004,@weir2007]. Hence, one has to use the correct probabilities and also account for the fact the number of comparisons are $N(N+1)/2$ for a database of size $N$. The `DNAtools` package implements the methodologies of @tvedebrink2012 for efficient computations of the expectation and variance of the number of matches.

The analysis of mixed DNA traces have proven to be one of the most challenging tasks in forensic genetics. DNA mixtures, as they are referred to, is the trace observed when two or more individuals have contributed biological material to a DNA trace. Assessing the number of contributors to a DNA mixture is difficult. One indicator is the number of distinct alleles in the stain -- the more alleles the more contributors. `DNAtools` implements the expression of @tvedebrink2014, where the distribution of the number of distinct alleles can be computed, while accounting for subpopulation effects by the $\theta$-correction [@tvedebrink2014].

The documentation of `DNAtools` consists of manual pages for the various available functions, articles describing how to perform contiguous analyses (*vignettes*), and unit tests.

# References

