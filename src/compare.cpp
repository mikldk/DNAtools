/*########################################################################*/
/* File: compare.cpp                                                     */
/* Authors: James M. Curran, Torben Tvedebrink, and                       */
/*          Mikkel M. Andersen                                            */
/*                                                                        */
/* Version history                                                        */
/* ---------------------------------------------------------------------  */
/* Version  Date        Changes                          Author           */
/* -------  ----------  --------------------------       ---------------- */
/* 1.0      2013-10-22  Added first version number       JMC              */
/* 1.0      2013-10-23  Moved Profile to diff file       JMC              */
/* 1.0-1    2013-10-28  Changed UNPRoTECT count in       JMC              */
/*                      prepReturnList as was                             */
/*                      causing seg faults                                */
/* 1.0-1    2013-10-28  Changed UNPRoTECT count in       JMC              */
/*                      prepReturnList as was                             */
/*                      causing seg faults                                */ 
/* 1.0-2    2013-10-29  Changed UNPRoTECT back in        JMC              */
/*                      prepReturnList, added                             */
/*                      UNPROTECT(1) in compare                           */ 
/* 1.0-3    2013-11-01  Calls to profile->compare        JMC              */
/*                      had rare and wildcard switces                     */
/*                      reversed.                                         */ 
/* 1.0-4    2013-11-04  Added some error checking       JMC               */
/*                      to prepReturnList                                 */
/* 1.0-5    2013-11-05  Changed compare                 JMC               */
/*                      arg lists and code                                */
/*                      to match so we don't guess that                   */
/*                      the input is correct                              */
/* 1.0-5    2013-11-05  Added trace code to             JMC               */
/*                      compare, mcompare to help                         */
/*                      debugging                                         */
/* 1.0-6    2018-03-22  Prototypes in header file.       MMA              */
/*                      Small adjustments.                                */




#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

#undef length // remove due to Rcpp update?
 
// move up due to Rcpp update?
// JMC: removed Profile class declaration and implementation to separate files for maintainability

// JMC: header for interrupts
//#include <R_ext/Utils.h>

// load last (Rcpp update)?
#include <Rcpp.h>

// [[Rcpp::depends(RcppProgress)]]
#include <progress.hpp>

#include "profile.cpp"

vector<Profile *> readProfiles(const Rcpp::StringVector &DB, int nProfiles, int nLoci){
  int t = 0;
  string strLine;
  vector<Profile *> vpProfiles;
  Profile *pProfile;
  
  while(t < nProfiles){
    strLine = DB(t);
    pProfile = new Profile(strLine, nLoci);
    vpProfiles.push_back(pProfile);
    t++;
  }
  
  return vpProfiles;
}

