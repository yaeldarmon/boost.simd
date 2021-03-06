//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SELDEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SELDEC_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/selsub.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(seldec_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bs::logical_<A0>, X>
                          , bs::pack_<bd::integer_<A1>, X>
                          )
   {
      BOOST_FORCEINLINE A1 operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
      {
        return a1 + bitwise_cast<A1>(genmask(a0));
      }
   };

   BOOST_DISPATCH_OVERLOAD(seldec_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          , bs::pack_<bd::arithmetic_<A1>, X>
                          )
   {
      BOOST_FORCEINLINE A1 operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
      {
        return selsub(a0, a1, One<A1>());
      }
   };

} } }
#endif

