// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// score_rcpp
Rcpp::IntegerVector score_rcpp(const Rcpp::IntegerVector& prof1, const Rcpp::IntegerVector& prof2, int numLoci, bool useWildCard, bool useRareAllele);
RcppExport SEXP _DNAtools_score_rcpp(SEXP prof1SEXP, SEXP prof2SEXP, SEXP numLociSEXP, SEXP useWildCardSEXP, SEXP useRareAlleleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::IntegerVector& >::type prof1(prof1SEXP);
    Rcpp::traits::input_parameter< const Rcpp::IntegerVector& >::type prof2(prof2SEXP);
    Rcpp::traits::input_parameter< int >::type numLoci(numLociSEXP);
    Rcpp::traits::input_parameter< bool >::type useWildCard(useWildCardSEXP);
    Rcpp::traits::input_parameter< bool >::type useRareAllele(useRareAlleleSEXP);
    rcpp_result_gen = Rcpp::wrap(score_rcpp(prof1, prof2, numLoci, useWildCard, useRareAllele));
    return rcpp_result_gen;
END_RCPP
}
// compare
Rcpp::List compare(const Rcpp::StringVector& DB, int numLoci, int bigHit, bool trace, int single, bool useWildcard, bool useWildcardEffect, bool useRallele);
RcppExport SEXP _DNAtools_compare(SEXP DBSEXP, SEXP numLociSEXP, SEXP bigHitSEXP, SEXP traceSEXP, SEXP singleSEXP, SEXP useWildcardSEXP, SEXP useWildcardEffectSEXP, SEXP useRalleleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::StringVector& >::type DB(DBSEXP);
    Rcpp::traits::input_parameter< int >::type numLoci(numLociSEXP);
    Rcpp::traits::input_parameter< int >::type bigHit(bigHitSEXP);
    Rcpp::traits::input_parameter< bool >::type trace(traceSEXP);
    Rcpp::traits::input_parameter< int >::type single(singleSEXP);
    Rcpp::traits::input_parameter< bool >::type useWildcard(useWildcardSEXP);
    Rcpp::traits::input_parameter< bool >::type useWildcardEffect(useWildcardEffectSEXP);
    Rcpp::traits::input_parameter< bool >::type useRallele(useRalleleSEXP);
    rcpp_result_gen = Rcpp::wrap(compare(DB, numLoci, bigHit, trace, single, useWildcard, useWildcardEffect, useRallele));
    return rcpp_result_gen;
END_RCPP
}
// compare_threaded
Rcpp::List compare_threaded(const Rcpp::StringVector& DB, int numLoci, int bigHit, bool trace, int single, bool useWildcard, bool useWildcardEffect, bool useRallele);
RcppExport SEXP _DNAtools_compare_threaded(SEXP DBSEXP, SEXP numLociSEXP, SEXP bigHitSEXP, SEXP traceSEXP, SEXP singleSEXP, SEXP useWildcardSEXP, SEXP useWildcardEffectSEXP, SEXP useRalleleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::StringVector& >::type DB(DBSEXP);
    Rcpp::traits::input_parameter< int >::type numLoci(numLociSEXP);
    Rcpp::traits::input_parameter< int >::type bigHit(bigHitSEXP);
    Rcpp::traits::input_parameter< bool >::type trace(traceSEXP);
    Rcpp::traits::input_parameter< int >::type single(singleSEXP);
    Rcpp::traits::input_parameter< bool >::type useWildcard(useWildcardSEXP);
    Rcpp::traits::input_parameter< bool >::type useWildcardEffect(useWildcardEffectSEXP);
    Rcpp::traits::input_parameter< bool >::type useRallele(useRalleleSEXP);
    rcpp_result_gen = Rcpp::wrap(compare_threaded(DB, numLoci, bigHit, trace, single, useWildcard, useWildcardEffect, useRallele));
    return rcpp_result_gen;
END_RCPP
}
// convolve
NumericVector convolve(NumericMatrix x);
RcppExport SEXP _DNAtools_convolve(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(convolve(x));
    return rcpp_result_gen;
END_RCPP
}
// Pnm_locus
NumericVector Pnm_locus(int m, double theta, NumericVector alleleProbs);
RcppExport SEXP _DNAtools_Pnm_locus(SEXP mSEXP, SEXP thetaSEXP, SEXP alleleProbsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    Rcpp::traits::input_parameter< double >::type theta(thetaSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type alleleProbs(alleleProbsSEXP);
    rcpp_result_gen = Rcpp::wrap(Pnm_locus(m, theta, alleleProbs));
    return rcpp_result_gen;
END_RCPP
}
// Pnm_all_cpp
NumericMatrix Pnm_all_cpp(int numContrib, double theta, List loci);
RcppExport SEXP _DNAtools_Pnm_all_cpp(SEXP numContribSEXP, SEXP thetaSEXP, SEXP lociSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type numContrib(numContribSEXP);
    Rcpp::traits::input_parameter< double >::type theta(thetaSEXP);
    Rcpp::traits::input_parameter< List >::type loci(lociSEXP);
    rcpp_result_gen = Rcpp::wrap(Pnm_all_cpp(numContrib, theta, loci));
    return rcpp_result_gen;
END_RCPP
}
// generateCompositions
List generateCompositions(int numContributors);
RcppExport SEXP _DNAtools_generateCompositions(SEXP numContributorsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type numContributors(numContributorsSEXP);
    rcpp_result_gen = Rcpp::wrap(generateCompositions(numContributors));
    return rcpp_result_gen;
END_RCPP
}
// Prob
NumericVector Prob(CharacterVector vstrCombs, NumericVector q, NumericVector R, double r, double t);
RcppExport SEXP _DNAtools_Prob(SEXP vstrCombsSEXP, SEXP qSEXP, SEXP RSEXP, SEXP rSEXP, SEXP tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type vstrCombs(vstrCombsSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type q(qSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type R(RSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    Rcpp::traits::input_parameter< double >::type t(tSEXP);
    rcpp_result_gen = Rcpp::wrap(Prob(vstrCombs, q, R, r, t));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_DNAtools_score_rcpp", (DL_FUNC) &_DNAtools_score_rcpp, 5},
    {"_DNAtools_compare", (DL_FUNC) &_DNAtools_compare, 8},
    {"_DNAtools_compare_threaded", (DL_FUNC) &_DNAtools_compare_threaded, 8},
    {"_DNAtools_convolve", (DL_FUNC) &_DNAtools_convolve, 1},
    {"_DNAtools_Pnm_locus", (DL_FUNC) &_DNAtools_Pnm_locus, 3},
    {"_DNAtools_Pnm_all_cpp", (DL_FUNC) &_DNAtools_Pnm_all_cpp, 3},
    {"_DNAtools_generateCompositions", (DL_FUNC) &_DNAtools_generateCompositions, 1},
    {"_DNAtools_Prob", (DL_FUNC) &_DNAtools_Prob, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_DNAtools(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
