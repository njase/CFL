///////////
// Main Test module for fe_data.h
//////////
#define BOOST_TEST_MODULE TMOD_FEDATA_1_H
#define BOOST_TEST_DYN_LINK
#include "test_fe_data.h"
//////////

//// Test case FEDataCreation
// Type: Positive test case
// Coverage: following classes - FEData
// Checks for:
// 1. Template instantiation with several combinations of (degree,number of components,dim,index)
// 2. Object creation in each case, and basic state check for the object
template <int i>
struct FEDatafunctor
{
  static constexpr int degree[4] = { 1, 2, 3 };
  static constexpr int n_comp[4] = { 1, 1, 1 };
  static constexpr int dim[4] = { 1, 2, 3 };
  static constexpr unsigned int fe_no[4] = { fe_0, fe_1, fe_2 };
  static constexpr unsigned int max_degree = 4;

  static void
  run()
  {
    FE_Q<dim[i]> fe(degree[i]);

    FEData<FE_Q, degree[i], n_comp[i], dim[i], fe_no[i], max_degree> obj(fe);

    // Check basic state of object
    BOOST_TEST(obj.fe_number == fe_no[i]);
    BOOST_TEST(obj.max_degree == max_degree);
  }
};

BOOST_AUTO_TEST_CASE(FEDataCreation)
{
  // Check some combinations of object creation
  for_<0, 3>::run<FEDatafunctor>();
}
