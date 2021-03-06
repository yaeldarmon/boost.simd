//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/idiv.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/ceil.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

STF_CASE_TPL( "Check idiv behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idiv;
  using r_t = decltype(idiv(T(), T()));
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

#ifndef STF_NO_INVALIDS
  STF_EQUAL(idiv(bs::Inf<T>(),  bs::Inf<T>()), bs::Nan<r_t>());
  STF_EQUAL(idiv(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
  STF_EQUAL(idiv(bs::Nan<T>(),  bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(idiv(bs::One<T>(),bs::Zero<T>()), bs::Inf<r_t>());
  STF_EQUAL(idiv(bs::Zero<T>(), bs::Zero<T>()), bs::Nan<r_t>());
  STF_EQUAL(idiv(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
}



STF_CASE_TPL( "Check idiv behavior with options", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idiv;
  using r_t = decltype(idiv(T(), T()));
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  STF_EQUAL(idiv(bs::One<T>(), bs::Two<T>()), bs::Zero<r_t>());

  STF_EQUAL(idiv(bs::One<T>(), bs::Two<T>(), bs::ceil), bs::One<r_t>());
  STF_EQUAL(idiv(bs::One<T>(), bs::Two<T>(), bs::floor), bs::Zero<r_t>());
  STF_EQUAL(idiv(bs::One<T>(), bs::Two<T>(), bs::round), bs::One<r_t>());
  STF_EQUAL(idiv(bs::One<T>(), bs::Two<T>(), bs::round2even), bs::Zero<r_t>());
  STF_EQUAL(idiv(bs::One<T>(), bs::Two<T>(), bs::fix), bs::Zero<r_t>());
}
