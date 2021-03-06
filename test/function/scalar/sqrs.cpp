//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sqrs.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" sqrs real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrs;
  using r_t = decltype(sqrs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(sqrs(bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(sqrs(bs::Minf<T>()), bs::Inf<T>());
  STF_IEEE_EQUAL(sqrs(bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(sqrs(bs::One<T>()), bs::One<T>());
  STF_EQUAL(sqrs(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(sqrs(bs::Valmax<T>()), bs::Inf<T>());
  STF_EQUAL(sqrs(bs::Valmin<T>()), bs::Inf<T>());
  STF_EQUAL(sqrs(bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(sqrs(T(1)), T(1));
} // end of test for floating_

STF_CASE_TPL (" sqrs unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrs;
  using r_t = decltype(sqrs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sqrs(bs::One<T>()), bs::One<T>());
  STF_EQUAL(sqrs(bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(sqrs(bs::Valmin<T>()), bs::Valmin<T>());
  STF_EQUAL(sqrs(bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" sqrs signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sqrs;
  using r_t = decltype(sqrs(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sqrs(bs::Mone<T>()), bs::One<T>());
  STF_EQUAL(sqrs(bs::One<T>()), bs::One<T>());
  STF_EQUAL(sqrs(bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(sqrs(bs::Valmin<T>()), bs::Valmax<T>());
  STF_EQUAL(sqrs(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_
