//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/is_finite.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;
  using pl_t = bs::pack<bs::logical<T>, N>;

  T a1[N];
  bs::logical<T> b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : bs::Inf<T>();
    b[i] = bs::is_finite(a1[i]);
   }
  p_t aa1(&a1[0], &a1[N]);
  pl_t bb(&b[0], &b[N]);
  STF_IEEE_EQUAL(bs::is_finite(aa1), bb);
}

STF_CASE_TPL("Check is_finite on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
