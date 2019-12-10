
<!-- README.md is generated from README.Rmd. Please edit only README.Rmd! -->

# DNAtools

[![Build
Status](https://travis-ci.org/mikldk/DNAtools.svg?branch=master)](https://travis-ci.org/mikldk/DNAtools)
[![Build
status](https://ci.appveyor.com/api/projects/status/1861od7todeskm5p/branch/master?svg=true)](https://ci.appveyor.com/project/mikldk/DNAtools/branch/master)

Development version of the DNAtools R-package.

## Install

To build and install from Github using R 3.3.0 (or later) and the R
`devtools` package 1.11.0 (or later) run this command from within `R`:

    devtools::install_github("mikldk/DNAtools", 
                             build_opts = c("--no-resave-data", "--no-manual"))

You can also install the package without vignettes if needed as follows:

    devtools::install_github("mikldk/DNAtools")

## Contribute, issues, and support

Please use the issue tracker at
<https://github.com/mikldk/DNAtools/issues> if you want to notify us of
an issue or need support. If you want to contribute, please either
create an issue or make a pull request.

## Getting started

See documentation included in package (vignettes and manual) at
<https://mikldk.github.io/DNAtools/>.

### Small example

Please read the vignettes for more elaborate explanations than those
given below. The below example is meant to illustrate some of the
functionality the package provides in a compact fashion.

Say that we have a reference database:

``` r
data(dbExample, package = "DNAtools")
head(dbExample)[, 2:7]
#>   D16S539.1 D16S539.2 D18S51.1 D18S51.2 D19S433.1 D19S433.2
#> 1        11        11       15       21        14        14
#> 2        13        12       15       14        16        16
#> 3         9         9       13       17        14        14
#> 4        11        12       14       15        15        13
#> 5        12        12       17       12      15.2        13
#> 6         9        13       17       14        13        14
dim(dbExample)
#> [1] 1000   21
```

One could ask: What is the distribution of the number of alleles
observed in a three person mixture? This can be easily calculated by
this package. First we find the allele frequencies:

``` r
allele_freqs <- lapply(1:10, function(x){
  al_freq <- table(c(dbExample[[x*2]], dbExample[[1+x*2]]))/(2*nrow(dbExample))
  al_freq[sort.list(as.numeric(names(al_freq)))]
})
names(allele_freqs) <- sub("\\.1", "", names(dbExample)[(1:10)*2])
```

Now, the distribution of the number of alleles in a three person mixture
can be calculated. We focus on the D16S539 locus:

``` r
allele_freqs$D16S539
#> 
#>      8      9     10     11     12     13     14 
#> 0.0005 0.1910 0.0195 0.2755 0.2860 0.2255 0.0020
noa <- Pnm_locus(m = 3, theta = 0, alleleProbs = allele_freqs$D16S539)
names(noa) <- seq_along(noa)
noa
#>           1           2           3           4           5           6 
#> 0.001164550 0.089551483 0.492098110 0.389529448 0.027534048 0.000122361
```

So it is most likely that a three person mixture on D16S539 has 3
alleles.

This can be done for all loci at once:

``` r
noa <- Pnm_all(m = 3, theta = 0, probs = allele_freqs, locuswise = TRUE)
noa
#>                    1           2         3         4          5            6
#> D16S539 0.0011645502 0.089551483 0.4920981 0.3895294 0.02753405 1.223610e-04
#> D18S51  0.0002318216 0.017959845 0.1779391 0.4378291 0.31153235 5.450770e-02
#> D19S433 0.0035865859 0.089632027 0.3625087 0.3976107 0.13518050 1.148149e-02
#> D21S11  0.0038709572 0.096894566 0.3687696 0.3853717 0.13233905 1.275409e-02
#> D2S1338 0.0000431618 0.006746923 0.1068460 0.3899646 0.39812735 9.827197e-02
#> D3S1358 0.0016039659 0.078199562 0.3939623 0.4258141 0.09768694 2.733108e-03
#> D8S1179 0.0007349290 0.039905625 0.2705804 0.4539819 0.21275810 2.203902e-02
#> FGA     0.0000742453 0.010955567 0.1455096 0.4287449 0.34698332 6.773235e-02
#> TH01    0.0025373680 0.111902320 0.4515490 0.3761236 0.05783065 5.706482e-05
#> vWA     0.0008047420 0.054208046 0.3452015 0.4542519 0.13852872 7.005098e-03
```

We can also find the convolution and thereby the total number of
distinct alleles:

``` r
noa <- Pnm_all(m = 3, theta = 0, probs = allele_freqs)
noa
#>            1            2            3            4            5            6 
#> 0.000000e+00 0.000000e+00 0.000000e+00 0.000000e+00 0.000000e+00 0.000000e+00 
#>            7            8            9           10           11           12 
#> 0.000000e+00 0.000000e+00 0.000000e+00 2.891086e-32 2.089630e-29 6.726379e-27 
#>           13           14           15           16           17           18 
#> 1.282439e-24 1.625439e-22 1.457361e-20 9.605595e-19 4.777072e-17 1.827088e-15 
#>           19           20           21           22           23           24 
#> 5.455402e-14 1.287742e-12 2.429902e-11 3.702434e-10 4.597777e-09 4.693091e-08 
#>           25           26           27           28           29           30 
#> 3.968035e-07 2.798451e-06 1.656443e-05 8.274188e-05 3.504602e-04 1.263902e-03 
#>           31           32           33           34           35           36 
#> 3.894858e-03 1.028680e-02 2.334381e-02 4.560959e-02 7.684831e-02 1.117952e-01 
#>           37           38           39           40           41           42 
#> 1.405269e-01 1.526853e-01 1.433854e-01 1.163205e-01 8.143643e-02 4.912883e-02 
#>           43           44           45           46           47           48 
#> 2.548638e-02 1.133857e-02 4.311188e-03 1.394979e-03 3.821005e-04 8.802401e-05 
#>           49           50           51           52           53           54 
#> 1.691803e-05 2.685887e-06 3.478319e-07 3.616152e-08 2.955716e-09 1.846961e-10 
#>           55           56           57           58           59           60 
#> 8.484368e-12 2.703293e-13 5.435722e-15 5.774600e-17 2.098567e-19 1.565331e-22
```

So it is most likely that a three person mixture has 38 distinct alleles
on all loci combined.
