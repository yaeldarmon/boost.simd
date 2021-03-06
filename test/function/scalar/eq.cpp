//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/eq.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" eq integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::eq;
  using r_t = decltype(eq(T(), T()));

   // return type conformity test
  STF_TYPE_IS(r_t,bs::logical<T>);

  // specific values tests
  STF_EQUAL(eq(bs::One<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(eq(bs::One<T>(),bs::Zero<T>()), r_t(false));
  STF_EQUAL(eq(bs::Zero<T>(), bs::Zero<T>()), r_t(true));
} // end of test for integer_

STF_CASE_TPL (" eq real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::eq;
  using r_t = decltype(eq(T(), T()));

   // return type conformity test
  STF_TYPE_IS(r_t,bs::logical<T>);

  // specific values tests
  STF_EQUAL(eq(bs::Inf<T>(), bs::Inf<T>()), r_t(true));
  STF_EQUAL(eq(bs::Minf<T>(), bs::Minf<T>()), r_t(true));
  STF_EQUAL(eq(bs::Nan<T>(), bs::Nan<T>()), r_t(false));
  STF_EQUAL(eq(bs::One<T>(),bs::Zero<T>()), r_t(false));
  STF_EQUAL(eq(bs::Zero<T>(), bs::Zero<T>()), r_t(true));
} // end of test for floating_

STF_CASE_TPL (" eq logical",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::eq;
  using r_t = decltype(eq(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  STF_EQUAL(eq(bs::True< bs::logical<T> >(), bs::True< bs::logical<T> >()), r_t(true));
  STF_EQUAL(eq(bs::False< bs::logical<T> >(), bs::False< bs::logical<T> >()), r_t(true));
  STF_EQUAL(eq(bs::True< bs::logical<T> >(), bs::False< bs::logical<T> >()), r_t(false));
  STF_EQUAL(eq(bs::False< bs::logical<T> >(), bs::True< bs::logical<T> >()), r_t(false));
}

STF_CASE ( "eq bool")
{
  namespace bs = boost::simd;
  using bs::eq;

  // return type conformity test
  STF_EXPR_IS(eq(bool(), bool()), bool);

  // specific values tests
  STF_EQUAL(eq(true, false), false);
  STF_EQUAL(eq(false, true), false);
  STF_EQUAL(eq(true, true), true);
  STF_EQUAL(eq(false, false), true);
}




