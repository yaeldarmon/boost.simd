//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <simd_test.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;
  using iT = bd::as_integer_t<T>;
  using i_t = bs::pack<iT, N>;

  T a1[N], m[N];
  iT e[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     m[i] = bs::frexp(a1[i], e[i]);
   }
  p_t aa1(&a1[0], &a1[N]);
  i_t ee1;
  p_t mm(&m[0], &m[N]);
  i_t ee(&e[0], &e[N]);
  STF_IEEE_EQUAL(bs::frexp(aa1, ee1), mm);
  STF_IEEE_EQUAL(ee1, ee);
}

STF_CASE_TPL("Check frexp on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
