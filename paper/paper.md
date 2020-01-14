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

The prevailing technology in forensic genetics is that of capillary electrophoresis [@butler2010], which measures the lengths of so-called *short tandem repeat* regions on the DNA (STR markers). One quantity of interest is the random match probability. The random match probability is defined as the probability that a randomly chosen individual has *a specific* DNA profile ($G_C$), given we know that at least one other (usually person $S$ of interest with genotype $G_S$) has this profile [@DJBwoe2].  We write this as
\[
\Pr(G_C \mid G_S \equiv G_C).
\]
Estimates of this probability become very small (in the order of $10^{-20}$) as the number of STR markers increases. Some people regard the small random match probabilities associated with DNA evidence as just too small or basically unsupportable. 

In 2001, Karen Troyer and others [@troyer2001] published a poster reporting the results of a *database matching* exercise. In such an exercise, every profile is compared to every other profile and the number of loci where the two profiles match is recorded. This is a very useful exercise, because, amongst other things it helps laboratories detect potentially erroneous entries in their databases. The Arizona laboratory, where Troyer worked, used the CODIS set of loci, which was a standardized set of 13 STR markers used in many jurisdictions across the US, including federally by the FBI. Troyer et al.'s poster [@troyer2001] reported that a 9 locus match had been found between two apparently unrelated individuals. This was information was seized upon by an enterprising defence lawyer, because at first glance, it seemed to cast doubt on extremely small match probabilities. That is, how could two unrelated individuals, in a database of 65,000 people, have the same (partial) profile, when the probability of this profile was at most 1 in 754 million ($7.54\times 10^{-8})? This issue is nicely summarized by Charles Brenner on his webpage "[Arizona DNA Database Matches](http://dna-view.com/ArizonaMatch.htm)". 

Weir [@weir2004;@weir2007] and others pointed out that this degree of matching is not surpriseing when one takes into account the total number of comparisons being made (about 4 billion in the Arizona case), and recognize that it is not the probability of a specific profile that is of interest, but rather the probability that *any* two loci would match at 9 loci. Hence, one has to use the correct probabilities and also account for the fact the number of comparisons to be made between all pairs of profiles for a database of size $N$ is $N(N+1)/2$ . The `DNAtools` package implements the methodology of @tvedebrink2012 for efficient computations of the expectation and variance of the number of matches. 
To our knowledge, `DNAtools` is the only software that can perform such computations. 

The analysis of mixed DNA traces have proven to be one of the most challenging tasks in forensic genetics. DNA mixtures, as they are referred to, are observed biological traces which are comprised of biological material from two or more individuals. Assessing the number of contributors to a DNA mixture is difficult. One indicator is the number of distinct alleles in the stain -- the more alleles the more contributors. `DNAtools` implements the expression of @tvedebrink2014, where the distribution of the number of distinct alleles can be computed, while accounting for subpopulation effects by the $\theta$-correction [@tvedebrink2014]. Equally, researchers looking at the efficacy of new multiplexes (in this context this is mainly about the number of and frequencies of alleles in newly included loci) are interested in understanding the probability that a mixture which truly consists of $n$ individuals appears to consist of $n-1$ individuals. This might happen, for example, when a two person mixture shows no more than two alleles per locus at every locus in a multiplex. `DNAtools` allows the rapid, and exact computation, of such probabilities for any number of individuals. 
To our knowledge, `DNAtools` is the only software that can perform such computations. 

The documentation of `DNAtools` consists of manual pages for the various available functions, articles describing how to perform contiguous analyses (*vignettes*), and unit tests.

# References

