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
#include <boost/simd/function/two_prod.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;


  T a1[N], a2[N], r1[N], r2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = (i%2) ? T(i+N) :T(-(i+N));
     r1[i] = bs::two_prod(a1[i], a2[i], r2[i]);
   }
  p_t aa1(&a1[0], &a1[N]);
  p_t aa2(&a2[0], &a2[N]);
  p_t rr21;
  p_t rr1(&r1[0], &r1[N]);
  p_t rr2(&r2[0], &r2[N]);
  STF_IEEE_EQUAL(bs::two_prod(aa1, aa2, rr21), rr1);
  STF_IEEE_EQUAL(rr21, rr2);
}

STF_CASE_TPL("Check two_prod on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
//  test<T, N/2>($);
//  test<T, Nx2>($);
}