Rcpp::List prepReturnList(Rcpp::IntegerVector &m, vector<int>& vnRow1, vector<int>& vnRow2, vector<int>& vnMatch, 
                          vector<int>& vnPartial, vector<int>& vnFmatch, vector<int>& vnFpartial){
  
 Rcpp::List rl;
  
  //    Rprintf("vnRow1 %d\n",vnRow1.size());
  //    Rprintf("vnRow2 %d\n",vnRow2.size());
  //    Rprintf("vnMatch %d\n",vnMatch.size());
  //    Rprintf("vnPartial %d\n",vnPartial.size()); 
  //    Rprintf("vnFMatch %d\n",vnFmatch.size());
  //    Rprintf("vnFpartial %d\n",vnFpartial.size());
  
  int pnSizes[6];
  pnSizes[0] = (int)vnRow1.size();
  pnSizes[1] = (int)vnRow2.size();
  pnSizes[2] = (int)vnMatch.size();
  pnSizes[3] = (int)vnPartial.size();
  pnSizes[4] = (int)vnFmatch.size();
  pnSizes[5] = (int)vnFpartial.size();
  
  sort(pnSizes, pnSizes + 6);
  
  if(pnSizes[0] != pnSizes[5]){
    Rprintf("Warning: different result vector sizes in prepReturnList. This will cause problems\n");
    
    pnSizes[0] = (int)vnRow1.size();
    pnSizes[1] = (int)vnRow2.size();
    pnSizes[2] = (int)vnMatch.size();
    pnSizes[3] = (int)vnPartial.size();
    pnSizes[4] = (int)vnFmatch.size();
    pnSizes[5] = (int)vnFpartial.size();
    
    const char *szNames[] = {"vnRow1", "vnRow2", "vnMatch", "vnPartial", "vnFmatch", "vnFpartial"};
    for(int i = 0; i < 6; i++){
      Rprintf("%s %d\n", (char *)szNames[i], pnSizes[i]);
    }
  }
  
  
  int nMatchlength = (int)vnRow1.size();
  
  Rcpp::IntegerVector row1(vnRow1.size());
  Rcpp::IntegerVector row2(vnRow2.size());
  Rcpp::IntegerVector matches(vnMatch.size());
  Rcpp::IntegerVector partial(vnPartial.size());
  Rcpp::IntegerVector fmatches(vnFmatch.size());
  Rcpp::IntegerVector fpartial(vnFpartial.size());
  
  for(int i = 0; i < nMatchlength; i++){
    row1[i] = vnRow1[i]; 
    row2[i] = vnRow2[i]; 
    matches[i] = vnMatch[i]; 
    partial[i] = vnPartial[i]; 
    fmatches[i] = vnFmatch[i]; 
    fpartial[i] = vnFpartial[i]; 
  }
  
  rl["M"] = m;
  rl["row1"] = row1;
  rl["row2"] = row2;
  rl["matches"] = matches;
  rl["partial"] = partial;
  rl["fmatches"] = fmatches;
  rl["fpartial"] = fpartial;
  
  return rl;
}


