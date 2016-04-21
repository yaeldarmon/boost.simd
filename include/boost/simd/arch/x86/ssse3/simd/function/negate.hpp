
//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_NEGATE_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#define BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_NEGATE_HPP_INCLUDED

#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/simd/genmask.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( negate_
                          , (typename A0)
                          , bs::ssse3_
                          , bs::pack_<bd::int32_<A0>, bs::sse_>
                          , bs::pack_<bd::int32_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      return _mm_sign_epi32(a0, a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( negate_
                          , (typename A0)
                          , bs::ssse3_
                          , bs::pack_<bd::int8_<A0>, bs::sse_>
                          , bs::pack_<bd::int8_<A0>, bs::sse_>
                        )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      return _mm_sign_epi8(a0, a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( negate_
                          , (typename A0)
                          , bs::ssse3_
                          , bs::pack_<bd::int16_<A0>, bs::sse_>
                          , bs::pack_<bd::int16_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT
    {
      return _mm_sign_epi16(a0, a1);
    }
  };

} } }

#endif
