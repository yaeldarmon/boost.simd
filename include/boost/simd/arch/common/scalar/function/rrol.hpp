//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_RROL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_RROL_HPP_INCLUDED

#include <boost/simd/function/scalar/rol.hpp>
#include <boost/simd/function/scalar/ror.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( rrol_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          , bd::scalar_< bd::int_<A1> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A1 a1) const BOOST_NOEXCEPT
    {
      return (a1 > 0)? rol(a0, a1) : ror(a0, -a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( rrol_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          , bd::scalar_< bd::uint_<A1> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A1 a1) const BOOST_NOEXCEPT
    {
      return  rol(a0, a1);
    }
  };
} } }


#endif
