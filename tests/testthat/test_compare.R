# OLD_db_comp_dbExample_5
source("include-test_compare.R")

context("dbCompare: Regression tests comparing to old version of package")

data(dbExample)

################################################################################

test_that("dbCompare: dbExample, hit = 5, threads = 1", {
  db_comp_dbExample_5_t1 <- DNAtools::dbCompare(dbExample, hit = 5, trace = FALSE, threads = 1)
  
  expect_equal(OLD_db_comp_dbExample_5, db_comp_dbExample_5_t1)
})


test_that("dbCompare: threaded vs non-threaded", {
  for (h in c(5, 7)) {
    a1 <- DNAtools::dbCompare(dbExample, hit = h, trace = FALSE, threads = 1)
    a2 <- DNAtools::dbCompare(dbExample, hit = h, trace = FALSE, threads = 2)
    a3 <- DNAtools::dbCompare(dbExample, hit = h, trace = FALSE, threads = 3)
    a4 <- DNAtools::dbCompare(dbExample, hit = h, trace = FALSE, threads = 4)
    
    expect_equal(a1, a2, info = paste0("hit = ", h))
    expect_equal(a1, a3, info = paste0("hit = ", h))
    expect_equal(a1, a4, info = paste0("hit = ", h))
  }
})

if (FALSE) {
  db_big <- rbind(dbExample, dbExample, dbExample, dbExample)
  nrow(db_big)
  
  microbenchmark::microbenchmark(
    threads_4 = DNAtools::dbCompare(db_big, hit = 7, trace = FALSE, threads = 4),
    single = DNAtools::dbCompare(db_big, hit = 7, trace = FALSE, threads = 1),
    times = 3
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

