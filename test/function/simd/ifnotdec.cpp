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
#include <boost/simd/function/ifnotdec.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], b[N];
  for(int i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(1) : T(0);
     a2[i] = (i%2) ? T(i+N) : T(-(i+N));
     b[i] = bs::ifnotdec(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[N]);
  p_t aa2(&a2[0], &a2[N]);
  p_t bb(&b[0], &b[N]);
  STF_IEEE_EQUAL(bs::ifnotdec(aa1, aa2), bb);
}

STF_CASE_TPL("Check ifnotdec on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