// [[Rcpp::export]]
Rcpp::List compare(const Rcpp::StringVector& DB, int numLoci, int bigHit, bool trace, int single,
                   bool useWildcard, bool useWildcardEffect, bool useRallele) {  
  if(trace){
    Rprintf("numLoci: %d\n", numLoci);
    Rprintf("bigHit: %d\n", bigHit);
    Rprintf("single: %d\n", single);
    Rprintf("useWildcard: %c\n", useWildcard ? 'T' : 'F');
    Rprintf("useWildcardEffect: %c\n", useWildcardEffect ? 'T' : 'F');
    Rprintf("useRallele: %c\n", useRallele ? 'T' : 'F');
  }
  
  vector<Profile*> vpProfiles;
  int nProfiles = DB.size();
  
  string strLine;
  string strID, strA1, strA2;
  
  int iProfiles = nProfiles;
  long unsigned comps = nProfiles*(nProfiles-1)/2;
  
  if (single > 0){ 
    iProfiles = single; // i only runs through 0...iProfiles-1
    comps = nProfiles * iProfiles; 
  }
  
  long unsigned stepper = 0;
  //long unsigned r = 0;
  
  Progress progress(comps, trace);
  

  // CONSTRUCT THE PROFILES VECTOR BY READING IN DATA FROM DB
  vpProfiles = readProfiles(DB, nProfiles, numLoci);
  
  unsigned long i, j;
  unsigned long m0, m1, m2, fm1, fm2;
  
  unsigned long nNumRows = useWildcardEffect ? 2 * numLoci + 1 : numLoci + 1;
  unsigned long m_size = nNumRows * nNumRows;
  
  Rcpp::IntegerVector m(m_size, 0);
//  PROTECT(m = allocVector(INTSXP, m_size));
/*  for(i = 0; i < m_size; i++){
    INTEGER(m)[i] = 0; 
  }*/
  
  vector<int> row1;
  vector<int> row2;
  vector<int> match;
  vector<int> partial;
  vector<int> fmatch;
  vector<int> fpartial;
  
  int ii;
  
  Profile *pProf1, *pProf2;
  
  // NEW!
  // the casts to unsigned long are mine (James) - I doubt it makes any difference
  for(i = 0; i < (unsigned long)iProfiles; i++){
    pProf1 = vpProfiles[i];
    if(single > 0){
      ii = single; 
    }
    else{
      ii = i+1;
    }
    
    
    for(j = ii; j < (unsigned long)nProfiles; j++){ // NEW! ends
    
    pProf2 = vpProfiles[j];
    
    m2 = 0;
    m1 = 0;
    fm2 = 0;
    fm1 = 0;
    
    pProf1->compare(pProf2, m2, m1, m0, fm2, fm1, useWildcardEffect, useRallele); // v1.0-3 Wildcard and Rare were reversed
    
    progress.increment();
    
    if(nProfiles >= 15 && trace){  // 15*14/2 = 105 > 100 whereas 14*13/2 = 91 < 100
      if (stepper > comps/100){ 
        if (Progress::check_abort()){
          Rcpp::stop("Aborted"); // FIXME: Return intermediate result?
        }
        stepper = 0;
      }
      stepper++;
    }
    
    //      m(m2,m1)++;
    if(useWildcardEffect){
      m[(m2 * 2 + m1) * (2 * numLoci + 1) + ( fm2 * 2 + fm1)]++;
    }
    else{
      m[(m2 + fm2) * (numLoci + 1)+( fm1 + m1)]++;
      /*
      if (m[2] > 7099) {      
        Rcpp::Rcout << "i = " << i << "; j = " << j << "; m[2] = " << m[2] << std::endl; 
        //Rcpp::print();
        //Rcpp::Rcout << m[2] << std::endl;
      }
      */
      
      if((m2 + fm2) >= (long unsigned)bigHit){
        // 	prof1.push_back(pProf1->m_strName);
        // 	prof2.push_back(pProf2->m_strName);
        row1.push_back(i + 1);
        row2.push_back(j + 1);
        match.push_back(m2);
        partial.push_back(m1);
        fmatch.push_back(fm2);
        fpartial.push_back(fm1);
      }
    }
    
    } // end for(j)
  } // end for(i)
  
  //  for(i=0;i<(numLoci+1)*(numLoci+2)/2;i++) Rprintf("%d ",INTEGER(m)[i]);
  
  Rcpp::List rl = prepReturnList(m, row1, row2, match, partial, fmatch, fpartial);  
  
  return rl;
  
}

//' @export
// [[Rcpp::export]]
Rcpp::IntegerVector score_rcpp(const Rcpp::IntegerVector& prof1, 
                               const Rcpp::IntegerVector& prof2, 
                               int numLoci, 
                               bool useWildCard, 
                               bool useRareAllele){
  
  int *pnProf1 = &(Rcpp::as<std::vector<int> >(prof1)[0]); // this should replace INTEGER(prof1)
  int *pnProf2 = &(Rcpp::as<std::vector<int> >(prof2)[0]);
  
  int nLoci = numLoci;
  bool bWildCard = useWildCard;
  bool bRareAllele = useRareAllele;
  
  Profile *pProf1 = new Profile(pnProf1, nLoci);
  Profile *pProf2 = new Profile(pnProf2, nLoci);
  
  //Rprintf("Profile 1:\n%s\nProfile 2:\n%s\n", pProf1->toString().c_str(), pProf2->toString(true).c_str());
  
  vector<int> vnScore(nLoci);
  unsigned long m2, m1, m0, fm2, fm1;
  m2 = m1 = m0 = fm2  = fm1 = 0;
  
  pProf1->compare(pProf2, m2, m1, m0, fm2, fm1, bWildCard, bRareAllele, &vnScore);
  delete pProf1;
  delete pProf2;
  
  Rcpp::IntegerVector result;
  vector<int>::iterator i = vnScore.begin();
  while(i!=vnScore.end()){
    result.push_back(*i);
    i++;
  }
  return result;
}


