//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/cot.hpp>
#include <boost/simd/function/fast.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_4.hpp>

STF_CASE_TPL (" cot",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cot;

  using r_t = decltype(cot(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cot(-bs::Zero<T>()), -bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(cot(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cot(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cot(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(cot(bs::Zero<T>()), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cot(-bs::Pio_2<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cot(-bs::Pio_4<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cot(bs::Pio_2<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cot(bs::Pio_4<T>()), bs::One<r_t>(), 0.5);
}

STF_CASE_TPL (" cot fast_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cot;

  using r_t = decltype(cot(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::fast_(cot)(-bs::Zero<T>()), -bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::fast_(cot)(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::fast_(cot)(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::fast_(cot)(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::fast_(cot)(bs::Zero<T>()), bs::Inf<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(bs::fast_(cot)(-bs::Pio_2<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::fast_(cot)(-bs::Pio_4<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::fast_(cot)(bs::Pio_2<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(bs::fast_(cot)(bs::Pio_4<T>()), bs::One<r_t>(), 0.5);
}
