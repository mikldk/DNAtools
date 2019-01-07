# OLD_db_comp_dbExample_5
source("include-test_compare.R")

context("dbCompare: Regression tests comparing to old version of package")

data(dbExample)

################################################################################

test_that("dbCompare: dbExample, hit = 5, threads = 1", {
  db_comp_dbExample_5_t1 <- DNAtools::dbCompare(dbExample, hit = 5, trace = FALSE, threads = 1)
  
  expect_equal(OLD_db_comp_dbExample_5, db_comp_dbExample_5_t1)
})


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

