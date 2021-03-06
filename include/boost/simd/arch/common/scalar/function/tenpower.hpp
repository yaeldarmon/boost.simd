//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TENPOWER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TENPOWER_HPP_INCLUDED

#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/scalar/is_ltz.hpp>
#include <boost/simd/function/scalar/is_odd.hpp>
#include <boost/simd/function/scalar/rec.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/config.hpp>
#include <boost/mpl/if.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( tenpower_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::int_<A0> >
                          )
  {
    using result_t = bd::as_floating_t<A0>;
    BOOST_FORCEINLINE result_t operator() ( A0 exp) const BOOST_NOEXCEPT
    {

      result_t result = One<result_t>();
      result_t base = Ten<result_t>();
      auto neg = is_ltz(exp);
      exp =  boost::simd::abs(exp);
      while(exp)
      {
        if (is_odd(exp)) result *= base;
        exp >>= 1;
        base = sqr(base);
      }
      return neg ? rec(result) : result;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( tenpower_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::uint_<A0> >
                          )
  {
    using result_t = bd::as_floating_t<A0>;
    BOOST_FORCEINLINE result_t operator() ( A0 exp) const BOOST_NOEXCEPT
    {
      result_t result = One<result_t>();
      result_t base = Ten<result_t>();
      while(exp)
      {
        if (is_odd(exp)) result *= base;
        exp >>= 1;
        base = sqr(base);
      }
      return result;
    }
  };
} } }


#endif
