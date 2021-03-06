//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IFNOTADD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IFNOTADD_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/if_zero_else.hpp>
#include <boost/simd/function/simd/plus.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(ifnotadd_
                             , (typename A0, typename A1, typename X)
                             , bd::cpu_
                             , bs::pack_<bd::fundamental_<A0>, X>
                             , bs::pack_<bd::fundamental_<A1>, X>
                             , bs::pack_<bd::fundamental_<A1>, X>
                             )
   {
      BOOST_FORCEINLINE A0
      operator()(A0 const& a0, A1 const& a1, A1 const& a2
               , typename std::enable_if<
                bs::cardinal_of<A0>::value == bs::cardinal_of<A1>::value
                >::type* = 0
       ) const BOOST_NOEXCEPT
       {
         return a1+if_zero_else(a0, a2);
       }
   };

} } }

#endif

