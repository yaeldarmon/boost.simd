//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CORRECT_FMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CORRECT_FMA_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <boost/simd/function/scalar/exponent.hpp>
#include <boost/simd/function/scalar/ldexp.hpp>
#include <boost/simd/function/scalar/max.hpp>
#include <boost/simd/function/scalar/multiplies.hpp>
#include <boost/simd/function/scalar/sign.hpp>
#include <boost/simd/function/scalar/two_add.hpp>
#include <boost/simd/function/scalar/two_prod.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( correct_fma_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::single_<A0> >
                          , bd::scalar_< bd::single_<A0> >
                          , bd::scalar_< bd::single_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1, A0 a2) const BOOST_NOEXCEPT
    {
      return static_cast<A0>( static_cast<double>(a0)*static_cast<double>(a1)
                              + static_cast<double>(a2)
                            );
    }
  };


  BOOST_DISPATCH_OVERLOAD ( correct_fma_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1, A0 a2) const BOOST_NOEXCEPT
    {
      A0 p, rp, s, rs;
    #ifndef BOOST_SIMD_DONT_CARE_FMA_OVERFLOW
      using iA0 = bd::as_integer_t<A0>;
      iA0 e0 = exponent(a0);
      iA0 e1 = exponent(a1);
      iA0 e = -bs::max(e0, e1)/2;
      A0 ae2  = ldexp(a2, e);
      auto choose = (e0 > e1);
      A0 amax = choose ? ldexp(a0, e) : ldexp(a1, e);
      A0 amin = choose ? a1 : a0;
      two_prod(amax, amin, p, rp);
      two_add(p, ae2, s, rs);
      return ldexp(s+(rp+rs), -e);
    #else
      two_prod(a0, a1, p, rp);
      two_add(p, a2, s, rs);
      return s+(rp+rs);
    #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( correct_fma_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::int_<A0> >
                          , bd::scalar_< bd::int_<A0> >
                          , bd::scalar_< bd::int_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1, A0 a2) const BOOST_NOEXCEPT
    {
      // correct fma has to ensure "no intermediate overflow".
      // This is done in the case of signed integers by transtyping to unsigned type
      // to perform the computations in a guaranted 2-complement environment
      // since signed integer overflows in C++ produce "undefined results"
      using u_t = bd::as_integer_t<A0, unsigned>;
      return A0(correct_fma(u_t(a0), u_t(a1), u_t(a2)));
    }
  };


  BOOST_DISPATCH_OVERLOAD ( correct_fma_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::uint_<A0> >
                          , bd::scalar_< bd::uint_<A0> >
                          , bd::scalar_< bd::uint_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1, A0 a2) const BOOST_NOEXCEPT
    {
      return multiplies(a0, a1)+a2;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( correct_fma_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          , boost::simd::std_tag
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1, A0 a2, std_tag const&) const BOOST_NOEXCEPT
    {
      return std::fma(a0, a1, a2);
    }
  };
} } }


#endif
