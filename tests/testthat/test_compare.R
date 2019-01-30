# OLD_db_comp_dbExample_5
#source("include-test_compare.R")
# Loads/source()s helper-test_compare.R

context("dbCompare: Regression tests comparing to old version of package")

data(dbExample)

################################################################################

test_that("dbCompare: dbExample, hit = 5, threads = 1", {
  db_comp_dbExample_5_t1 <- DNAtools::dbCompare(dbExample, hit = 5, trace = FALSE, threads = 1)
  
  expect_equal(OLD_db_comp_dbExample_5, db_comp_dbExample_5_t1)
})

test_that("dbCompare: dbExample, hit = 5, threads = 3", {
  db_comp_dbExample_5_t3 <- DNAtools::dbCompare(dbExample, hit = 5, trace = FALSE, threads = 3)
  
  expect_equal(OLD_db_comp_dbExample_5, db_comp_dbExample_5_t3)
})


test_that("dbCompare: threaded vs non-threaded: small data", {
  for (h in c(5, 7)) {
    a1 <- DNAtools::dbCompare(dbExample, hit = h, trace = FALSE, threads = 1)
    a2 <- DNAtools::dbCompare(dbExample, hit = h, trace = FALSE, threads = 2)
    a3 <- DNAtools::dbCompare(dbExample, hit = h, trace = FALSE, threads = 3)
    a4 <- DNAtools::dbCompare(dbExample, hit = h, trace = FALSE, threads = 4)
    
    expect_equal(a1$m, a2$m, info = paste0("hit = ", h))
    expect_equal(a1$m, a3$m, info = paste0("hit = ", h))
    expect_equal(a1$m, a4$m, info = paste0("hit = ", h))
  }
})

test_that("dbCompare: threaded vs non-threaded: medium data", {
  db_medium <- rbind(dbExample, dbExample)
  
  for (h in c(5, 7)) {
    a1 <- DNAtools::dbCompare(db_medium, hit = h, trace = FALSE, threads = 1)
    a3 <- DNAtools::dbCompare(db_medium, hit = h, trace = FALSE, threads = 3)
    
    # Ordering
    a1$hits <- a1$hits[order(a1$hits$id1, a1$hits$id2), ]
    a3$hits <- a3$hits[order(a3$hits$id1, a3$hits$id2), ]
    rownames(a1$hits) <- NULL
    rownames(a3$hits) <- NULL
    
    a1$m
    a3$m
    a1$m - a3$m

    expect_equal(a1, a3, info = paste0("hit = ", h))
  }
})

if (FALSE) {
  db_big <- rbind(dbExample, dbExample, dbExample, dbExample)
  db_big <- rbind(db_big, db_big)
  nrow(db_big)
  
  rbenchmark::benchmark(
    threads_4 = DNAtools::dbCompare(db_big, hit = 5, trace = FALSE, threads = 4),
    single = DNAtools::dbCompare(db_big, hit = 5, trace = FALSE, threads = 1),
    replications = 2
  )
  
  microbenchmark::microbenchmark(
    threads_4 = DNAtools::dbCompare(db_big, hit = 5, trace = FALSE, threads = 4),
    single = DNAtools::dbCompare(db_big, hit = 5, trace = FALSE, threads = 1),
    times = 2
  )
}

################################################################################

if (FALSE) {
  test_that("dbCompare: dbExample, hit = 5, threads = 2", {
    db_comp_dbExample_5_t2 <- DNAtools::dbCompare(dbExample, hit = 5, trace = FALSE, threads = 2)
    OLD_db_comp_dbExample_5_sorted <- OLD_db_comp_dbExample_5
  
    # Sort:
    db_comp_dbExample_5_t2$hits <- db_comp_dbExample_5_t2$hits[with(db_comp_dbExample_5_t2$hits, order(id1, id2, match, partial)), ]
    OLD_db_comp_dbExample_5_sorted$hits <- OLD_db_comp_dbExample_5_sorted$hits[with(OLD_db_comp_dbExample_5_sorted$hits, order(id1, id2, match, partial)), ]
    # Remove row names
    rownames(db_comp_dbExample_5_t2$hits) <- NULL
    rownames(OLD_db_comp_dbExample_5_sorted$hits) <- NULL
  
    expect_equal(OLD_db_comp_dbExample_5_sorted, db_comp_dbExample_5_t2)
  })
    
  
  test_that("dbCompare: !!!RcppParallel!!! dbExample, hit = 5, threads = 2", {
    db_comp_dbExample_5_t2 <- DNAtools::dbCompare(dbExample, hit = 5, trace = FALSE, threads = 666)
    OLD_db_comp_dbExample_5_sorted <- OLD_db_comp_dbExample_5
    
    # Sort:
    db_comp_dbExample_5_t2$hits <- db_comp_dbExample_5_t2$hits[with(db_comp_dbExample_5_t2$hits, order(id1, id2, match, partial)), ]
    OLD_db_comp_dbExample_5_sorted$hits <- OLD_db_comp_dbExample_5_sorted$hits[with(OLD_db_comp_dbExample_5_sorted$hits, order(id1, id2, match, partial)), ]
    # Remove row names
    rownames(db_comp_dbExample_5_t2$hits) <- NULL
    rownames(OLD_db_comp_dbExample_5_sorted$hits) <- NULL
    
    expect_equal(OLD_db_comp_dbExample_5_sorted, db_comp_dbExample_5_t2)
    #expect_equal(1, 2)
  })
  
  
}

