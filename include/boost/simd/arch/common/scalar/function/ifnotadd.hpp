//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IFNOTADD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IFNOTADD_HPP_INCLUDED

#include <boost/simd/function/scalar/is_nez.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_OVERLOAD ( ifnotadd_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::scalar_< bd::fundamental_<A1> >
                          , bd::scalar_< bd::fundamental_<A1> >
                          )
  {
    BOOST_FORCEINLINE A1 operator() (const A0 & a0,const A1 & a1,const A1 & a2) const BOOST_NOEXCEPT
    {
      return is_nez(a0) ?  a1 :(a1+a2);
    }
  };
} } }


#endif
