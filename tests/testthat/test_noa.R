# res_3cntr_locuswise
# res_3cntr_locuswise_NoA
source("include-test_noa.R")

context("NoA: Regression tests comparing to old version of package")

res_3cntr_locuswise <- DNAtools::Pnm_all(m = 3, theta = 0, probs = freqs, locuswise = TRUE)

res_3cntr_conv <- DNAtools::Pnm_all(m = 3, theta = 0, probs = freqs, locuswise = FALSE)
res_3cntr_NoA <- DNAtools::convolve(res_3cntr_locuswise)

test_that("PnmAll: numContrib = 3, theta = 0", {
  expect_equal(OLD_res_3cntr_locuswise, res_3cntr_locuswise)
})

test_that("convolve: numContrib = 3, theta = 0", {
  expect_equal(OLD_res_3cntr_NoA, res_3cntr_NoA)
  expect_equal(res_3cntr_conv, res_3cntr_NoA)
})

# A battery...
for (i in seq_along(test_big_cache)) {
  #print(i)
  x <- test_big_cache[[i]]
  
  if (x$m >= 2) {
    next
  }

  res_locuswise <- DNAtools::Pnm_all(m = x$m, theta = x$theta, probs = x$freqs, locuswise = TRUE)
  res_NoA <- DNAtools::convolve(res_locuswise)
  res_conv <- DNAtools::Pnm_all(m = x$m, theta = x$theta, probs = x$freqs, locuswise = FALSE)
  
  test_that(paste0("Battery #", i, ": PnmAll: numContrib = ", x$m, ", theta = ", x$theta), {
    expect_equal(res_locuswise, x$OLD_res_locuswise)
  })
  
  test_that(paste0("Battery #", i, ": convolve: numContrib = ", x$m, ", theta = ", x$theta), {
    expect_equal(res_NoA, x$OLD_res_NoA)
    expect_equal(res_NoA, res_conv)
  })
}

