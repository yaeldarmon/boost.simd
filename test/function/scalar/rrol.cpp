//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/rrol.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" rroli",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::rrol;

  using r_t = decltype(rrol(T(),std::int32_t()));
  typedef T wished_r_t;


  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(rrol(bs::Mone<T>(),T(1)), bs::Mone<r_t>());
  STF_EQUAL(rrol(bs::Mone<T>(),T(5)), bs::Mone<r_t>());
  STF_EQUAL(rrol(bs::Two<T>(),-1),  bs::One<T>());
  STF_EQUAL(rrol(bs::Two<T>(),1), bs::Four<r_t>());
  STF_EQUAL(rrol(bs::One<T>(),1), bs::Two<r_t>());
  STF_EQUAL(rrol(bs::Four<T>(),-1), bs::Two<r_t>());
  STF_EQUAL(rrol(bs::One<T>(), 2), bs::Four<r_t>());
  STF_EQUAL(rrol(bs::Four<T>(),-2), bs::One<r_t>());
  STF_EQUAL(rrol(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_


