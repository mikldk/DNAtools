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
---

# Summary

DNA evidence is the pre-eminent tool in the modern forensic scientists toolbox. It is widely accepted by the public, scientific and legal communities and it has been instrumental in determining both the innocence and guilt of individuals involved in the legal process. Despite this widespread acceptance there is unease regarding the statistical measures used to evaluate DNA evidence amongst some of members of all these communities. 

The prevailing technology in forensic genetics is that of capillary electrophoresis, which measaures the lengths of so-called *short tandem repeat* regions on the DNA (STR markers). With increasing number of STR markers, the random match probabilities are in the order of $10^{-20}$, which some people regard the random match probabilities associated with DNA evidence as just too small or basically unsupportable. The random match probabilities express the probability that two individals share *a specific* DNA profile at hand. 

The fact that there exists near matches in a database of DNA profiles have caused some concern in the community and among end-users [@troyer2001, @brenner2007]. However, making all pairwise comparisons and counting their coinciding alleles do not relate to a specific DNA profile [@weir2004,@weir2007]. Hence, one has to use the correct probabilities and also account for the fact the number of comparisons are $N(N+1)/2$ for a database of size $N$. The `DNAtools` package implements the methodologies of @tvedebrink2012 for efficient computations of the expectation and variance of the number of matches.

The analysis of mixed DNA traces have proven to be one of the most challenging tasks in forensic genetics. DNA mixtures, as they are referred to, is the trace observed when two or more individuals have contributed biological material to a DNA trace. Assessing the number of contributors to a DNA mixture is difficult. One indicator is the number of distinct alleles in the stain -- the more alleles the more contributors. `DNAtools` implements the expression of @tvedebrink2014, where the distribution of the number of distinct alleles can be computed, while accounting for subpopulation effects by the $\theta$-correction.

The documentation of `DNAtools` consists of manual pages for the various available functions, articles describing how to perform contiguous analyses (*vignettes*), and unit tests.

# References

---
references: 
- id: brenner2007
  author: 
    - family: Brenner 
      given: C
  title: Arizona DNA Database Matches.
  URL: http://dna-view.com/ArizonaMatch.htm
  issued:
    year: 2007
- id: budowle_1999
  author: 
    - family: Budowle 
      given: B
    - family: Moretti 
      given: TR
  title: Genotype Profiles for Six Population Groups at the 13 CODIS Short Tandem Repeat Core Loci and Other PCR-Based Loci.
  container-title: Forensic Science Communications 1(2).
  URL: http://www2.fbi.gov/hq/lab/fsc/backissu/july1999/budowle.htm
  issued:
    year: 1999
- id: curran2010
  author:
  - family: Curran 
    given: JM 
  - family: Buckleton 
    given: JS 
  issued:
    year: 2010
  title: Re Sign mistake in allele sharing probability formulae of Curran, et al.
  container-title: "Forensic Science International: Genetics, 4(3), 215--217."
- id: curran2007
  author:
  - family: Curran 
    given: JM
  - family: Walsh 
    given: SJ
  - family: Buckleton 
    given: J 
  issued: 
    year: 2007
  title: Empirical testing of estimated DNA frequencies.
  container-title: "Forensic Science International: Genetics, 1(3-4), 267--272."
- id: Rsolnp
  author: 
  - family: Ghalanos
    given: A
  - family: Theussl
    given: S
  issued: 
    year: 2012
  title: Rsolnp General Non-linear Optimization Using Augmented Lagrange Multiplier Method. 
  container-title: R package version 1.16.
- id: kaye2009
  author:
  - family: Kaye
    given: DH
  issued: 
    year: 2009
  title: "Trawling DNA Databases for Partial Matches: What Is the FBI Afraid Of?"
  container-title: Cornell Journal of Law and Public Policy, 19(1)
- id: mueller2008
  author:
  - family: Mueller
    given: LD
  issued: 
    year: 2008
  title: Can simple population genetic models reconcile partial match frequencies observed in large forensic databases?
  container-title: Journal of Genetics, 87(2), 101--108.
- id: troyer2001
  author:
  - family: Troyer
    given: K
  - family: Gilboy
    given: T
  - family: Koeneman
    given: B
  issued: 
    year: 2001
  title: A nine STR locus match between two apparently unrelated individuals using AmFlSTR Profiler Plus and Cofiler
  container-title: In Genetic Identity Conference Proceedings, 12th International Symposium on Human Identification.
- id: tvedebrink2010
  author:
  - family: Tvedebrink
    given: T
  issued:
    year: 2010
  title: Statistical Aspects of Forensic Genetics -- Models for Qualitative and Quantitative STR Data.
  container-title: Ph.D. thesis, Department of Mathematical Sciences, Aalborg University.
- id: tvedebrink2012
  author:
  - family: Tvedebrink
    given: T
  - family: Eriksen 
    given: PS
  - family: Curran
    given: JM
  - family: Mogensen
    given: HS
  - family: Morling 
    given: N
  issued:
    year: 2012
  title: Analysis of matches and partial-matches in a Danish DNA reference profile data set.
  container-title: "Forensic Science International: Genetics 6(3), 387-392."
- id: weir2004
  author:
  - family: Weir 
    given: BS
  title: Matching and partially-matching DNA profiles.
  container-title: Journal of Forensic Sciences, 49(5), 1009--1014.
  issued:
    year: 2004
- id: weir2007
  author: 
  - family: Weir 
    given: BS
  issued:
    year: 2007
  title: The rarity of DNA Profiles.
  container-title: The Annals of Applied Statistics, 1(2), 358--370.
- id: wiki_birthday
  author: Wikipedia 
  issued: 
    year: 2010
  title: Birthday problem.
  URL: http://en.wikipedia.org/wiki/Birthday_problem
- id: tvedebrink2014
  author:
  - family: Tvedebrink
    given: T
  title: On the exact distribution of the number of alleles in DNA mixtures
  container-title: International Journal of Legal Medicine; 128(3):427–37
  issued: 
    year: 2014
---
