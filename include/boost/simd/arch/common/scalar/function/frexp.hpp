//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FREXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FREXP_HPP_INCLUDED
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/fast.hpp>

#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/constant/twotonmb.hpp>
#include <boost/simd/function/scalar/is_eqz.hpp>
#endif
#include <boost/simd/constant/limitexponent.hpp>
#include <boost/simd/constant/mask1frexp.hpp>
#include <boost/simd/constant/mask2frexp.hpp>
#include <boost/simd/constant/maxexponentm1.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/scalar/bitwise_and.hpp>
#include <boost/simd/function/scalar/bitwise_andnot.hpp>
#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <boost/simd/function/scalar/bitwise_or.hpp>
#include <boost/simd/function/scalar/is_invalid.hpp>
#include <boost/simd/function/scalar/shr.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
 BOOST_DISPATCH_OVERLOAD ( frexp_
                         , (typename A0, typename A1)
                         , bd::cpu_
                         , bd::scalar_< bd::floating_<A0> >
                         , bd::scalar_< bd::floating_<A0> >
                         , bd::scalar_< bd::integer_<A1>  >
                         )
 {
    BOOST_FORCEINLINE void operator() ( A0 a0,A0 & r0,A1& r1) const BOOST_NOEXCEPT
    {
      if (a0 == 0 || is_invalid(a0))
      {
        r0 = a0;
        r1 = Zero<A1>();
      }
      else
      {
        using i_t = bd::as_integer_t<A0, signed>;
        r1 = simd::bitwise_cast<i_t>(bitwise_and(Mask1frexp<A0>(), a0));  // extract exp.
#ifndef BOOST_SIMD_NO_DENORMALS
        A1 t = Zero<A1>();
        if(is_eqz(r1)) // denormal
        {
          a0 *= Twotonmb<A0>();
          r1 = simd::bitwise_cast<i_t>(bitwise_and(Mask1frexp<A0>(), a0));  // extract exp. again
          t = Nbmantissabits<A0>();
        }
#endif
        A0 x  = bitwise_andnot(a0, Mask1frexp<A0>());                    // clear exp. in a0
        r1 = shr(r1,Nbmantissabits<A0>())- Maxexponentm1<A0>();         // compute exp.
        if (r1 > Limitexponent<A0>())
        {
          r1   = 0;
          r0   = a0;
          return;
        }
        r0 = bitwise_or(x,Mask2frexp<A0>());                                   // insert exp.+1 in x
#ifndef BOOST_SIMD_NO_DENORMALS
        r1 -= t;
#endif
      }
    }
  };

 BOOST_DISPATCH_OVERLOAD ( frexp_
                         , (typename A0, typename A1)
                         , bd::cpu_
                         , bd::scalar_< bd::floating_<A0> >
                         , bd::scalar_< bd::floating_<A0> >
                         , bd::scalar_< bd::integer_<A1>  >
                         , boost::simd::fast_tag
                         )
 {
    BOOST_FORCEINLINE void operator() ( A0 a0,A0 & r0,A1& r1
                                      , fast_tag const&) const BOOST_NOEXCEPT
    {
      r1  = bitwise_cast<A1>(bitwise_and(Mask1frexp<A0>(), a0));
      A0  x = bitwise_andnot(a0, Mask1frexp<A0>());
      r1  = shr(r1,Nbmantissabits<A0>()) - Maxexponentm1<A0>();
      r0  = bitwise_or(x,Mask2frexp<A0>());
    }
  };

 BOOST_DISPATCH_OVERLOAD ( frexp_
                         , (typename A0, typename A1)
                         , bd::cpu_
                         , bd::scalar_< bd::floating_<A0> >
                         , bd::scalar_< bd::integer_<A1>  >
                         , boost::simd::std_tag
                         )
 {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A1& r1
                                      , std_tag const&) const BOOST_NOEXCEPT
    {
      int e = Zero<int>();
      A0 r = std::frexp(a0, &e);
      r1 = e;
      return r;
    }
  };

 BOOST_DISPATCH_OVERLOAD ( frexp_
                         , (typename A0, typename A1)
                         , bd::cpu_
                         , bd::scalar_< bd::floating_<A0> >
                         , bd::scalar_< bd::floating_<A0> >
                         , bd::scalar_< bd::integer_<A1>  >
                         , boost::simd::std_tag
                         )
 {
    BOOST_FORCEINLINE void operator() ( A0 a0, A0& r1, A1& r2
                                      , std_tag const&) const BOOST_NOEXCEPT
    {
      int e = Zero<int>();
      r1 = std::frexp(a0, &e);
      r2 = e;
    }
  };

 BOOST_DISPATCH_OVERLOAD ( frexp_
                         , (typename A0)
                         , bd::cpu_
                         , bd::scalar_< bd::floating_<A0> >
                         , boost::simd::std_tag
                         )
 {
   using i_t = bd::as_integer_t<A0, signed>;
   BOOST_FORCEINLINE std::pair < A0, i_t> operator() ( A0 a0
                                                     , std_tag const&) const BOOST_NOEXCEPT
    {
      int e = Zero<int>();
      A0 r1 = std::frexp(a0, &e);
      return {r1, i_t(e)};
    }
  };

} } }


#endif
