//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NOT_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NOT_EQUAL_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/meta/is_bitwise_logical.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/meta/as_arithmetic.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD_IF(is_not_equal_
                             , (typename A0,typename X)
                             , (bs::is_bitwise_logical_t<A0>)
                             , bs::simd_
                             , bs::pack_<bs::logical_<A0>,X>
                             , bs::pack_<bs::logical_<A0>,X>
                             )
   {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1
                                   ) const BOOST_NOEXCEPT
    {
      using cast_t = bd::as_integer_t<bs::as_arithmetic_t<A0>>;
      return bitwise_cast<A0>(is_not_equal(bitwise_cast<cast_t>(a0)
                                          , bitwise_cast<cast_t>(a1)
                                          )
                             );
    }
  };
} } }

#endif

