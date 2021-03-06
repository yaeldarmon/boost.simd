//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/is_ord.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/quarter.hpp>

STF_CASE_TPL (" is_ord real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ord;
  using r_t = decltype(is_ord(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(is_ord(bs::Inf<T>(), bs::Inf<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Minf<T>(), bs::Minf<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Nan<T>(), bs::Nan<T>()), r_t(false));
#endif
  STF_EQUAL(is_ord(-bs::Zero<T>(), -bs::Zero<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Half<T>(), bs::Half<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Mone<T>(), bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::One<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Quarter<T>(), bs::Quarter<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Two<T>(), bs::Two<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Zero<T>(), bs::Zero<T>()), r_t(true));
}

STF_CASE_TPL (" is_ord signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ord;
  using r_t = decltype(is_ord(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_ord(bs::Mone<T>(), bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::One<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Two<T>(), bs::Two<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Zero<T>(), bs::Zero<T>()), r_t(true));
}

STF_CASE_TPL (" is_ord unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ord;
  using r_t = decltype(is_ord(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_ord(bs::One<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Two<T>(), bs::Two<T>()), r_t(true));
  STF_EQUAL(is_ord(bs::Zero<T>(), bs::Zero<T>()), r_t(true));
}

STF_CASE ( "is_ord bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_ord;
  using r_t = decltype(is_ord(bool(), bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);

  // specific values tests
  STF_EQUAL(is_ord(true, false), true);
  STF_EQUAL(is_ord(false, true), true);
  STF_EQUAL(is_ord(true, true), true);
  STF_EQUAL(is_ord(false, false), true);
}
