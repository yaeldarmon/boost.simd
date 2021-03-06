//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/selsub.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" selsub real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::selsub;
  using bs::logical;
  using r_t = decltype(selsub(logical<T>(),T(),T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(selsub(logical<T>(T(0)),T(1),T(2)), T(1));
  STF_EQUAL(selsub(logical<T>(bs::Nan<T>()),T(1),T(2)), T(-1));
  STF_IEEE_EQUAL(selsub(logical<T>(bs::Nan<T>()),bs::Inf<T>(),bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(selsub(logical<T>(bs::Nan<T>()),bs::Minf<T>(),bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(selsub(logical<T>(bs::Nan<T>()),bs::Nan<T>(),bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(selsub(logical<T>(bs::Nan<T>()),bs::Zero<T>(),bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" selsub signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::selsub;
  using bs::logical;
  using r_t = decltype(selsub(logical<T>(),T(),T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );


  STF_EQUAL(selsub(logical<T>(T(-1)),T(4),T(2)), T(2));
  STF_EQUAL(selsub(logical<T>(T(0)),T(4),T(2)), T(4));
  STF_EQUAL(selsub(logical<T>(bs::Zero<T>()), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_

STF_CASE_TPL (" selsub unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::selsub;
  using bs::logical;
  using r_t = decltype(selsub(logical<T>(),T(),T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(selsub(logical<T>(T(-1)),T(4),T(2)), T(2));
  STF_EQUAL(selsub(logical<T>(T(0)),T(4),T(2)), T(4));
  STF_EQUAL(selsub(logical<T>(bs::Zero<T>()), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_


