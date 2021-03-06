//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_LOG2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_LOG2_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/arch/common/detail/scalar/logarithm.hpp>
#include <boost/simd/function/scalar/frexp.hpp>
#include <boost/simd/function/scalar/ilog2.hpp>
#include <boost/simd/meta/is_not_scalar.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( log2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 const& a0) const BOOST_NOEXCEPT
    {
      return detail::logarithm<A0,is_not_scalar_t<A0>>::log2(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( log2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 const& a0) const BOOST_NOEXCEPT
    {
      return bs::ilog2(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( log2_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::integer_<A1> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A1& a1) const BOOST_NOEXCEPT
    {
      return bs::frexp(a0, a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( log2_
                          , (typename A0, typename A1, typename A2)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A1> >
                          , bd::scalar_< bd::integer_<A2> >
                          )
  {
    BOOST_FORCEINLINE void operator() ( A0 const& a0, A1& a1, A2& a2) const
    {
      return bs::frexp(a0, a1, a2);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( log2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          , boost::simd::std_tag
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0
                                    , std_tag const& ) const BOOST_NOEXCEPT
    {
       return std::log2(a0);
    }
  };
} } }


#endif
