## Makes all permuations of a vector and returns a matrix // Based on the 'multicool' package
## of Prof. James M. Curran
permAll <- function(x) {
  if (length(x) == 1) 
    return(x)
  xx = initMC(x)
  allPerm(xx)
}
