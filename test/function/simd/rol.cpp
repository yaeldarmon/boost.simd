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
#include <boost/simd/function/rol.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], b[N], c[N], d[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     b[i] = bs::rol(a1[i], 1);
     c[i] = bs::rol(a1[i], N/2);
     d[i] = bs::rol(a1[i], N-1);
   }
  p_t aa1(&a1[0], &a1[N]);
  p_t bb(&b[0], &b[N]);
  p_t cc(&c[0], &c[N]);
  p_t dd(&d[0], &d[N]);
  STF_IEEE_EQUAL(bs::rol(aa1, 1), bb);
  STF_IEEE_EQUAL(bs::rol(aa1, N/2), cc);
  STF_IEEE_EQUAL(bs::rol(aa1, N-1), dd);
}

STF_CASE_TPL("Check rol on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
//  test<T, N/2>($);
//  test<T, Nx2>($);
}
